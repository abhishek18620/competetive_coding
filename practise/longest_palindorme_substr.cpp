#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::pair <int, int> Solve(std::string& str) {
  int n = str.length();
  if(n == 0) {
    return {-1 , 0};
  }
  std::pair<int, int> sol = {0, 0};
  int max_substr_len = 1;
  std::vector<std::vector<bool> > is_palin(n+1, std::vector<bool> (n+1, false));
  //base cases
  for(int i = 0; i < n; i++) {
    is_palin[i][0] = true;
    is_palin[i][1] = true;
  }
  for(int middle = 0; middle < n-1; middle++) {
    for(int len = 2; len <= n; len++) {
      int i = middle - len/2 + !(len&1);
      int j = middle + len/2;
      //std::cout << i << "  " << j << std::endl;
      if(i < 0 || j > n) {
        break;
      }
      if(str[i] == str[j] && is_palin[middle][len-2]) {
        is_palin[middle][len] = true;
        if(max_substr_len < len) {
          max_substr_len = len;
          sol = {i, j};
        }
      }
    }
  }
  //for (int k = 3; k <= n; ++k) {
    //for (int i = 0; i < n - k + 1; ++i) {
    //  int j = i + k - 1;
    //  if (is_palin[i + 1][j - 1] && str[i] == str[j]) {
    //    is_palin[i][j] = true;

    //    if (k > max_substr_len) {
    //      max_substr_len = k;
    //      sol = {i, j};
    //    }
    //  }
    //}
  //}
  return sol;
}


int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str;
  std::cin >> str;
  if(str.length() > 0) {
  std::pair<int, int> sol = Solve(str);
  int sol_len = sol.second - sol.first + 1;
  std::string sol_str = str.substr(sol.first, sol_len);
  std::cout << sol_str << std::endl;
  }
  else {
    std::cout << "" << std::endl;
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::pair <int, int> Solve(std::string& str) {
  int n = str.length();
  std::pair<int, int> sol = {0, 0};
  int max_substr_len = 1;
  std::vector<std::vector<bool> > is_palin(n+1, std::vector<bool> (n+1, false));
  //base cases
  for(int i = 0; i < n; i++) {
    is_palin[i][i] = true;
  }
  for(int i = 0; i < n-1; i++) {
    if(str[i] == str[i+1]) {
      is_palin[i][i + 1] = true;
      if(max_substr_len < 2) {
        sol = {i, i+1};
        max_substr_len = 2;
      }
    }
  }

  for(int i = 0; i < n - 2; i++) {
    for(int j = i+2; j < n; j++) {
      if(str[i] == str[j] and is_palin[i+1][j-1]) {
        is_palin[i][j] = true;
        int curr_plain_len = j-i+1;
        if(max_substr_len < curr_plain_len) {
          max_substr_len = curr_plain_len;
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
  std::string str;
  std::cin >> str;
  std::pair<int, int> sol = Solve(str);
  int sol_len = sol.second - sol.first + 1;
  std::string sol_str = str.substr(sol.first, sol_len);
  std::cout << sol_str << std::endl;
  return 0;
}

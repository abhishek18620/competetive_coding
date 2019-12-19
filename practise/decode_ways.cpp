//https://leetcode.com/problems/unique-paths/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int Solve(const std::string& str) {
  const int& N = str.length();
  std::vector<int> dp(N+1, 0);
  if(str[0] == '0') {
    return 0;
  }
  dp[0] = 1;
  for(int i = 1; i < N; i++) {
      if(str[i] != '0') {
        dp[i] = dp[i-1];
      }
      int val = (str[i-1] - (int)'0')*10 + (str[i] - (int)'0');
      if(val > 0 && val <= 26) {
        dp[i] += (i-2 >= 0) ? dp[i-2] : 1;
      }
      if(dp[i] == 0) {
        //none case matches
        return 0;
      }
  }
  return dp[N-1];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str;
  getline(std::cin, str);
  printf("%d", Solve(str));
  return 0;
}

// https://leetcode.com/problems/edit-distance/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int Solve(const std::string &str1, const std::string &str2) {
  if (str1 == str2) {
    // no operations required
    return 0;
  }
  int m = str1.length();
  int n = str2.length();
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  // base cases
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0) {
        dp[i][j] = j;
        continue;
      }
      if (j == 0) {
        dp[i][j] = i;
        continue;
      }
      if (str1[i - 1] == str2[j - 1]) {
        // same character no operation required
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = 1 + std::min(dp[i][j - 1],             // insert
                              std::min(dp[i - 1][j],    // delete
                                       dp[i - 1][j - 1] // replace
                                       ));
    }
  }

  // for (int i = 0; i < m; i++) {
  // printf("\n");
  // for (int j = 0; j < n; j++) {
  //  printf("%d  ", dp[i][j]);
  //}
  //}
  return dp[m][n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str1, str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  printf("%s: Input str1 = %s  str2 = %s\n", __func__, str1.c_str(),
         str2.c_str());
  printf("%s: solution = %d\n", __func__, Solve(str1, str2));
  return 0;
}

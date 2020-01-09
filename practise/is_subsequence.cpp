// https://leetcode.com/problems/is-subsequence/
#include <iostream>
#include <vector>

int SolveOptimised(const std::string& str1, const std::string& str2) {
  const int m = str1.size();
  const int n = str2.size();
  // handle crappy base cases
  if (m == 0) {
    return n == 0;
  }
  if (m < n) {
    return false;
  }
  if (str1 == str2) {
    return true;
  }

  int str2_idx = 1;

  for (int i = 1; i <= m; ++i) {
    if (str1[i - 1] == str2[str2_idx - 1]) {
      // equa char
      str2_idx++;
    }
  }
  printf("%s: str2_idx = %d\n", __func__, str2_idx);
  return str2_idx == n + 1;
}

int Solve(const std::string& str1, const std::string& str2) {
  const int m = str1.size();
  const int n = str2.size();
  // handle crappy base cases
  if (m == 0) {
    return n == 0;
  }

  std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1));
  for (int i = 0; i <= m; ++i) {
    dp[i][0] = true;
  }

  for (int j = 1; j <= n; ++j) {
    for (int i = j; i <= m; ++i) {
      dp[i][j] = (dp[i - 1][j - 1] && (str1[i - 1] == str2[j - 1])) || dp[i - 1][j];
      // if (dp[i][j])
      // printf("%s: state(%d, %d) = %s\n", __func__, i, j, dp[i][j] ? "true" : "false");
    }
  }
  return dp[m][n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str1;
  std::string str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  printf("%s: str1 = %s  str2 = %s\n", __func__, str1.c_str(), str2.c_str());
  printf("%s: solution = %s\n", __func__, Solve(str1, str2) ? "true" : "false");
  printf("%s: solution = %s\n", __func__, SolveOptimised(str1, str2) ? "true" : "false");
  return 0;
}

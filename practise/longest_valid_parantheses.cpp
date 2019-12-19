// https://leetcode.com/problems/longest-valid-parentheses/
#include <iostream>
#include <string>
#include <vector>

int SolveRecursive(const std::string &str, int i, int j,
                   std::vector<std::vector<int>> &dp,
                   const std::vector<int> &prefix_sum, int &max_len) {
  // base cases
  // printf("%d, %d\n", i, j);
  if (i > j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    // printf("2\n");
    return dp[i][j];
  }
  if ((j - i + 1) & 1) {
    // odd number of chars
    // printf("1\n");
    dp[i][j] = 0;
  }
  if (str[i] != '(' || str[j] != ')') {
    // printf("3\n");
    dp[i][j] = 0;
  }
  if (i + 1 == j) {
    // printf("4\n");
    max_len = std::max(max_len, 2);
    return dp[i][j] = 1;
  }
  if (prefix_sum[j + 1] - prefix_sum[i] != 0) {
    dp[i][j] = 0;
  }
  // end of base cases

  if (dp[i][j] == 0) {
    SolveRecursive(str, i, j - 1, dp, prefix_sum, max_len);
    SolveRecursive(str, i + 1, j, dp, prefix_sum, max_len);
    return 0;
  } else {
    int sol = SolveRecursive(str, i + 1, j - 1, dp, prefix_sum, max_len);
    if (sol != 1) {
      int mid = (i + j) >> 1;
      sol = (SolveRecursive(str, i, mid, dp, prefix_sum, max_len) &&
             SolveRecursive(str, mid + 1, j, dp, prefix_sum, max_len))
                ? 1
                : 0;
    }
    if (i == 11 && j == 22) {
      std::cout << sol << std::endl;
    }
    if (sol == 1) {
      printf("%d, %d = %d\n", i, j, j - i + 1);
      max_len = std::max(max_len, j - i + 1);
      if (max_len == j - i + 1) {
        std::cout << "caught " << i << ", " << j << std::endl;
      }
    }
    return dp[i][j] = sol;
  }
}

int Solve(const std::string &str) {
  int n = str.length();
  std::vector<int> prefix_sum(n + 1, 0);
  prefix_sum[0] = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') {
      prefix_sum[i + 1] = prefix_sum[i] + 1;
    } else {
      prefix_sum[i + 1] = prefix_sum[i] - 1;
    }
  }
  // sum(i, j) = prefix_sum[j+1] - prefix_sum[i]
  int max_len = 0;
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  SolveRecursive(str, 0, n - 1, dp, prefix_sum, max_len);
  return max_len;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str;
  std::getline(std::cin, str);
  printf("%s: Input: %s and length = %d\n", __func__, str.c_str(),
         (int)str.length());
  printf("%s: solution: %d\n", __func__, Solve(str));
  return 0;
}

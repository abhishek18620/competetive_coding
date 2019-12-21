// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <string>
#include <vector>

/* Recursive */
int SolveRecursive(const int &n, const int &i, const int &j,
                   std::vector<std::vector<int>> &dp) {
  // base cases
  // printf("%d, %d\n", i, j);
  if (i > n || j > n) {
    return 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (i > j || i == j) {
    return dp[i][j] = 1;
  }
  if (i + 1 == j) {
    return dp[i][j] = 2;
  }
  int sol = 0;
  for (int root = i; root <= j; root++) {
    sol +=
        SolveRecursive(n, i, root - 1, dp) * SolveRecursive(n, root + 1, j, dp);
  }
  return dp[i][j] = sol;
}

/* Iterative */
int SolveIterative(const int &n) {
  std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 1));
  for (int length = 1; length <= n; length++) {
    for (int start = 1; start <= n; start++) {
      int end = start + length - 1;
      int sol = 0;
      if (end > n) {
        continue;
      }
      for (int k = start; k <= end; k++) {
        sol += dp[k - start][start] * dp[end - k][k + 1];
      }
      dp[length][start] = (sol == 0) ? 1 : sol;
    }
  }
  return dp[n][1]; // length, start
}

int Solve(const int &n) {
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  int sol_recursive = SolveRecursive(n, 1, n, dp);
  int sol_iterative = SolveIterative(n);
  if (sol_iterative == sol_recursive) {
    std::cout << "Passed ............." << std::endl;
  } else {
    // wanted to use gtest but was just a simple EXPECT_EQ ;)
    printf("%s: Not matched!! recursive = %d iterative = %d\n", __func__,
           sol_recursive, sol_iterative);
    std::cout << "Failed xxxxxxxxxxxxx" << std::endl;
  }
  return sol_recursive;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: solution = %d\n", __func__, Solve(n));
  return 0;
}


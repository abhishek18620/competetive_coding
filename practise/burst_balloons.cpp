// https://leetcode.com/problems/burst-balloons/
#include <iostream>
#include <vector>

int SolveOptimised(const std::vector<int>& arr) {
  int sz = arr.size();
  int n  = sz - 2;
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    arr[1];
  }
  std::vector<std::vector<int>> dp(sz, std::vector<int>(sz));
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i < n; ++i) {
      int j = i + len + 1;
      if (j > n + 1) {
        break;
      }
      for (int k = i + 1; k < j; ++k) {
        dp[i][len] = std::max(dp[i][len], dp[i][k - i - 1] + (arr[i] * arr[k] * arr[j]) +
                                              dp[k][j - k - 1]);
      }
      printf("%s: (%d, %d) = %d\n", __func__, i, len, dp[i][len]);
    }
  }
  return dp[0][n];
}

int SolveRecursive(const int& i, const int& j, const int& n, const std::vector<int>& arr,
                   std::vector<std::vector<int>>& dp) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int state_i_j = 0;
  for (int k = i + 1; k < j; ++k) {
    state_i_j =
        std::max(state_i_j, SolveRecursive(i, k, n, arr, dp) + arr[i] * arr[k] * arr[j] +
                                SolveRecursive(k, j, n, arr, dp));
  }
  printf("%s: (%d, %d) = %d\n", __func__, i, j, state_i_j);
  return dp[i][j] = state_i_j;
}

int Solve(std::vector<int>& arr) {
  const int n = arr.size();

  std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
  // state(i, j) = arr starting from i to j
  int sol1 = SolveRecursive(0, n - 1, n - 2, arr, dp);
  printf("\n");
  int sol2 = SolveOptimised(arr);
  printf("%s: solution using Solve = %d\n", __func__, sol1);
  printf("%s: solution using SolveOptimised = %d\n", __func__, sol2);
  return sol1;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input n = %d\n", __func__, n);
  std::vector<int> arr(n + 2);
  arr[0]     = 1;
  arr[n + 1] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    printf("%d  ", arr[i]);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr));
  return 0;
}

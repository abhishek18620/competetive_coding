// https://leetcode.com/problems/house-robber/
#include <iostream>
#include <string>
#include <vector>

int SolveOptimised(std::vector<int>& arr) {
  int n = arr.size();
  // base cases
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return arr[0];
  }
  if (n == 2) {
    return std::max(arr[0], arr[1]);
  }
  // dp
  std::vector<int> dp(2, 0);
  dp[0] = arr[0];
  dp[1] = std::max(arr[0], arr[1]);
  int temp;
  for (int i = 2; i < n; i++) {
    temp = std::max(dp[1], dp[0] + arr[i]);
    std::swap(dp[1], dp[0]); // this is fucking expensive
    dp[1] = temp;
  }
  return dp[1];
}

int Solve(std::vector<int>& arr) {
  int n = arr.size();
  // base cases
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return arr[0];
  }
  if (n == 2) {
    return std::max(arr[0], arr[1]);
  }
  // dp
  std::vector<int> dp(n + 1, 0);
  dp[0] = arr[0];
  dp[1] = std::max(arr[0], arr[1]);
  for (int i = 2; i < n; i++) {
    dp[i] = std::max(dp[i - 1], dp[i - 2] + arr[i]);
    printf("%s: dp[%d] = %d\n", __func__, i, dp[i]);
  }
  return dp[n - 1];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n%s: solution = %d\n", __func__, Solve(arr));
  printf("\n%s: solution = %d\n", __func__, SolveOptimised(arr));
  return 0;
}

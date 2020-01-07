// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>

int SolveOptimised(std::vector<int>& arr) {
  const int& n = arr.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return arr[0];
  }
  std::vector<int> dp(2); // only need last two states
  dp[0] = 0;
  dp[1] = arr[0];
  int temp_state; // temp state
  for (int i = 2; i <= n; ++i) {
    temp_state = dp[1];
    dp[1]      = std::min(dp[0], dp[1]) + arr[i - 1];
    dp[0]      = temp_state;
    // printf("%s: dp[%d] = %d\n", __func__, i, dp[i]);
  }
  return std::min(dp[0], dp[1]);
}

int Solve(std::vector<int>& arr) {
  const int& n = arr.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return arr[0];
  }
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = arr[0];
  for (int i = 2; i <= n; ++i) {
    dp[i] = std::min(dp[i - 1], dp[i - 2]) + arr[i - 1];
    // printf("%s: dp[%d] = %d\n", __func__, i, dp[i]);
  }
  return std::min(dp[n - 1], dp[n]);
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr));
  printf("%s: solution = %d\n", __func__, SolveOptimised(arr));
  return 0;
}

// https://leetcode.com/problems/counting-bits/
#include <iostream>
#include <vector>

std::vector<int> Solve(const int& n) {
  if (n == 0) {
    return std::vector<int>{0};
  }
  if (n == 1) {
    return std::vector<int>{0, 1};
  }
  if (n == 2) {
    return std::vector<int>{0, 1, 1};
  }
  // more than 2
  std::vector<int> dp(n + 1);
  dp[0]                       = 0;
  dp[1]                       = 1;
  dp[2]                       = 1;
  int next_nearest_power_of_2 = 4;
  int dis                     = 1; // distance from nearest power of 2

  for (int i = 3; i <= n; ++i) {
    if (i == next_nearest_power_of_2) {
      dp[i] = dis = 1;
      next_nearest_power_of_2 <<= 1;
      continue;
    }
    dp[i] = 1 + dp[dis++];
  }
  return dp;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input: n = %d\n", __func__, n);
  const auto& sol = Solve(n);
  printf("%s: solution:\n", __func__);
  for (const auto& ele : sol) {
    printf("%d  ", ele);
  }
  printf("\n");
  return 0;
}


// https://leetcode.com/problems/perfect-squares/
#include <cmath>
#include <iostream>
#include <vector>

int Solve(const int& n) {
  if (n == 0 || n == 1 || n == 2) {
    return n;
  }
  std::vector<int> dp(n + 1);
  // base cases
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = i;
    for (int j = std::sqrt(i); j >= 1; --j) {
      dp[i] = std::min(dp[i], dp[i - j * j] + 1);
    }
    printf("dp[%d] = %d\n", i, dp[i]);
  }
  return dp[n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  printf("%s: solution = %d\n", __func__, Solve(n));
  return 0;
}

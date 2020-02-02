#include <iostream>
#include <numeric>
#include <vector>

int Solve(const int& n) {
  std::vector<int> dp(11);
  dp[0] = 1;
  dp[1] = 9;
  dp[2] = 81;
  for (int i = 3; i <= 10; ++i) {
    dp[i] = dp[i - 1] * (10 - i + 1);
  }

  int sol = 0;
  if (n <= 10) {
    sol = std::accumulate(dp.begin(), dp.begin() + n + 1, 0);
  } else {
    sol = std::accumulate(dp.begin(), dp.end(), 0);
  }
  return sol;
}

int main() {
  // int n;
  // scanf("%d", &n);
  // printf("%s: n = %d\n", __func__, n);
  for (int i = 0; i < 20; i++) {
    printf("%s: solution for %d = %d\n", __func__, i, Solve(i));
  }
  return 0;
}

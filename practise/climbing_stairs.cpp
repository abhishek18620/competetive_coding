// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <string>
#include <vector>

int Solve(int n) {
  std::vector<int> dp(n + 1, -1);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: solution = %d\n", __func__, Solve(n));
  return 0;
}


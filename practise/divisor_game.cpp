// https://leetcode.com/problems/divisor-game/
#include <cmath>
#include <iostream>
#include <vector>
// Dp approach
bool SolveDP(const int& N) {
  std::vector<bool> dp(N + 1);
  if (N == 1) {
    return true;
  }
  dp[1] = false;
  for (int i = 2; i <= N; ++i) {
    for (int factor = std::sqrt(i); factor >= 1; --factor) {
      if (i % factor == 0 && !dp[i - factor]) {
        // printf("%s: i = %d factor = %d\n", __func__, i, factor);
        dp[i] = true;
        break;
      }
    }
  }
  return dp[N];
}

bool Solve(const int& N) {
  return !(N & 1); // for even number alice would just choose 2 and win
}

int main() {
  // freopen("../input.txt", "rt", stdin);
  // int N;
  // scanf("%d", &N);
  // printf("%s: N = %d\n", __func__, N);
  for (int i = 1; i <= 1000; ++i) {
    printf("%s: N = %d solution = %s\n", __func__, i, Solve(i) ? "true" : "false");
  }
}

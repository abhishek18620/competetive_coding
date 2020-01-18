// https://leetcode.com/problems/knight-dialer/
#include <iostream>
#include <vector>

static constexpr int MOD = 1e9 + 7;

inline static int AddModulo(const int& a, const int& b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

int Solve(const int& n) {
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 10;
  }
  const std::vector<std::vector<int>> possible_moves = {{4, 6},    // 0
                                                        {6, 8},    // 1
                                                        {7, 9},    // 2
                                                        {4, 8},    // 3
                                                        {3, 9, 0}, // 4
                                                        {},        // 5
                                                        {7, 1, 0}, // 6
                                                        {6, 2},    // 7
                                                        {1, 3},    // 8
                                                        {2, 4}};   // 9

  std::vector<std::vector<int>> dp(2, std::vector<int>(10));
  int                           curr_move_mask;
  int                           prev_move_mask;
  int                           total_sol;
  for (int i = 0; i <= 9; ++i) {
    dp[1][i] = 1;
  }
  for (int move = 2; move <= n; ++move) {
    curr_move_mask = move & 1;
    prev_move_mask = !curr_move_mask;
    for (int dial = 0; dial <= 9; ++dial) {
      total_sol = 0;
      for (auto& next_move : possible_moves[dial]) {
        total_sol = AddModulo(total_sol, dp[prev_move_mask][next_move]);
      }
      dp[curr_move_mask][dial] = total_sol;
      // printf("%s: masks: prev : %d curr : %d state(%d %d) = %d\n", __func__,
      // prev_move_mask, curr_move_mask, move, dial, total_sol);
    }
  }
  total_sol = 0;
  for (int i = 0; i <= 9; ++i) {
    total_sol = AddModulo(total_sol, dp[curr_move_mask][i]);
  }
  return total_sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  printf("%s: %d\n", __func__, Solve(n));
}

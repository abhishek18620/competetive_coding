// https://leetcode.com/problems/integer-break/
#include <algorithm> // for std::max_element
#include <iostream>
#include <vector>

int SolveOptimised(const int& n) {
  // state(num, integer_used) = create num using interger_used
  std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(10, std::vector<int>(10, -1)));
  for (int i = 1; i <= n; ++i) {
    dp[i][1][1] = 1;
    if (i <= 9) {
      dp[i][i][i] = i;
    }
  }

  int sol = 0;
  for (int num = 2; num <= n; ++num) {
    for (int first_part = 1; first_part <= num - 1; ++first_part) {
      for (int int_used1 = 1; int_used1 <= std::min(num, 9); ++int_used1) {
        for (int int_used2 = 1; int_used2 <= std::min(num, 9); ++int_used2) {
          if (num < int_used1 && num < int_used2) {
            dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] = 0;
            continue;
          }
          // int used to build first_part
          if (dp[first_part][int_used1][int_used2] == 0 || dp[num - first_part][int_used1][int_used2] == 0) {
            dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] = 0;
            continue;
          }
          // different combinations og getting num from int_used1 and int_used2
          sol = dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used1][int_used2];
          sol = std::max(sol, dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used1][int_used1]);
          sol = std::max(sol, dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used2][int_used2]);

          sol = std::max(sol, dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used1][int_used2]);
          sol = std::max(sol, dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used1][int_used1]);
          sol = std::max(sol, dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used2][int_used2]);

          sol = std::max(sol, dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used1][int_used2]);
          sol = std::max(sol, dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used1][int_used1]);
          sol = std::max(sol, dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used2][int_used2]);
          dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] = std::max(dp[num][int_used1][int_used2], sol);
        }
      }
    }
  }
  sol = 1;
  for (int int_used1 = 1; int_used1 <= std::min(n - 1, 9); ++int_used1) {
    for (int int_used2 = 1; int_used2 <= std::min(n - 1, 9); ++int_used2) {
      sol = std::max(sol, dp[n][int_used1][int_used2]);
    }
  }
  return sol;
}

int Solve(const int& n) {
  // state(num, integer_used) = create num using interger_used
  std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(10, std::vector<int>(10, -1)));
  std::vector<int>                           memo(9);
  for (int i = 1; i <= n; ++i) {
    dp[i][1][1] = 1;
    if (i <= 9) {
      dp[i][i][i] = i;
    }
  }

  for (int num = 2; num <= n; ++num) {
    for (int first_part = 1; first_part <= num - 1; ++first_part) {
      for (int int_used1 = 1; int_used1 <= std::min(num, 9); ++int_used1) {
        for (int int_used2 = 1; int_used2 <= std::min(num, 9); ++int_used2) {
          if (num < int_used1 && num < int_used2) {
            dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] = 0;
            continue;
          }
          // int used to build first_part
          if (dp[first_part][int_used1][int_used2] == 0 || dp[num - first_part][int_used1][int_used2] == 0) {
            dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] = 0;
            continue;
          }
          // different combinations og getting num from int_used1 and int_used2
          memo[0] = dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used1][int_used2];
          memo[1] = dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used1][int_used1];
          memo[2] = dp[first_part][int_used1][int_used2] * dp[num - first_part][int_used2][int_used2];

          memo[3] = dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used1][int_used2];
          memo[4] = dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used1][int_used1];
          memo[5] = dp[first_part][int_used1][int_used1] * dp[num - first_part][int_used2][int_used2];

          memo[6] = dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used1][int_used2];
          memo[7] = dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used1][int_used1];
          memo[8] = dp[first_part][int_used2][int_used2] * dp[num - first_part][int_used2][int_used2];
          dp[num][int_used1][int_used2] = dp[num][int_used2][int_used1] =
              std::max(dp[num][int_used1][int_used2], *std::max_element(memo.begin(), memo.end()));
        }
      }
    }
  }
  int sol = 1;
  for (int int_used1 = 1; int_used1 <= std::min(n - 1, 9); ++int_used1) {
    for (int int_used2 = 1; int_used2 <= std::min(n - 1, 9); ++int_used2) {
      sol = std::max(sol, dp[n][int_used1][int_used2]);
    }
  }
  return sol;
}

int main() {
  // freopen("../input.txt", "rt", stdin);
  // int n;
  // scanf("%d", &n);
  // printf("%s: n = %d\n", __func__, n);
  for (int i = 2; i <= 58; ++i) {
    printf("%s: Solve(%d) = %d  SolveOptimised(%d) = %d\n", __func__, i, Solve(i), i, SolveOptimised(i));
  }
  return 0;
}

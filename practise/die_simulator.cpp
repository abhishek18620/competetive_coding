// https://leetcode.com/problems/dice-roll-simulation/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static int constexpr MOD = 1e9 + 7;

inline static int AddModulo(const int& a, const int& b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

inline static int SubModulo(const int& a, const int& b) {
  return ((a % MOD) - (b % MOD)) % MOD;
}

struct State {
  std::vector<int> occurence;
  int              total_occ_j = 0;
};

static int GetNonOccOfJOnIthState(const int& i, const int& j,
                                  std::vector<std::vector<State>>& dp) {
  int sol = 0;
  for (int outcome = 1; outcome <= 6; ++outcome) {
    sol = AddModulo(sol, dp[i][outcome].total_occ_j);
    // sol %= MOD;
  }
  // printf("%s: State(%d, %d) = %d\n", __func__, i, j, sol);
  return SubModulo(sol, dp[i][j].total_occ_j);
}

int Solve(const int& n, std::vector<int>& roll_max) {
  // handle bases cases
  if (n == 0) {
    return 0;
  }
  std::vector<int> arr(7);
  std::copy(roll_max.begin(), roll_max.begin() + 6, ++arr.begin());

  std::vector<std::vector<State>> dp(n + 1,
                                     std::vector<State>(7)); // 3D state
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      dp[i][j].occurence.resize(arr[j] + 1);
    }
  }
  /*
   * State(I, J, K) = ith roll, jth dice outcome, Kth consecutive occurennce of jth
   */
  for (int j = 1; j <= 6; ++j) {
    dp[1][j].occurence[1] = (arr[j] >= 1) ? 1 : 0;
    dp[1][j].total_occ_j  = (arr[j] >= 1) ? 1 : 0;
  }
  int max_consec_allowed_occs = 0;
  int total_occ               = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (arr[j] >= 1) {
        total_occ = dp[i][j].occurence[1] = GetNonOccOfJOnIthState(i - 1, j, dp);
        printf("%s: State(%d, %d, 1) = %d\n", __func__, i, j, dp[i][j].occurence[1]);
      }
      max_consec_allowed_occs = std::min(arr[j], i);
      for (int consec_occs = 2; consec_occs <= max_consec_allowed_occs; consec_occs++) {
        dp[i][j].occurence[consec_occs] = dp[i - 1][j].occurence[consec_occs - 1];
        total_occ = AddModulo(total_occ, dp[i][j].occurence[consec_occs]);
        // total_occ %= MOD;
        printf("%s: State(%d, %d, %d) = %d\n", __func__, i, j, consec_occs,
               dp[i][j].occurence[consec_occs]);
      }
      dp[i][j].total_occ_j = total_occ;
    }
  }
  int sol = 0;
  for (int i = 1; i <= 6; i++) {
    sol = AddModulo(sol, dp[n][i].total_occ_j);
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input = %d\n", __func__, n);
  std::vector<int> arr(7);
  for (int& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(n, arr));
  return 0;
}

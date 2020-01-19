// https://www.spoj.com/problems/ACTIV/
#include <algorithm> // for sort
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

static int constexpr SZ  = 1e5 + 7;
static int constexpr MOD = 1e8;

inline static int AddModulo(const int& a, const int& b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

int LowerBound(const std::vector<std::pair<int, int>>& intervals, const int& target,
               int&& left, int&& right) {
  int mid     = -1;
  int ret_idx = -1;
  while (left <= right) {
    mid = left + ((right - left) >> 1);
    if (intervals[mid].first < target) {
      left = mid + 1;
    } else if (intervals[mid].first > target) {
      right   = mid - 1;
      ret_idx = mid;
    } else {
      // case of equality
      ret_idx = mid;
      right   = mid - 1;
    }
  }
  return ret_idx;
}

int Solve(std::vector<std::pair<int, int>>& intervals,
          std::vector<std::pair<int, int>>& dp, const int& n) {
  // sort the array
  // std::sort(intervals.begin(), intervals.begin() + n,
  //[](const std::pair<int, int>& left, const std::pair<int, int>& right) {
  //  return left.first < right.first;
  //});
  std::sort(intervals.begin(), intervals.begin() + n);

  int lower_bound;
  dp[n - 1] = {1, 1};
  for (int i = n - 2; i >= 0; --i) {
    lower_bound = -1;
    lower_bound = LowerBound(intervals, intervals[i].second, i + 1, n - 1);
    dp[i].first = 1;
    if (lower_bound == -1) {
      dp[i].second = AddModulo(dp[i + 1].second, 1);
      // printf("%s: target = %d  lb = %d dp[%d]= (%d, %d) \n", __func__,
      // intervals[i].second, lower_bound, i, dp[i].first, dp[i].second);
      continue;
    }
    dp[i].first  = AddModulo(dp[lower_bound].second, 1);
    dp[i].second = AddModulo(dp[i + 1].second, dp[i].first);
    // printf("%s: target = %d  lb = %d dp[%d]= (%d, %d) \n", __func__,
    // intervals[i].second, lower_bound, i, dp[i].first, dp[i].second);
  }
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    sol = AddModulo(sol, dp[i].first);
  }
  return sol;
}

int main() {
  std::vector<std::pair<int, int>> intervals(SZ);
  std::vector<std::pair<int, int>> dp(SZ); // state sol for i, state sol beyond this
  freopen("../input.txt", "rt", stdin);
  int n = 0;
  scanf("%d", &n);
  while (n != -1) {
    // printf("%s: n = %d\n", __func__, n);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &intervals[i].first, &intervals[i].second);
      // printf("(%d, %d)  ", pai.first, pai.second);
    }
    // form the solutiom=n string
    std::string sol             = std::to_string(Solve(intervals, dp, n));
    int         zeroes_required = 8 - sol.length();
    sol                         = std::string(zeroes_required, '0') + sol;
    // printf("%s: solution = %s\n", __func__, sol.c_str());
    printf("%s\n", sol.c_str());
    scanf("%d", &n);
  }
  return 0;
}

// https://leetcode.com/problems/wiggle-subsequence/
#include <iostream>
#include <vector>

static constexpr auto signum = [](int n) { return (n == 0) ? 0 : (n > 0) ? 1 : -1; };

int SolveOptimised(const std::vector<int>& arr) {
  const int n = arr.size();
  if (n == 1 || n == 0) {
    return n;
  }

  int last_sign = 0;
  int sol       = 1;
  for (int i = 1; i < n; ++i) {
    int curr_sign = signum(arr[i] - arr[i - 1]);

    if (curr_sign != last_sign && curr_sign != 0) {
      last_sign = curr_sign;
      sol++;
    }
  }
  return sol;
}

int Solve(const std::vector<int>& arr) {
  const int n = arr.size();
  if (n == 1) {
    return 1;
  }
  // first indicates positive and second indicates negative
  std::vector<std::pair<int, int>> dp(n);
  dp[0] = {1, 1};
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i - 1; ++j) {
      if (arr[i] > arr[j]) {
        // need to look for longest negative
        dp[i].first = std::max(dp[i].first, dp[j].second + 1);
      }
      if (arr[i] < arr[j]) {
        // need to look for longest positive
        dp[i].second = std::max(dp[i].second, dp[j].first + 1);
      }
    }
    printf("%s: max till %d = %d\n", __func__, i, std::max(dp[i].first, dp[i].second));
  }
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    sol = std::max(sol, std::max(dp[i].first, dp[i].second));
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution using Solve = %d\n", __func__, Solve(arr));
  printf("%s: solution using SolveOptimised = %d\n", __func__, SolveOptimised(arr));
  return 0;
}

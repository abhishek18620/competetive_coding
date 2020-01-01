// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <stack>
#include <vector>

int SolveOptimised(const std::vector<int>& arr) {
  if (arr.size() == 0)
    return 0;

  std::vector<int> tail(arr.size(), 0);
  int              length = 1; // always points empty slot in tail

  tail[0] = arr[0];

  for (int i = 1; i < arr.size(); i++) {

    auto beg = tail.begin(), end = tail.begin() + length;
    auto it = lower_bound(beg, end, arr[i]);

    if (it == tail.begin() + length)
      tail[length++] = arr[i];
    else
      *it = end[i];
  }

  return length;
}

int SolveDP(const std::vector<int>& arr) {
  int n = arr.size();
  if (n == 0) {
    return 0;
  }
  std::vector<int> dp(n + 1, 1);
  int              sol = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      // std::max()
      if (arr[i] < arr[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    printf("%s: dp[%d] = %d\n", __func__, i, dp[i]);
    sol = std::max(sol, dp[i]);
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s : Solution = %d\n", __func__, SolveDP(arr));
  // printf("%s : Solution = %d\n", __func__, SolveOptimised(arr));
  return 0;
}

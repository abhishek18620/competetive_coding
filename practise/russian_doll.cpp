// https://leetcode.com/problems/russian-doll-envelopes/
#include <algorithm> // for std::sort
#include <iostream>
#include <vector>

int SolveOptimised(std::vector<std::pair<int, int>>& arr) {
  const int n = arr.size();
  // sanity check
  if (n == 0 || n == 1) {
    return n;
  }
  std::sort(arr.begin(), arr.end());
  for (auto& pai : arr) {
    printf("(%d, %d)  ", pai.first, pai.second);
  }
  printf("\n");
  std::vector<int> dp(n, 1);
  int              search_till_idx = -1;
  for (int i = 1; i < n; ++i) {
    search_till_idx = std::lower_bound(arr.begin(), arr.begin() + i, std::make_pair(arr[i].first, 0)) - arr.begin();
    if (arr[search_till_idx].first == arr[i].first) {
      search_till_idx--;
    }
    printf("%s : search_till_idx = %d  ", __func__, search_till_idx);
    for (int j = 0; j <= search_till_idx; ++j) {
      if (arr[i].second > arr[j].second) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    printf("dp[%d] = %d\n", i, dp[i]);
  }
  return *std::max_element(dp.begin(), dp.end());
}

int Solve(std::vector<std::pair<int, int>>& arr) {
  const int n = arr.size();
  // sanity check
  if (n == 0 || n == 1) {
    return n;
  }
  std::sort(arr.begin(), arr.end());
  for (auto& pai : arr) {
    printf("(%d, %d)  ", pai.first, pai.second);
  }
  printf("\n");
  std::vector<int> dp(n, 1);
  for (int i = 1; i < n; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i && arr[i].first > arr[j].first; ++j) {
      if (arr[i].second > arr[j].second) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    printf("dp[%d] = %d\n", i, dp[i]);
  }
  return *std::max_element(dp.begin(), dp.end());
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<std::pair<int, int>> arr(n);
  for (auto& pai : arr) {
    scanf("%d %d", &pai.first, &pai.second);
    printf("(%d, %d)  ", pai.first, pai.second);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr));
  printf("%s: solution = %d\n", __func__, SolveOptimised(arr));
  return 0;
}

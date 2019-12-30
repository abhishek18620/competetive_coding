// https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <vector>

int SolveOptimised(const std::vector<int>& arr) {
  int n = arr.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return arr[0];
  }
  // int = objective cost   bool = if 1st house has been robbed or not
  std::vector<std::pair<int, bool>> dp(2);
  dp[1]                                = std::make_pair(arr[0], true);
  std::pair<int, bool> curr_robbed     = {0, false};
  std::pair<int, bool> curr_not_robbed = {0, false};
  for (int i = 2; i < n; i++) {
    curr_robbed     = {dp[0].first + arr[i - 1], dp[0].second};
    curr_not_robbed = dp[1];
    if (curr_robbed.first < curr_not_robbed.first) {
      dp[0] = dp[1];
    } else if (curr_robbed > curr_not_robbed) {
      dp[0] = dp[1];
      dp[1] = curr_robbed;
    } else {
      // curr_robbed == curr_not_robbed
      // choose the one which allows us to rob the last house as well
      dp[0] = dp[1];
      dp[1] = (!curr_not_robbed.second) ? curr_not_robbed : curr_robbed;
    }
  }
  // calculate dp[n]
  curr_robbed     = {dp[0].first + arr[n - 1], dp[0].second};
  curr_not_robbed = dp[1];
  if (curr_robbed > curr_not_robbed) {
    // robbing the last house gives the max objective
    // But need to check if first one was robbed or not
    if (!dp[0].second) {
      return curr_robbed.first;
    }
    // let's check if last house has more value then first
    if (arr[n - 1] > arr[0]) {
      return std::max(curr_not_robbed.first, curr_robbed.first - arr[0]);
    }
  }
  return curr_not_robbed.first;
}

int Solve(const std::vector<int>& arr) {
  int n = arr.size();
  if (n == 0) {
    return 0;
  }
  // int = objective cost   bool = if 1st house has been robbed or not
  std::vector<std::pair<int, bool>> dp(n + 1);
  dp[1]               = std::make_pair(arr[0], true);
  int curr_robbed     = 0;
  int curr_not_robbed = 0;
  for (int i = 2; i < n; i++) {
    curr_robbed     = dp[i - 2].first + arr[i - 1];
    curr_not_robbed = dp[i - 1].first;
    if (curr_robbed < curr_not_robbed) {
      dp[i] = dp[i - 1];
    } else if (curr_robbed > curr_not_robbed) {
      dp[i] = {curr_robbed, dp[i - 2].second};
    } else {
      // curr_robbed == curr_not_robbed
      // choose the one which allows us to rob the last house as well
      dp[i] = (!dp[i - 1].second) ? dp[i - 1]
                                  : std::make_pair(curr_not_robbed, dp[i - 2].second);
    }
  }
  // calculate dp[n]
  curr_robbed     = dp[n - 2].first + arr[n - 1];
  curr_not_robbed = dp[n - 1].first;
  if (curr_robbed > curr_not_robbed) {
    // robbing the last house gives the max objective
    // But need to check if first one was robbed or not
    if (!dp[n - 2].second) {
      return curr_robbed;
    }
    // let's check if last house has more value then first
    if (arr[n - 1] > arr[0]) {
      return std::max(curr_not_robbed, curr_robbed - arr[0]);
    }
  }
  return curr_not_robbed;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n = 0;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  int backup;

  {
    // solution is std::max of both calls
    // Solve with n size dp
    printf("%s: solution from Solve = %d\n", __func__, Solve(arr));
    backup = arr[0];
    arr[0] = -1;
    printf("%s: solution from Solve = %d\n", __func__, Solve(arr));
  }

  {
    // solution is std::max of both calls
    // Solve with 2 sized dp
    arr[0] = backup;
    printf("%s: solution from SolveOptimised = %d\n", __func__, SolveOptimised(arr));
    // now calculate the cost starting from second house, where we can always rob the last
    arr[0] = -1; // make the first house value negative so that it can be ignored
    printf("%s: solution from SolveOptimised = %d\n", __func__, SolveOptimised(arr));
  }
  return 0;
}

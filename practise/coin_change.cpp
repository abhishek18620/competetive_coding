// https://leetcode.com/problems/coin-change/
#include <iostream>
#include <vector>

static constexpr int MAX_INF = 1e9;

int Solve(std::vector<int>& arr, const int& amount) {
  const int& n = arr.size();
  // sanity check
  if (n == 0 || amount == 0) {
    return amount == 0 ? 0 : -1;
  }
  std::vector<int> dp(amount + 1, MAX_INF);
  dp[0] = 0;
  for (int amt = 1; amt <= amount; ++amt) {
    for (int coin = 0; coin < n; ++coin) {
      dp[amt] =
          std::min(dp[amt], (amt - arr[coin] < 0) ? MAX_INF : dp[amt - arr[coin]] + 1);
    }
  }
  for (int i = 0; i <= amount; ++i) {
    printf("%d  ", dp[i]);
  }
  printf("\n");
  return (dp[amount] < MAX_INF && dp[amount] > 0) ? dp[amount] : -1;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  int amount;
  scanf("%d %d", &n, &amount);
  printf("%s: n = %d amount = %d\n", __func__, n, amount);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr, amount));
  return 0;
}

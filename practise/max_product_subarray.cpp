// https://leetcode.com/problems/maximum-product-subarray/
#include <iostream>
#include <vector>
typedef long long ll;
static constexpr ll INF = -1 * 1e18 + 9;

int Solve(std::vector<int>& arr) {
  int n = arr.size();
  std::vector<ll> dp(n + 1);
  // base case, for length 1
  ll sol = INF;
  for (int i = 0; i < n; i++) {
    dp[i] = arr[i];
    sol = std::max<ll>(sol, arr[i]);
  }
  for (int i = 0; i < n; i++) {
    dp[1] = arr[i];
    for (int len = 2; len <= n - i; len++) {
      dp[len] = dp[len - 1] * 1ll * arr[i + len - 1];
      sol = std::max<ll>(sol, dp[len]);
      printf("%s: (%d, %d) = %lld sol = %lld\n", __func__, i, len, dp[len],
             sol);
    }
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
  printf("%s: solution = %d\n", __func__, Solve(arr));
  return 0;
}

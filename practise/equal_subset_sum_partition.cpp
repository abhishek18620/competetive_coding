#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define trace2(x, y) std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                                                                \
  std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z            \
            << std::endl;
#define trace4(a, b, c, d)                                                                                             \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                                                          \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << " | " << #e << ": " << e << std::endl;

bool Solve(const std::vector<int>& arr) {
  const int n = arr.size();
  if (n < 2) { // sanity check
    return false;
  }
  std::vector<int> prefix_sum(n + 1);
  prefix_sum[0] = arr[0];
  for (int i = 1; i < n; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }
  if (prefix_sum[n - 1] & 1) { // odd so not possible
    return false;
  }
  const int half_sum = prefix_sum[n - 1] >> 1;
  for (const auto& ele : arr) { // one more sanity check
    if (ele == half_sum) {
      return true;
    }
  }
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(half_sum + 1));
  dp[0][arr[0]] = true;
  for (int i = 0; i < n; ++i) {
    for (int sum = arr[i]; sum <= std::min(half_sum, prefix_sum[i]); ++sum) {
      const int target_sum = sum - arr[i];
      for (int j = 0; j < i; ++j) {
        if (dp[j][target_sum]) {
          dp[i][sum] = true;
          if (sum == half_sum) { // possible
            return true;
          }
          break;
        }
      }
    }
  }
  return false;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d ", ele);
  }
  printf("\n");
  printf("%s: solution = %s\n", __func__, Solve(arr) ? "true" : "false");
  return 0;
}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
constexpr int INT_MAX = 1e9 + 9;
static int    FindMiddle(const int i, const int j) { return std::ceil((i + j) >> 1); }

int Solve(std::vector<int>& arr, const int k) {
  const int n = arr.size();
  std::sort(arr.begin(), arr.end());
  // Cost btw. 2 houses i-j with 1 post-office - built in the mid
  std::vector<std::vector<int>> wij(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    wij[i][i] = 0;
    for (int j = i + 1; j <= n; j++) {
      // Check both odd\even. It holds.
      wij[i][j] = wij[i][j - 1] + arr[j - 1] - arr[(i + j) / 2 - 1];
    }
  }

  // main DP
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][1] = wij[1][i];
  }
  for (int i = 2; i <= k; i++) // post-offices
  {
    for (int j = n; j > i; j--) // houses. Low j sets high j
    {
      dp[j][i] = INT_MAX;
      for (int x = i - 1; x < j; x++) {
        dp[j][i] = std::min(dp[j][i], dp[x][i - 1] + wij[x + 1][j]);
      }
    }
  }

  return dp[n][k];
}

int main() {
#ifdef DEBUG
  freopen("../input.txt", "rt", stdin);
#endif
  int n, k;
  scanf("%d %d", &n, &k);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
  }
  printf("%s: sol = %d\n", __func__, Solve(arr, k));
  return 0;
}

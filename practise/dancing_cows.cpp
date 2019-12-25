// https://www.spoj.com/problems/DCOWS/
#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
static constexpr int INF = 1e9 + 9;

ll Solve(std::vector<int>& bulls_height, std::vector<int>& cows_height) {
  std::sort(bulls_height.begin(), bulls_height.end());
  std::sort(cows_height.begin(), cows_height.end());
  for (auto bull : bulls_height) {
    printf("%d  ", bull);
  }
  printf("\n");
  for (auto cow : cows_height) {
    printf("%d  ", cow);
  }
  printf("\n");

  int N = bulls_height.size();
  int M = cows_height.size();
  std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(M + 1));
  for (int bull = 1; bull <= N; ++bull) {
    int last_cow_allowed = M - N + bull;
    // special first case
    dp[bull][bull] = std::abs(bulls_height[bull - 1] - cows_height[bull - 1]) +
                     dp[bull - 1][bull - 1];
    for (int cow = bull + 1; cow <= last_cow_allowed; ++cow) {
      dp[bull][cow] =
          std::min<ll>(dp[bull][cow - 1],
                       std::abs(bulls_height[bull - 1] - cows_height[cow - 1]) +
                           dp[bull - 1][cow - 1]);
    }
  }
  // Print dp array, please disable for long test case
  for (auto bull : dp) {
    for (auto cow : bull) {
      printf("%lld  ", cow);
    }
    printf("\n");
  }
  return dp[N][M];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int nbulls;
  int ncows;
  scanf("%d %d", &nbulls, &ncows);
  printf("%s: bulls = %d  cows = %d\n", __func__, nbulls, ncows);
  std::vector<int> bulls_height(nbulls);
  std::vector<int> cows_height(ncows);
  for (auto& height : bulls_height) {
    scanf("%d", &height);
  }
  printf("\n");
  for (auto& height : cows_height) {
    scanf("%d", &height);
  }
  printf("\n");
  printf("%s: solution = %lld\n", __func__, Solve(bulls_height, cows_height));
  return 0;
}

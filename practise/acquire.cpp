// https://www.spoj.com/problems/ACQUIRE/
#include <iostream>
#include <vector>

typedef long long ll;

static constexpr ll INF = 1e18 + 9;

void PreProcess(const int& n, std::vector<std::pair<ll, ll>>& plots,
                std::vector<std::vector<ll>>& cost_i_j) {

  ll max_width;
  ll max_length;
  for (int i = 0; i < n; i++) {
    max_length = plots[i].first;
    max_width = plots[i].second;
    for (int j = i; j < n; j++) {
      max_length = std::max<ll>(max_length, plots[j].first);
      max_width = std::max<ll>(max_width, plots[j].second);
      // printf("%s: (%d %d): %d %d\n", __func__, i, j, max_length, max_width);
      cost_i_j[i][j] = max_length * max_width;
    }
  }
  // for (int i = 0; i < n; i++) {
  // for (int j = 0; j < n; j++) {
  //  printf("%d  ", cost_i_j[i][j]);
  //}
  // printf("\n");
  //}
}

ll Solve(const int n, std::vector<std::pair<ll, ll>>& plots) {
  std::vector<std::vector<ll>> cost_i_j(n + 1, std::vector<ll>(n + 1));
  PreProcess(n, plots,
             cost_i_j); // preporocess the cost of buying land from plot i to j

  std::vector<ll> dp(n + 1, INF);
  for (int i = n - 1; i >= 0; --i) {
    // cost of buying plots i, n-1
    for (int k = i + 1; k < n; k++) {
      dp[i] = std::min(dp[i], cost_i_j[i][k - 1] + dp[k]);
    }
    dp[i] = std::min(dp[i], cost_i_j[i][n - 1]);
    // printf("%s: dp[%d] = %d  ", __func__, i, dp[i]);
  }
  return dp[0];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  // printf("%s: n = %d\n", __func__, n);
  std::vector<std::pair<ll, ll>> plots(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &plots[i].first, &plots[i].second);
    //  printf("plot %d : %d %d\n", i, plots[i].first, plots[i].second);
  }
  // printf("%s: solution = %lld\n", __func__, Solve(n, plots));
  printf("%lld\n", Solve(n, plots));
  return 0;
}

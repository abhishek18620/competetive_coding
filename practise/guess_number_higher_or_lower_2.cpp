// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include <iostream>
#include <string>
#include <vector>
constexpr auto INF = 1e9 + 9;

int SolveRecursive(const int i, const int j,
                   std::vector<std::vector<int>>& dp) {
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != INF) {
        return dp[i][j];
    }

    for (int k = i; k <= j; k++) {
        dp[i][j] =
            std::min(dp[i][j], k + std::max(SolveRecursive(i, k - 1, dp),
                                            SolveRecursive(k + 1, j, dp)));
    }
    printf("%s: dp[%d][%d] = %d\n", __func__, i, j, dp[i][j]);
    return dp[i][j];
}

int Solve(const int n) {
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, INF));
    auto                          sol = SolveRecursive(1, n, dp);
    return sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    printf("%s: n = %d\n", __func__, n);
    printf("%s: solution for %d = %d\n", __func__, n, Solve(n));
}

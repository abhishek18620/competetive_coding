// https://leetcode.com/problems/split-array-largest-sum/
#include <iostream>
#include <vector>

constexpr auto INF = 1e9 + 9;

int Solve(const std::vector<int>& arr, const int M) {
    const int                     N = arr.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, INF));
    std::vector<int>              pre_sum(N + 1);

    // calculate prefix sum sum[i..j] = pre_sum[j+1] - pre_sum[i]
    for (int i = 0; i < N; ++i) {
        pre_sum[i + 1] = pre_sum[i] + arr[i];
    }
    // pre fill dp
    for (int i = 0; i < N; ++i) {
        dp[i][1] = pre_sum[i + 1];
    }
    for (int i = 0; i < N; ++i) {
        for (int m = 2; m <= std::min(i + 1, M); ++m) {
            for (int k = m - 1; k <= i; ++k) {
                dp[i][m] =
                    std::min(dp[i][m], std::max(dp[k - 1][m - 1],
                                                pre_sum[i + 1] - pre_sum[k]));
            }
            // printf("%s: dp[%d][%d] = %d\n", __func__, i, m, dp[i][m]);
        }
    }

    return dp[N - 1][M];
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int              N, M;
    std::vector<int> arr;
    scanf("%d %d", &N, &M);
    arr.resize(N);
    for (auto& ele : arr) {
        scanf("%d", &ele);
        printf("%d ", ele);
    }
    printf("\n");
    printf("%s: solution = %d\n", __func__, Solve(arr, M));
    return 0;
}

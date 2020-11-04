#include <iostream>
#include <set>
#include <vector>

constexpr auto NEG_INF = -1e9 + 9;

int FindClosestToK(int new_val, int prev_val, int k) {
    if (new_val > k) {
        return NEG_INF;
    }
    return std::max(prev_val, new_val);
}

/* O(n^4) approach */
int Solve(const std::vector<std::vector<int>>& matrix, const int k) {
    int       sol = NEG_INF, row_mid, col_mid;
    const int m   = matrix.size() - 1;
    const int n   = matrix[0].size() - 1;
    printf("m = %d n = %d\n", m, n);
    std::vector<std::vector<std::vector<std::vector<int>>>> dp(
        m + 1, std::vector<std::vector<std::vector<int>>>(
                   n + 1, std::vector<std::vector<int>>(
                              m + 1, std::vector<int>(n + 1))));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[1][1][i][j] = matrix[i][j];
            int ret        = FindClosestToK(dp[1][1][i][j], sol, k);
            if (ret != NEG_INF) {
                sol = ret;
            }
        }
    }
    for (int row_size = 1; row_size <= m; ++row_size) {
        for (int col_size = 1; col_size <= n; ++col_size) {
            if (row_size == 1 && col_size == 1) {
                continue;
            }
            for (int i = 1; i <= m - row_size + 1; ++i) {
                for (int j = 1; j <= n - col_size + 1; ++j) {
                    if (col_size == 1) {
                        row_mid = row_size >> 1;
                        dp[row_size][col_size][i][j] =
                            dp[row_mid][col_size][i][j] +
                            dp[row_size - row_mid][col_size][i + row_mid][j];
                    } else {
                        col_mid = col_size >> 1;
                        dp[row_size][col_size][i][j] =
                            dp[row_size][col_mid][i][j] +
                            dp[row_size][col_size - col_mid][i][j + col_mid];
                    }
                    printf("(%d, %d, %d, %d) = %d\n", row_size, col_size, i, j,
                           dp[row_size][col_size][i][j]);
                    int ret =
                        FindClosestToK(dp[row_size][col_size][i][j], sol, k);
                    if (ret != NEG_INF) {
                        sol = ret;
                    }
                }
            }
        }
    }
    return sol;
}

int SolveOptimised(const std::vector<std::vector<int>>& matrix, const int k) {
    int       sol = NEG_INF;
    const int m   = matrix.size();
    const int n   = matrix[0].size();

    for (int left = 1; left < n; left++) {
        // array that accumulate sums for each row from left to right
        std::vector<int> sums(m);
        for (int right = left; right < n; right++) {
            // update sums to include values in curr right col
            for (int i = 1; i < m; i++) {
                sums[i] += matrix[i][right];
            }

            std::set<int> sum_set;
            // add 0 to cover the single row case
            sum_set.insert(0);
            int curr_sum = 0;

            for (int i = 1; i < m; i++) {
                curr_sum += sums[i];
                // we use sum subtraction (cur_sum - sum) to get the subarray
                // with sum <= k therefore we need to look for the smallest sum
                // >= curr_sum - k
                auto ub_iter = sum_set.upper_bound(curr_sum - k);
                if (ub_iter != sum_set.end()) {
                    sol = std::max(sol, curr_sum - (*ub_iter));
                    printf("sol = %d\n", sol);
                }
                sum_set.insert(curr_sum);
            }
        }
    }
    return sol;
}

int main() {
#ifdef DEBUG
    freopen("../input.txt", "rt", stdin);
#endif
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%s: sol = %d\n", __func__, Solve(matrix, k));
    printf("%s: sol = %d\n", __func__, SolveOptimised(matrix, k));
    return 0;
}

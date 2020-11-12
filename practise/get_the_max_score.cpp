// https://leetcode.com/problems/get-the-maximum-score/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

constexpr int MOD = 1e9 + 7;

void PrintState(const int state, int val1, int val2, int val3, int val4) {
    printf("--------------For state %d\n", state);
    printf("dp[0][0] = %d\n", val1);
    printf("dp[0][1] = %d\n", val2);
    printf("dp[1][0] = %d\n", val3);
    printf("dp[1][1] = %d\n", val4);
}

int SolveOptimised(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    const int n1   = arr1.size() - 1;
    const int n2   = arr2.size() - 1;
    long long sol1 = 0, sol2 = 0;
    long long prev_sol1 = 0, prev_sol2 = 0;
    int       i, j;
    for (i = 1, j = 1; i <= n1 && j <= n2;) {
        if (arr1[i] < arr2[j]) {
            sol1 += arr1[i++];
        } else if (arr1[i] > arr2[j]) {
            sol2 += arr2[j++];
        } else {
            sol1 = sol2 =
                std::max(prev_sol1 + arr1[i++], prev_sol2 + arr2[j++]);
        }
        prev_sol1 = sol1;
        prev_sol2 = sol2;
    }
    return std::max(std::accumulate(arr1.begin() + i, arr1.end(), sol1),
                    std::accumulate(arr2.begin() + j, arr2.end(), sol2)) %
           MOD;
}

int Solve(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    const int                                    n1 = arr1.size() - 1;
    const int                                    n2 = arr2.size() - 1;
    std::unordered_map<int, std::pair<int, int>> ele_map;

    for (int i = 1; i <= n1; ++i) {
        ele_map[arr1[i]] = {i, -1};
    }
    for (int i = 1; i <= n2; ++i) {
        if (ele_map.find(arr2[i]) == ele_map.end()) {
            ele_map[arr2[i]] = {-1, i};
        } else {
            (ele_map.at(arr2[i])).second = i;
        }
    }
    int max_num = std::max(arr1[n1], arr2[n2]);
    // state(val, arr1/arr2, switch or not)
    std::vector<std::vector<std::vector<int>>> dp(
        max_num + 1, std::vector<std::vector<int>>(2, std::vector<int>(2)));
    for (int i = 1; i <= max_num; ++i) {
        if (ele_map.find(i) == ele_map.end()) {
            continue;
        }
        int idx1 = ele_map[i].first;
        int idx2 = ele_map[i].second;
        if (idx1 != -1 && idx2 != -1) {
            // present in both arr1 and arr2
            // first arr1
            dp[i][0][0] =
                std::max(dp[arr1[idx1 - 1]][0][0], dp[arr1[idx1 - 1]][0][1]) +
                i;
            dp[i][0][1] = dp[arr2[idx2 - 1]][1][0] + i;

            // second arr2
            dp[i][1][0] =
                std::max(dp[arr2[idx2 - 1]][1][0], dp[arr2[idx2 - 1]][1][1]) +
                i;
            dp[i][1][1] = dp[arr1[idx1 - 1]][0][0] + i;

        } else if (idx1 != -1) { // only present in arr1
            dp[i][0][0] =
                std::max(dp[arr1[idx1 - 1]][0][0], dp[arr1[idx1 - 1]][0][1]) +
                i;
        } else { // only present in arr2
            dp[i][1][0] =
                std::max(dp[arr2[idx2 - 1]][1][0], dp[arr2[idx2 - 1]][1][1]) +
                i;
        }
        // PrintState(i, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
    }
    return std::max({dp[arr1[n1]][0][0], dp[arr1[n1]][0][1], dp[arr1[n1]][1][0],
                     dp[arr1[n1]][1][1], dp[arr2[n2]][0][0], dp[arr2[n2]][0][1],
                     dp[arr2[n2]][1][0], dp[arr2[n2]][1][1]}) %
           MOD;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("n1 = %d n2 = %d\n", n1, n2);
    std::vector<int> arr1(n1 + 1, 0);
    std::vector<int> arr2(n2 + 1, 0);
    for (int i = 1; i <= n1; ++i) {
        scanf("%d", &arr1[i]);
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 1; i <= n2; ++i) {
        scanf("%d", &arr2[i]);
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("%s: solution = %d\n", __func__, Solve(arr1, arr2));
    printf("%s: optimised solution = %d\n", __func__,
           SolveOptimised(arr1, arr2));

    return 0;
}

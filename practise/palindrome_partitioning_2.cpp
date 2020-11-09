// https://leetcode.com/problems/palindrome-partitioning-ii/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr auto INF = 1e9 + 9;

// 0(n^2) optimised approach
int SolveOptimised(std::string str) {
    const int n = str.length();

    std::vector<int>               dp(n + 1, INF);
    std::vector<std::vector<bool>> palin_i_j(n + 1, std::vector<bool>(n + 1));

    for (int i = 0; i < n; ++i) {
        palin_i_j[i][i] = true;
    }
    // calculate palindrome matrix
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (len == 2)
                palin_i_j[i][j] = (str[i] == str[j]);
            else
                palin_i_j[i][j] = (str[i] == str[j]) && palin_i_j[i + 1][j - 1];
        }
    }
    // dp
    for (int i = 0; i < n; ++i) {
        if (palin_i_j[0][i]) {
            dp[i] = 0;
        } else {
            for (int sep = 0; sep < i; ++sep) {
                if (palin_i_j[sep + 1][i])
                    dp[i] = std::min(dp[i], 1 + dp[sep]);
            }
        }
    }

    return dp[n - 1];
}

// O(n^3) approach
int Solve(std::string str) {
    auto check_palindrome = [](const std::string& str) {
        return std::equal(str.begin(), str.begin() + str.size() / 2,
                          str.rbegin());
    };
    const int n = str.length();
    if (n == 1 || check_palindrome(str)) {
        return 0;
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, INF));
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 0;
    }
    for (int i = 0; i < n; ++i) {
        dp[i][2] = check_palindrome(str.substr(i, 2)) ? 0 : 1;
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            if (check_palindrome(str.substr(i, len))) {
                dp[i][len] = 0;
                continue;
            }
            for (int sep = 1; sep <= len; ++sep) {
                dp[i][len] = std::min(dp[i][len],
                                      dp[i][sep] + dp[i + sep][len - sep] + 1);
            }
            // printf("%s: for %s dp[%d][%d] = %d\n", __func__,
            // str.substr(i, len).c_str(), i, len, dp[i][len]);
        }
    }

    return dp[0][n];
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string str;
    std::getline(std::cin, str);
    printf("str = %s\n", str.c_str());
    printf("%s: Solution = %d\n", __func__, Solve(str));
    printf("%s: Solution Optimised = %d\n", __func__, SolveOptimised(str));
    return 0;
}

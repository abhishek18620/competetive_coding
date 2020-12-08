// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto INF = 1e9 + 9;

// problem 18. nice little dp ;)
std::pair<int, int> FindContigousSet(const std::vector<int>& preamble,
                                     const int N, const int target) {
    std::pair<int, int>           sol;
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));

    for (int i = 0; i < N; ++i) {
        dp[i][1] = preamble[i];
    }
    for (int st = 0; st < N; st++) {
        for (int len = 2; len < N - st + 1; ++len) {
            dp[st][len] = dp[st][len - 1] + preamble[st + len - 1];
            if (dp[st][len] == target) {
                return {st, len};
            }
        }
    }
    return sol;
}

// problem 17
bool Solve(const std::vector<int>& preamble, int start, int end,
           const int target) {
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end; ++j) {
            if (i == j) {
                continue;
            }
            if (preamble[i] + preamble[j] == target) {
                return true;
            }
        }
    }

    return false;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::vector<int> preamble(25);
    int              x;
    int              start      = 0;
    int              faulty_idx = -1;
    int              faulty_ele = -1;
    for (auto& ele : preamble) {
        scanf("%d", &ele);
    }
    while (scanf("%d", &x)) {
        if (!Solve(preamble, start, start + 25, x)) {
            faulty_idx = preamble.size();
            faulty_ele = x;
            break;
        }
        preamble.push_back(x);
        start++;
    }
    printf("%s: faulty_ele %d at %d\n", __func__, faulty_ele, faulty_idx);
    auto sol = FindContigousSet(preamble, faulty_idx, faulty_ele);
    printf("%s: %d %d\n", __func__, sol.first, sol.second);
    auto sol_sum =
        *(std::max_element(preamble.begin() + sol.first,
                           preamble.begin() + sol.first + sol.second)) +
        (*std::min_element(preamble.begin() + sol.first,
                           preamble.begin() + sol.first + sol.second));
    printf("%s: sol_sum = %d\n", __func__, sol_sum);

    return 0;
}

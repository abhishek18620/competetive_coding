// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto INF = 1e9 + 9;

bool Solve(const std::vector<int>& preamble, int start, int end,
           const int target) {
    // printf("start = %d end = %d\n", start, end);
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end; ++j) {
            if (i == j) {
                continue;
            }
            if (preamble[i] + preamble[j] == target) {
                // printf("%s: target = %d = %d + %d\n", __func__, target,
                // preamble[i], preamble[j]);
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
    int              start = 0;
    for (auto& ele : preamble) {
        scanf("%d", &ele);
    }
    while (scanf("%d", &x)) {
        if (!Solve(preamble, start, start + 25, x)) {
            printf("%s: Wrong element : %d\n", __func__, x);
            break;
        }
        preamble.push_back(x);
        start++;
    }

    return 0;
}

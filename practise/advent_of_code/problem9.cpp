// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto INF = 1000;

long long Solve(const std::string& str) {
    int row_min = 0;
    int row_max = 127;
    int row_mid;
    int col_min = 0;
    int col_max = 7;
    int col_mid;
    auto pos1 = str.find('R');
    auto pos2 = str.find('L');
    pos1 = pos1 == std::string::npos ? INF : pos1;
    pos2 = pos2 == std::string::npos ? INF : pos2;
    auto pos = std::min(pos1, pos2);
    for (int idx = 0; idx < pos; ++idx) {
        row_mid = row_min + ((row_max - row_min) >> 1);
        if (str[idx] == 'F') {
            row_max = row_mid;
        } else {
            row_min = row_mid + 1;
        }
        // printf("%c: row_min = %d  row_max = %d\n", str[idx], row_min, row_max);
    }
    for (int idx = pos; idx < str.length(); ++idx) {
        col_mid = col_min + ((col_max - col_min) >> 1);
        if (str[idx] == 'L') {
            col_max = col_mid;
        } else {
            col_min = col_mid + 1;
        }
        // printf("%c: col_min = %d  col_max = %d\n", str[idx], col_min, col_max);
    }

    // printf("seats (%d, %d)\n", row_max, col_max);
    return 1LL* (row_max * 8 + col_max);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    long long   sol = -1;
    std::string str;
    while (std::getline(std::cin, str)) {
        printf("str = %s\n", str.c_str());
        sol = std::max<long long> (sol, Solve(str));
    }

    printf("%s: solution = %lld\n", __func__, sol);

    return 0;
}

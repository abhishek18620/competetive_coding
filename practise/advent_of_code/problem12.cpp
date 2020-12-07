// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

int Solve(const std::string& str, const int group_cnt) {
    int cnt = 0;
    for (int i = 0; i <= 25; i++) {
        char ch = 'a' + i;
        if (std::count(str.begin(), str.end(), ch) == group_cnt) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    long long   sol = 0;
    std::string str1, str2;
    int group_cnt = 0;
    while (std::getline(std::cin, str2)) {
        if (str2.empty()) {
            // printf("str1 = %s\n", str1.c_str());
            sol += Solve(str1, group_cnt);
            str1.clear();
            group_cnt = 0;
            continue;
        }
        group_cnt++;
        str1 += str2;
    }
    printf("%s: solution = %lld\n", __func__, sol);

    return 0;
}

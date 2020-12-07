// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<bool> present(26, false);

int Solve(const std::string& str) {
    int cnt = 0;
    for (auto ch : str) {
        if (!present[ch - 'a']) {
            present[ch - 'a'] = true;
            cnt++;
        }
        if (cnt == 26) {
            return 26;
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
    while (std::getline(std::cin, str2)) {
        if (str2.empty()) {
            printf("str1 = %s\n", str1.c_str());
            sol += Solve(str1);
            str1.clear();
            std::fill(present.begin(), present.end(), false);
            continue;
        }
        str1 += str2;
    }

    printf("%s: solution = %lld\n", __func__, sol);

    return 0;
}

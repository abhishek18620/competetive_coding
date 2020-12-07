// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto VALID_MASK1 = 255;
constexpr auto VALID_MASK2 = 127;

const std::unordered_map<std::string, int> field_idx_map = {
    {"byr", 0}, {"iyr", 1}, {"eyr", 2}, {"hgt", 3},
    {"hcl", 4}, {"ecl", 5}, {"pid", 6}, {"cid", 7},
};

bool ValidatePassport(const std::string& str) {
    int        mask = 0;
    std::regex word_regex("(\\w+)");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), word_regex);
    auto words_end   = std::sregex_iterator();
    std::string entry, field, val;
    size_t      pos;
    for (auto it = words_begin; it != words_end; ++it) {
        entry = it->str();
        pos   = entry.find(':');
        field = entry.substr(0, pos);
        val   = entry.substr(pos + 1, str.length() - pos - 1);
        if (field_idx_map.find(field) != field_idx_map.end()) {
            mask = (1 << field_idx_map.at(field)) | mask;
        }
    }

    return (mask == VALID_MASK1 || mask == VALID_MASK2);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::regex  word_regex("(\\w+:\\w+)");
    long long   sol = 0;
    std::string str1, str2;
    while (std::getline(std::cin, str2)) {
        if (str2.empty()) {
            str1.pop_back();
            printf("str1 = %s\n", str1.c_str());
            if (ValidatePassport(str1)) {
                sol++;
            }
            str1.clear();
            continue;
        }
        str1 += str2 + ' ';
    }

    printf("%s: solution = %lld\n", __func__, sol);

    return 0;
}

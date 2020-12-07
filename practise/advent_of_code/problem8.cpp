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

const std::unordered_map<std::string, std::string> field_regex_map = {
    {"byr", "(19[2-9][0-9]|200[0-2])"},
    {"iyr", "(201[0-9]|2020)"},
    {"eyr", "(202[0-9]|2030)"},
    {"hgt", "((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)"},
    {"hcl", "(#(\\w{6}))"},
    {"ecl", "(amb|blu|brn|gry|grn|hzl|oth)"},
    {"pid", "(\\d{9})"},
    {"cid", "(\\d+)"},
};

bool ValidatePassport(const std::string& str) {
    int        mask = 0;
    std::regex word_regex("(\\w+:[0-9|a-z|A-Z|#]\\w+)");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), word_regex);
    auto words_end   = std::sregex_iterator();
    std::string entry, field, val;
    size_t      pos;
    std::cmatch m;
    std::cout << std::distance(words_begin, words_end) << std::endl;
    for (auto it = words_begin; it != words_end; ++it) {
        entry = it->str();
        pos   = entry.find(':');
        field = entry.substr(0, pos);
        val   = entry.substr(pos + 1, entry.length() - pos - 1);
        if (field_idx_map.find(field) != field_idx_map.end()) {
            if (std::regex_match(val.c_str(), m,
                                 std::regex(field_regex_map.at(field)))) {
                mask = (1 << field_idx_map.at(field)) | mask;
            } // else {
              // printf("Failed at %s val = %s\n", field.c_str(), val.c_str());
            // }
        }
    }
    return (mask == VALID_MASK1 || mask == VALID_MASK2);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    long long   sol = 0;
    std::string str1, str2;
    while (std::getline(std::cin, str2)) {
        if (str2.empty()) {
            str1.pop_back();
            // printf("str1 = %s\n", str1.c_str());
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

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> Solve(std::vector<std::string>& dict,
                               const std::string&        pattern) {
    std::vector<std::string>       sol;
    std::unordered_map<char, char> char_map;
    for (const auto& str : dict) {
        if (str.length() != pattern.length()) {
            continue;
        }
        bool match = true;
        char_map.clear();
        for (int i = 0; i < str.length(); ++i) {
            if (char_map.find(pattern[i]) == char_map.end()) {
                char_map[pattern[i]] = str[i];
            } else if (char_map.at(pattern[i]) != str[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            printf("%s: matched %s\n", __func__, str.c_str());
            sol.emplace_back(str);
        }
    }
    return sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    std::vector<std::string> dict(n);
    std::string              pattern;
    for (auto& ele : dict) {
        std::cin >> ele;
    }
    std::cin >> pattern;
    auto sol = Solve(dict, pattern);
    printf("%s: solution \n", __func__);
    for (auto str : sol) {
        printf("%s ", str.c_str());
    }
    printf("\n");
    return 0;
}

// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, int> field_map = {
    {"departure location", 1},
    {"departure station", 2},
    {"departure platform", 3},
    {"departure track", 4},
    {"departure date", 5},
    {"departure time", 6},
    {"arrival location", 7},
    {"arrival station", 8},
    {"arrival platform", 9},
    {"arrival track", 10},
    {"class", 11},
    {"duration", 12},
    {"price", 13},
    {"route", 14},
    {"row", 15},
    {"seat", 16},
    {"train", 17},
    {"type", 18},
    {"wagon", 19},
    {"zone", 20},
};

// format: \\d-\\d
auto get_ranges = [](const std::string& str) -> std::pair<int, int> {
    auto pos = str.find('-');
    return {std::stoi(str.substr(0, pos)),
            std::stoi(str.substr(pos + 1, str.length() - pos - 1))};
};

auto fill_valid_ranges = [](std::vector<bool>& arr, const int min,
                            const int max) {
    if (arr.size() <= max) {
        arr.resize(max + 1);
    }
    std::fill(arr.begin() + min, arr.begin() + max + 1, true);
};

// 1,2,3 comma separated list
auto get_tickets = [](const std::string& str) {
    std::vector<int> ret;
    std::regex       word_regex("(\\d+)");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), word_regex);
    auto words_end   = std::sregex_iterator();
    for (auto it = words_begin; it != words_end; ++it) {
        ret.push_back(std::stoi(it->str()));
        // printf("%s ", it->str().c_str());
    }
    // printf("\n");

    return ret;
};

int Solve(const std::vector<int>& starting_nums) { return 0; }

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string                   str;
    bool                          tickets_hit     = false;
    bool                          self_ticket_hit = false;
    std::vector<bool>             valid_num;
    std::vector<int>              self_ticket;
    std::vector<std::vector<int>> nearby_tickets;
    while (std::getline(std::cin, str)) {
        if (tickets_hit) {
            // printf("nearby tickets : %s\n", str.c_str());
            nearby_tickets.push_back(get_tickets(str));
            continue;
        }
        if (self_ticket_hit) {
            self_ticket = get_tickets(str);
            continue;
        }
        if (str == "your_ticket:") {
            self_ticket_hit = true;
            continue;
        }
        if (str == "nearby tickets:") {
            tickets_hit = true;
            continue;
        }
        // ticket fields
        auto field = str.substr(0, str.find(':'));
        if (field_map.find(field) != field_map.end()) {
            // printf("Getting ranges for field : %s\n", field.c_str());
            std::regex word_regex("(\\d+\\-\\d+)");
            auto       words_begin =
                std::sregex_iterator(str.begin(), str.end(), word_regex);
            auto words_end = std::sregex_iterator();
            for (auto it = words_begin; it != words_end; ++it) {
                auto pai = get_ranges(it->str());
                // printf("%d-%d, ", pai.first, pai.second);
                fill_valid_ranges(valid_num, pai.first, pai.second);
            }
            // printf("\n");
        }
    }

    // traverse each freakig value in each ticket like a noob
    int sol = 0;
    printf("valid_num sz = %d\n", (int)valid_num.size());
    for (auto& ticket : nearby_tickets) {
        for (auto val : ticket) {
            if (val > valid_num.size() || !valid_num[val]) {
                sol += val;
            }
        }
    }
    printf("sol = %d\n", sol);
    return 0;
}

// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <bitset>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, int> field_map = {
    {"departure location", 0},
    {"departure station", 1},
    {"departure platform", 2},
    {"departure track", 3},
    {"departure date", 4},
    {"departure time", 5},
    {"arrival location", 6},
    {"arrival station", 7},
    {"arrival platform", 8},
    {"arrival track", 9},
    {"class", 10},
    {"duration", 11},
    {"price", 12},
    {"route", 13},
    {"row", 14},
    {"seat", 15},
    {"train", 16},
    {"type", 17},
    {"wagon", 18},
    {"zone", 19},
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
    // printf("%s: ", __func__);
    for (auto it = words_begin; it != words_end; ++it) {
        ret.push_back(std::stoi(it->str()));
        // printf("%d ", std::stoi(it->str()));
    }
    // printf("\n");

    return ret;
};

void ResolveValidTickets(
    int& mask, const int val,
    const std::vector<std::vector<std::pair<int, int>>>& ranges,
    std::vector<int>                                     blacklisted_indices) {
    // if (val == 850)
    // printf("checking for val %d\n", val);
    for (int i = 0; i < 20; ++i) {
        if (std::count(blacklisted_indices.begin(), blacklisted_indices.end(),
                       i) ||
            !(mask & (1 << (i - 1)))) {
            continue;
        }
        bool valid = false;
        for (auto& range : ranges[i]) {
            if (val >= range.first && val <= range.second) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            mask &= ~(1 << i);
            // printf("Unsetting %d bit from mask\n", i);
        }
        // if (val == 850)
        // printf(
        //    "%d: checking for %d ranges {[%d, %d], [%d, %d]} validity:%d\n",
        //    i, val, ranges[i][0].first, ranges[i][0].second,
        // ranges[i][1].first, ranges[i][1].second, valid ? 1 : 0);
    }
}

int Solve(const std::vector<int>& starting_nums) { return 0; }

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    std::string                                   str;
    bool                                          tickets_hit = false;
    std::vector<bool>                             valid_num;
    std::vector<int>                              self_ticket;
    std::vector<std::vector<int>>                 nearby_tickets;
    std::vector<std::vector<std::pair<int, int>>> ranges(20);
    while (std::getline(std::cin, str)) {
        if (tickets_hit) {
            // printf("nearby tickets : %s\n", str.c_str());
            nearby_tickets.push_back(get_tickets(str));
            continue;
        }
        if (str == "your ticket:") {
            std::getline(std::cin, str);
            self_ticket = get_tickets(str);
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
                ranges[field_map.at(field)].push_back(pai);
                // printf("%d-%d, ", pai.first, pai.second);
                fill_valid_ranges(valid_num, pai.first, pai.second);
            }
            // printf("\n");
        }
    }
    // traverse each freakig value in each ticket like a noob
    int sol = 0;
    printf("valid_num sz = %d\n", (int)valid_num.size());
    std::vector<std::vector<int>> valid_tickets;
    valid_tickets.push_back(self_ticket);
    for (auto& ticket : nearby_tickets) {
        bool valid = true;
        for (auto val : ticket) {
            if (val > valid_num.size() || !valid_num[val]) {
                sol += val;
                valid = false;
                break;
            }
        }
        if (valid) {
            valid_tickets.push_back(ticket);
        }
    }
    // for (auto& ticket : valid_tickets) {
    // for (int i = 0; i < 19; ++i) {
    //    printf("%d,", ticket[i]);
    //}
    // printf("%d\n", ticket[19]);
    //}
    printf("valid tickets sz = %d\n", (int)valid_tickets.size());

    for (int i = 0; i < 20; ++i) {
        for (int fld_idx = i; fld_idx < i + 1; ++fld_idx) {
            int mask = (1 << 20) - 1;
            // mask &= ~(1 << (1 - 1));
            for (auto& ticket : valid_tickets) {
                ResolveValidTickets(mask, ticket[fld_idx], ranges, {});
            }
            std::bitset<20> bs(mask);
            printf("fld_idx = %d mask = %d [%s]\n", fld_idx, mask,
                   bs.to_string().c_str());
        }
    }
    printf("sol = %d\n", sol);
    return 0;
}

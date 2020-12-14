// https://adventofcode.com/2020/day/1
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<unsigned long long int>
CalculateBitOP(const std::string& mask, const std::string& val,
               const std::vector<int>& floating_indices_list) {
    std::vector<unsigned long long int> ret;
    std::string                         out;
    const int num_floating = floating_indices_list.size();
    for (int i = 0; i < mask.length(); ++i) {
        if (mask[i] == '0') {
            out += val[i];
        } else if (mask[i] == '1') {
            out += '1';
        } else {
            out += 'X';
        }
    }
    // printf("ret_val = %s\n", out.c_str());
    int         max_bits = 1 << num_floating;
    std::string curr_idx_mask;
    for (int val = 0; val < max_bits; ++val) {
        curr_idx_mask = out;
        for (int idx = 0; idx < num_floating; ++idx) {
            // check if ith bit is set
            curr_idx_mask[floating_indices_list[idx]] = '0';
            if (val & (1 << idx)) {
                // printf("idx = %d idx of %d\n", idx,
                // floating_indices_list[idx]);
                curr_idx_mask[floating_indices_list[idx]] = '1';
            }
        }
        ret.push_back((std::bitset<36>(curr_idx_mask)).to_ullong());
        // printf("comb : %llu\n",
        // (std::bitset<36>(curr_idx_mask)).to_ullong());
    }
    // printf("ret_val = %llu\n", (std::bitset<36> (out)).to_ullong());
    return ret;
}

// 000000000000000000000000000001001001
// 000000000000000000000000000001001001
// 012345678911 12 13 14 15 16
// mem[24644]   =     1  1  6
auto get_floating_indices = [](const std::string& mask) {
    std::vector<int> indices;
    for (int i = 0; i < mask.length(); ++i) {
        if (mask[i] == 'X') {
            indices.push_back(i);
        }
    }
    return indices;
};

void Solve(
    std::unordered_map<unsigned long long int, unsigned long long int>& mem_map,
    const std::vector<
        std::pair<unsigned long long int, unsigned long long int>>& indices,
    const std::string                                               mask) {
    if (indices.empty()) {
        return;
    }
    auto floating_indices_list = get_floating_indices(mask);
    for (auto [idx, val] : indices) {
        std::bitset<36> idx_bs(idx);
        // printf("mask: %s idx = %s\n", mask.c_str(),
        // idx_bs.to_string().c_str());
        auto mem_map_indices =
            CalculateBitOP(mask, idx_bs.to_string(), floating_indices_list);
        for (auto& index : mem_map_indices) {
            mem_map[index] = val;
        }
    }
    return;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string str, mask;
    std::unordered_map<unsigned long long int, unsigned long long int> mem_map;
    std::vector<std::pair<unsigned long long int, unsigned long long int>>
        indices;
    while (std::getline(std::cin, str)) {
        if (str.find("mask") != std::string::npos) {
            Solve(mem_map, indices, mask);
            mask = str.substr(7, 36);
            printf("mask = %s\n", mask.c_str());
            indices.clear();
            continue;
        }
        auto idx = std::stoull(
            str.substr(str.find('[') + 1, str.find(']') - str.find('[') - 1));
        auto val = std::stoull(
            str.substr(str.find('=') + 2, str.length() - str.find('=') - 2));
        indices.push_back({idx, val});
        // printf("idx = %llu val = %u\n", idx, val);
    }
    Solve(mem_map, indices, mask);
    unsigned long long int sol = 0;
    for (auto [idx, val] : mem_map) {
        sol += val;
        printf("sol = %llu\n", sol);
    }
    printf("sol = %llu\n", sol);
    return 0;
}


// https://adventofcode.com/2020/day/1
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


auto get_occ = [](std::unordered_map<int, std::pair<int, int>>& numbers_map, int ele) {
    if (numbers_map.find(ele) == numbers_map.end()) {
        return 0;
    }
    if (numbers_map.at(ele).second == -1) {
        return 1;
    }
    return 2;
};

void Solve(const std::vector<int>& starting_nums) {
    std::unordered_map<int, std::pair<int, int>> numbers_map;
    std::vector<int> turn;
    for (int i = 0; i < starting_nums.size(); ++i) {
        numbers_map[starting_nums[i]] = {i+1, -1};
    }
    int curr_turn = starting_nums.size();
    int last_num = starting_nums[starting_nums.size() - 1];

    // Simulate game
    while (curr_turn++ != 2020) {
        int occ = get_occ(numbers_map, last_num);
        if (occ == 1) {
            last_num = 0;
        } else {
            // occ > 1
            last_num = numbers_map.at(last_num).second - numbers_map.at(last_num).first;
        }
        printf("curr_turn = %d last_num = %d\n", curr_turn, last_num);

        occ = get_occ(numbers_map, last_num);
        if (occ == 0) {
            numbers_map[last_num] = {curr_turn , -1};
        } else if (occ == 1) {
            numbers_map.at(last_num).second = curr_turn;
        } else {
            std::swap(numbers_map.at(last_num).first, numbers_map.at(last_num).second);
            numbers_map.at(last_num).second = curr_turn;
        }
        // printf("last f = %d s = %d\n", numbers_map.at(last_num).first, numbers_map.at(last_num).second);
    }

}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    Solve({15, 5, 1, 4, 7, 0});
    return 0;
}


// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int Solve(const std::vector<std::vector<bool>>& grid, const int x,
          const int y) {
    int       sol         = 0;
    const int max_row_idx = grid[0].size();
    for (int curr_row = x, curr_col = y; curr_row < grid.size();
         curr_col += y, curr_row += x) {
        if (!grid[curr_row][curr_col % max_row_idx]) {
            sol++;
        }
    }

    return sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    long long                      sol = 1;
    std::string                    str;
    std::vector<std::vector<bool>> grid(323, std::vector<bool>(31));
    for (auto& row : grid) {
        std::getline(std::cin, str);
        // printf("%s\n", str.c_str());
        for (int idx = 0; idx < str.length(); ++idx) {
            row[idx] = str[idx] == '.';
        }
    }
    const std::vector<std::pair<int, int>> slopes = {
        {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

    for (auto& [y, x] : slopes) {
        printf("solution for (%d, %d) = %d\n", y, x, Solve(grid, x, y));
        sol *= Solve(grid, x, y);
    }

    printf("%s: solution = %lld\n", __func__, sol);

    return 0;
}

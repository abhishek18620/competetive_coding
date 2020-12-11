// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <vector>

auto is_empty_seat1 = [](int x, int y, int M, int N) {
    if (x == M || y == N || x < 0 || y < 0) { // empty seat
        return true;
    }

    return false;
};

auto is_empty_seat2 = [](int x, int y, int M, int N) {
    if (x == M || y == N || x < 0 || y < 0) { // empty seat
        return false;
    }

    return true;
};

void PrintSeatMatrix(const std::vector<std::string>& grid) {
    for (auto& row : grid) {
        printf("%s\n", row.c_str());
    }
}

int CalculateOccupiedSeats(const std::vector<std::string>& grid) {
    int ret_cnt = 0;
    for (auto& row : grid) {
        ret_cnt += std::count(row.begin(), row.end(), '#');
    }
    return ret_cnt;
}

std::vector<std::string> SimulateRules(const std::vector<std::string>& grid,
                                       int& changes) {
    auto ret_grid = grid;
    int  M        = grid.size();
    int  N        = grid[0].size();
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == '.') {
                continue;
            }
            // Empty seat
            if (grid[i][j] == 'L') {
                // up
                if ((is_empty_seat1(i - 1, j, M, N) || grid[i - 1][j] != '#') &&
                    (is_empty_seat1(i + 1, j, M, N) || grid[i + 1][j] != '#') &&
                    (is_empty_seat1(i, j - 1, M, N) || grid[i][j - 1] != '#') &&
                    (is_empty_seat1(i, j + 1, M, N) || grid[i][j + 1] != '#') &&
                    (is_empty_seat1(i - 1, j + 1, M, N) ||
                     grid[i - 1][j + 1] != '#') &&
                    (is_empty_seat1(i - 1, j - 1, M, N) ||
                     grid[i - 1][j - 1] != '#') &&
                    (is_empty_seat1(i + 1, j + 1, M, N) ||
                     grid[i + 1][j + 1] != '#') &&
                    (is_empty_seat1(i + 1, j - 1, M, N) ||
                     grid[i + 1][j - 1] != '#')) {
                    ret_grid[i][j] = '#';
                    changes++;
                }
            } else {
                int occupied = 0;
                if (is_empty_seat2(i - 1, j, M, N) && grid[i - 1][j] == '#') {
                    occupied++;
                }
                if (is_empty_seat2(i + 1, j, M, N) && grid[i + 1][j] == '#') {
                    occupied++;
                }
                if (is_empty_seat2(i, j - 1, M, N) && grid[i][j - 1] == '#') {
                    occupied++;
                }
                if (is_empty_seat2(i, j + 1, M, N) && grid[i][j + 1] == '#') {
                    occupied++;
                }
                if (is_empty_seat2(i - 1, j + 1, M, N) &&
                    grid[i - 1][j + 1] == '#') {
                    if (++occupied >= 4) {
                        ret_grid[i][j] = 'L';
                        changes++;
                        continue;
                    }
                }
                if (is_empty_seat2(i - 1, j - 1, M, N) &&
                    grid[i - 1][j - 1] == '#') {
                    if (++occupied >= 4) {
                        ret_grid[i][j] = 'L';
                        changes++;
                        continue;
                    }
                }
                if (is_empty_seat2(i + 1, j + 1, M, N) &&
                    grid[i + 1][j + 1] == '#') {
                    if (++occupied >= 4) {
                        ret_grid[i][j] = 'L';
                        changes++;
                        continue;
                    }
                }
                if (is_empty_seat2(i + 1, j - 1, M, N) &&
                    grid[i + 1][j - 1] == '#') {
                    if (++occupied >= 4) {
                        ret_grid[i][j] = 'L';
                        changes++;
                        continue;
                    }
                }
            }
        }
    }

    return ret_grid;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::vector<std::string> grid;
    std::string              str;
    while (std::getline(std::cin, str)) {
        grid.emplace_back(str);
        // printf("%s\n", str.c_str());
    }
    int                      changes      = -1;
    std::vector<std::string> updated_grid = grid;
    while (changes != 0) {
        changes      = 0;
        updated_grid = SimulateRules(updated_grid, changes);
        // printf("new round \n");
        // PrintSeatMatrix(updated_grid);
    }
    printf("%s: Solution = %d\n", __func__,
           CalculateOccupiedSeats(updated_grid));

    return 0;
}

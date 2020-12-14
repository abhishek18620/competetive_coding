// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

auto get_instr_arg = [](const std::string& str) -> std::pair<std::string, int> {
    auto pos = str.find(' ');
    return {str.substr(0, pos),
            std::stoi(str.substr(pos + 1, str.length() - pos - 1))};
};

void PrintVisited(const std::vector<bool>& visited) {
    for (auto val : visited) {
        printf("%d ", val ? 1 : 0);
    }
    printf("\n");
}

// problem16 : Find faulty index
bool SolveRecursively(
    const std::vector<std::pair<std::string, int>>& inst_arg_list,
    std::vector<bool>& visited, int curr, int& faulty_idx,
    bool already_changed) {
    // printf("curr = %d\n", curr);
    if (visited[curr]) {
        return false;
    }
    if (curr >= inst_arg_list.size() - 1) {
        return true;
    }

    visited[curr]           = true;
    auto              instr = inst_arg_list[curr].first;
    auto              arg   = inst_arg_list[curr].second;
    std::vector<bool> visited_copy;
    bool              res;
    // printf("%s : %d\n", instr.c_str(), arg);
    if (instr == "nop") {
        if (already_changed) {
            return SolveRecursively(inst_arg_list, visited, curr + 1,
                                    faulty_idx, already_changed);
        } else {
            visited_copy = visited;
            res = SolveRecursively(inst_arg_list, visited, curr + 1, faulty_idx,
                                   already_changed);
        }
        // try jmp
        if (SolveRecursively(inst_arg_list, visited_copy, curr + arg, curr,
                             !already_changed)) {
            printf("faulty_idx = %d\n", curr);
            return true;
        }
    } else if (instr == "acc") {
        res = SolveRecursively(inst_arg_list, visited, curr + 1, faulty_idx,
                               already_changed);
    } else { // jmp
        if (already_changed) {
            return SolveRecursively(inst_arg_list, visited, curr + arg,
                                    faulty_idx, already_changed);
        } else {
            visited_copy = visited;
            res          = SolveRecursively(inst_arg_list, visited, curr + arg,
                                   faulty_idx, already_changed);
        }
        // try nop
        if (SolveRecursively(inst_arg_list, visited_copy, curr + 1, curr,
                             !already_changed)) {
            printf("faulty_idx = %d\n", curr);
            return true;
        }
    }
    return res;
}

// problem 15 : Just Solve instructions without cycle
int Solve(const std::vector<std::pair<std::string, int>>& inst_arg_list) {
    int               N = inst_arg_list.size();
    std::vector<bool> visited(N, false);
    int               acc      = 0;
    int               last_idx = 0;
    for (int curr = 0; curr >= 0 && !visited[curr] && curr <= N;
         last_idx = curr) {
        last_idx      = curr;
        visited[curr] = true;
        auto instr    = inst_arg_list[curr].first;
        auto arg      = inst_arg_list[curr].second;
        // printf("%s : %d\n", instr.c_str(), arg);
        if (instr == "nop") {
            curr++;
        } else if (instr == "acc") {
            acc += arg;
            curr++;
        } else { // jmp
            curr += arg;
        }
    }
    if (last_idx > 670) {
        printf("last_idx = %d\n", last_idx);
    }
    return acc;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string                              str;
    std::vector<std::pair<std::string, int>> inst_arg_list;
    while (std::getline(std::cin, str)) {
        inst_arg_list.push_back(get_instr_arg(str));
    }
    printf("%s: solution = %d\n", __func__, Solve(inst_arg_list));
    int               faulty_idx = -1;
    std::vector<bool> visited(inst_arg_list.size(), false);
    SolveRecursively(inst_arg_list, visited, 0, faulty_idx,
                     false); // prints faulty index
    printf("faulty_idx = %d\n", faulty_idx);
    // return 0;
}

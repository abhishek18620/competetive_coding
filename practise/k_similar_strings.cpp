#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct State {
    std::string str;
    int         start_idx;
    int         dist;
};

int BFS(const std::string& src, const std::string& dest) {
    // lambda to return index of first different char in str1 & str2
    auto str_diff = [](const std::string& str1, const std::string& str2,
                       int index) {
        while (str1[index] == str2[index]) {
            index++;
        }
        return index;
    };

    std::unordered_set<std::string> visited;
    std::queue<State>               bfs_que;
    std::string                     tmp;
    bfs_que.push({src, 0, 0});
    visited.insert(src);
    while (!bfs_que.empty()) {
        auto u   = bfs_que.front().str;
        int  w   = bfs_que.front().dist;
        int  idx = bfs_que.front().start_idx;
        bfs_que.pop();
        if (u == dest) {
            return w;
        }
        idx = str_diff(u, dest, idx);
        for (int i = idx + 1; i < u.length(); ++i) {
            if (u[i] == dest[idx]) {
                tmp = u;
                std::swap(tmp[i], tmp[idx]);
                if (visited.count(tmp) == 0) {
                    bfs_que.push({tmp, idx + 1, w + 1});
                    visited.insert(tmp);
                }
            }
        }
    }
    return -1;
}

int Solve(const std::string str1, const std::string str2) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    return BFS(str1, str2);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string str1, str2;
    std::cin >> str1 >> str2;
    printf("%s: str1 = %s str2 = %s\n", __func__, str1.c_str(), str2.c_str());
    printf("%s: solution = %d\n", __func__, Solve(str1, str2));
    return 0;
}

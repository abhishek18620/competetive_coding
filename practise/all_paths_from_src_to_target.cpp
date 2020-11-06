#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::vector<int>>
FindVertex(const std::vector<std::vector<int>>& graph, const int src,
           const int des) {
    std::vector<std::vector<int>> paths;
    if (src == des) {
        return paths = {{src}};
    }
    for (int i = 0; i < graph[src].size(); ++i) {
        auto paths_from_i = FindVertex(graph, graph[src][i], des);
        if (paths_from_i.size() != 0) { // destination found
            for (auto& path : paths_from_i) {
                if (graph[src][i] != des) {
                    path.push_back(graph[src][i]);
                }
                paths.push_back(path);
            }
        }
    }

    return paths;
}

void PrintPath(const std::vector<int>& path) {
    for (auto v : path) {
        printf("%d ", v);
    }
    printf("\n");
}

std::vector<std::vector<int>>
Solve(const std::vector<std::vector<int>>& graph) {
    int                           vertices = graph.size();
    std::vector<std::vector<int>> paths;
    std::vector<bool>             visited(vertices, false);

    for (int i = 0; i < graph[0].size(); ++i) {
        std::vector<int> path;
        auto paths_from_i = FindVertex(graph, graph[0][i], vertices - 1);
        if (paths_from_i.size() != 0) {
            for (auto& path : paths_from_i) {
                if (graph[0][i] != vertices - 1) {
                    path.push_back(graph[0][i]);
                }
                path.push_back(0);
                std::reverse(path.begin(), path.end());
                paths.push_back(path);
                PrintPath(path);
            }
        }
    }
    return paths;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int vertices, edges, u, v;
    scanf("%d %d", &vertices, &edges);
    std::vector<std::vector<int>> graph(vertices);
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    auto paths = Solve(graph);
    return 0;
}

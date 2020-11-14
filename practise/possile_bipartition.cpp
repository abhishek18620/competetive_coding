// https://leetcode.com/problems/possible-bipartition/
#include <iostream>
#include <queue>
#include <string>
#include <vector>

bool IsBipartite(int N, const std::vector<std::vector<int>>& graph) {
    /*
     * Color the vertices
     * 'R' = red
     * 'B' = blue
     * 'U' = Uncolored
     */
    std::vector<bool> visited(N + 1, false);
    std::vector<char> colours(N + 1, 'U');
    // lambda to color vertices
    auto color_vertex = [](const char& color) {
        return (color == 'R') ? 'B' : 'R';
    };

    int             u;
    char            u_color;
    char            v_color;
    std::queue<int> bfs_que;
    for (int vertex = 1; vertex <= N; ++vertex) {
        if (visited[vertex]) { // vertex already visited
            continue;
        }
        // BFS routine
        bfs_que.push(vertex);
        colours[vertex] = 'R'; // choose the red color for the first vexrtex
        while (!bfs_que.empty()) {
            u          = bfs_que.front();
            visited[u] = true;
            bfs_que.pop();
            u_color = colours[u];
            v_color = color_vertex(u_color);
            //            printf(
            //"%s: Visiting vertex %d with color %c neighbours should be "
            //"colored %c\n",
            //    __func__, u, u_color, v_color);
            for (auto& v : graph[u]) {
                if (colours[v] == u_color) { // if the neighbour is already
                                             // colored same as u
                    return false;
                }
                if (!visited[v]) { // v has't been visited yet
                    bfs_que.push(v);
                    if (colours[v] == 'U') {
                        colours[v] = v_color; // color the uncolored neighbour
                    }
                }
            }
        }
    }

    return true;
}

bool Solve(int N, std::vector<std::vector<int>>& dislikes) {
    std::vector<std::vector<int>> graph(N + 1);
    for (auto& edge : dislikes) {
        // undirected as luckily hate is mutual, avoid conflicts and
        // stalkers;)
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return IsBipartite(N, graph);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int vertices, edges, u, v;
    scanf("%d %d", &vertices, &edges);
    printf("vertices = %d  edges = %d\n", vertices, edges);
    std::vector<std::vector<int>> edges_list(edges, std::vector<int>(2));
    for (auto& edge : edges_list) {
        scanf("%d %d", &u, &v);
        edge[0] = u;
        edge[1] = v;
    }
    printf("%s: solution = %s\n", __func__,
           Solve(vertices, edges_list) ? "true" : "false");

    return 0;
}

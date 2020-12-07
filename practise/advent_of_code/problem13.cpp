// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

constexpr auto INF = 1e9 + 9;

/// TODO: Graph formed now try to just find number of ways to reach shiny gold
// vertex
std::unordered_map<std::string, int> color_map;

auto get_color = [](const std::string& str) {
    return str.substr(0, str.find("bag") - 1);
};

// problem 13
int WaysToReachVertex(
    const std::vector<std::vector<std::pair<int, int>>>& graph, const int v) {
    int                           sol      = 0;
    const int                     vertices = graph.size();
    std::vector<std::vector<int>> graph_matrix(vertices,
                                               std::vector<int>(vertices, INF));
    for (int u = 0; u < vertices; ++u) {
        graph_matrix[u][u] = 0;
        // printf("%d ", u);
        for (auto [v, dis] : graph[u]) {
            // printf("edge(--> %d )", v);
            graph_matrix[u][v] = dis;
        }
        // printf("\n");
    }
    // johnson's algo
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                graph_matrix[i][j] =
                    std::min(graph_matrix[i][j],
                             graph_matrix[i][k] + graph_matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < vertices; ++i) {
        printf("graph[%d][%d] = %d\n", v, i, graph_matrix[v][i]);
        if (graph_matrix[v][i] != INF) {
            sol++;
        }
    }

    return sol - 1; // avoid self edge
}

int DFS(const std::vector<std::vector<std::pair<int, int>>>& graph, int u) {
    int sol = 1;
    for (auto [v, dis] : graph[u]) {
        sol += dis * DFS(graph, v);
    }
    return sol;
}

// problem 14
int TotalBags(const std::vector<std::vector<std::pair<int, int>>>& graph,
              const int                                            v) {
    const int vertices = graph.size();
    int       sol      = 0;

    std::vector<int> sink_vertices;
    for (int i = 0; i < vertices; ++i) {
        if (graph[i].size() == 0) {
            sink_vertices.push_back(i);
        }
    }
    return DFS(graph, v);
    // for (auto vertex : graph[v]) {
    // int              sol = 0;
    // std::vector<int> visited(vertices, false);
    // std::stack<int>  st;
    // st.push(vertex.first);
    // while(!st.empty()) {
    //    int u = st.top();
    //    st.pop();
    //    visited[u] = true;
    //    for (auto [k, dis] : graph[u]) {
    //    }
    //}
    //}

    return sol;
}

void FormColorVertex(std::vector<std::pair<int, int>>& edge_list,
                     const std::string& u, std::string str) {
    std::regex re("(\\d\\s[a-zA-z ]*[,|.])");
    // printf("%s:%s\n", u.c_str(), str.c_str());
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto words_end   = std::sregex_iterator();
    for (auto i = words_begin; i != words_end; ++i) {
        std::string part = (*i).str();
        part.pop_back();
        // printf("%s ", part.c_str());
        std::string color = part.substr(part.find(' ') + 1,
                                        part.find("bag") - part.find(' ') - 2);

        int edge_length = std::stoi(part.substr(0, ' '));
        // printf("%s: %d:%s\n", part.c_str(), edge_length, color.c_str());
        edge_list.push_back({color_map.at(color), edge_length});
    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string                                      str;
    std::string                                      color;
    int                                              idx = 0;
    std::vector<std::pair<std::string, std::string>> edge_list;
    while (std::getline(std::cin, str)) {
        color = get_color(str);
        if (color_map.find(color) == color_map.end()) {
            color_map[color] = idx++;
        }
        auto contain_pos = str.find("contain");
        auto edge_part =
            str.substr(contain_pos + 8, str.length() - contain_pos - 8);
        // printf("%s:%s\n", color.c_str(), edge_part.c_str());
        edge_list.push_back({color, edge_part});
    }
    // printf("map as follows\n");
    // for (auto [u, v] : color_map) {
    //    printf("u = %s, %d\n", u.c_str(), v);
    //}

    std::vector<std::vector<std::pair<int, int>>> color_graph(color_map.size());
    for (auto [u, edge_part] : edge_list) {
        FormColorVertex(color_graph[color_map.at(u)], u, edge_part);
    }

    printf("%s: solution = %d\n", __func__,
           TotalBags(color_graph, color_map.at("shiny gold")) - 1);
    return 0;
}

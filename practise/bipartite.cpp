// https://leetcode.com/problems/is-graph-bipartite/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#if defined(DEBUG)
#include <algorithm>

void PrintColoredSets(const std::unordered_map<int, char>& color_map) {
  std::vector<int> color_one;
  std::vector<int> color_two;
  for (auto& pai : color_map) {
    if (pai.second == 'R') {
      color_one.emplace_back(pai.first);
    } else {
      color_two.emplace_back(pai.first);
    }
  }

  std::sort(color_one.begin(), color_one.end());
  std::sort(color_two.begin(), color_two.end());

  printf("%s two sets are as follows:\n", __func__);
  for (auto& v : color_one) {
    printf("%d  ", v);
  }
  printf("\n");
  for (auto& v : color_two) {
    printf("%d  ", v);
  }
  printf("\n");
}

void PrintColoredSetsFromList(const std::vector<char>& color_list) {
  std::vector<int> color_one;
  std::vector<int> color_two;
  for (int i = 0; i < color_list.size(); ++i) {
    char color = color_list[i];
    if (color == 'R') {
      color_one.emplace_back(i);
    } else {
      color_two.emplace_back(i);
    }
  }

  printf("%s two sets are as follows:\n", __func__);
  for (auto& v : color_one) {
    printf("%d  ", v);
  }
  printf("\n");
  for (auto& v : color_two) {
    printf("%d  ", v);
  }
  printf("\n");
}

#endif

void CreateGraph(const std::vector<std::pair<int, int>>& edges,
                 std::vector<std::vector<int>>&          graph) {
  for (auto& pai : edges) {
    graph[pai.first].emplace_back(pai.second);
    graph[pai.second].emplace_back(pai.first);
  }
}

bool Solve(std::vector<std::pair<int, int>>& edges) {
  /*
   * Color the vertices
   * 'R' = red
   * 'B' = blue
   * 'U' = Uncolored
   */
  std::unordered_map<int, char> color_map;
  for (auto& pai : edges) {
    color_map[pai.first] = color_map[pai.second] = 'U';
  }
  const int vertices = color_map.size();

  std::vector<bool>             visited(vertices);
  std::vector<std::vector<int>> graph(vertices);

  // lambda to color vertices
  auto color_vertex = [](const char& color) { return (color == 'R') ? 'B' : 'R'; };

  CreateGraph(edges, graph);
  int             u;
  char            u_color;
  char            v_color;
  std::queue<int> bfs_que;
  for (int vertex = 0; vertex < vertices; ++vertex) {
    if (visited[vertex]) { // vertex already visited
      continue;
    }
    // BFS routine
    bfs_que.push(vertex);
    color_map[vertex] = 'R'; // choose the red color for the first vexrtex
    while (!bfs_que.empty()) {
      u          = bfs_que.front();
      visited[u] = true;
      bfs_que.pop();
      u_color = color_map[u];
      v_color = color_vertex(u_color);
      printf("%s: Visiting vertex %d with color %c neighbours should be colored %c\n",
             __func__, u, u_color, v_color);
      for (auto& v : graph[u]) {
        if (color_map[v] == u_color) { // if the neighbour is already colored same as u
          return false;
        }
        if (!visited[v]) { // v has't been visited yet
          bfs_que.push(v);
          if (color_map[v] == 'U') {
            color_map[v] = v_color; // color the uncolored neighbour
          }
        }
      }
    }
  }
#if defined(DEBUG)
  PrintColoredSets(color_map);
#endif
  return true;
}

bool SolveOptimised(std::vector<std::pair<int, int>>& edges) {
  /*
   * Color the vertices
   * 'R' = red
   * 'B' = blue
   * 'U' = Uncolored
   */
  std::unordered_map<int, char> color_map;
  for (auto& pai : edges) {
    color_map[pai.first] = color_map[pai.second] = 'U';
  }

  const int vertices = color_map.size();

  std::vector<std::vector<int>> graph(vertices);

  // lambda to color vertices
  auto color_vertex = [](const char& color) { return (color == 'R') ? 'B' : 'R'; };

  CreateGraph(edges, graph);

  std::vector<char> color_list(vertices, 'U');
  std::vector<bool> visited(vertices);

  int             u;
  char            u_color;
  char            v_color;
  std::queue<int> bfs_que;
  for (int vertex = 0; vertex < vertices; ++vertex) {
    if (visited[vertex]) { // vertex already visited
      continue;
    }
    // BFS routine
    bfs_que.push(vertex);
    color_list[vertex] = 'R'; // choose the red color for the first vexrtex
    while (!bfs_que.empty()) {
      u          = bfs_que.front();
      visited[u] = true;
      bfs_que.pop();
      u_color = color_list[u];
      v_color = color_vertex(u_color);
      printf("%s: Visiting vertex %d with color %c neighbours should be colored %c\n",
             __func__, u, u_color, v_color);
      for (auto& v : graph[u]) {
        if (color_list[v] == u_color) { // if the neighbour is already colored same as u
          return false;
        }
        if (!visited[v]) { // v has't been visited yet
          bfs_que.push(v);
          if (color_list[v] == 'U') {
            color_list[v] = v_color; // color the uncolored neighbour
          }
        }
      }
    }
  }
#if defined(DEBUG)
  PrintColoredSetsFromList(color_list);
#endif
  return true;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int edges_cnt;
  scanf("%d", &edges_cnt);
  printf("%s: edges = %d\n", __func__, edges_cnt);
  std::vector<std::pair<int, int>> edges(edges_cnt);
  for (auto& pai : edges) {
    scanf("%d %d", &pai.first, &pai.second);
    printf("(%d %d)  ", pai.first, pai.second);
  }
  printf("\n");
  printf("%s: solution using Solve = %s\n", __func__, Solve(edges) ? "true" : "false");
  printf("%s: solution using SolveOptimised = %s\n", __func__,
         Solve(edges) ? "true" : "false");
  return 0;
}

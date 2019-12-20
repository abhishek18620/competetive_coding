// https://leetcode.com/problems/minimum-height-trees/
/*
 * The idea is to cut the vertices of the circumference(boundary nodes)
 * layer by layer until 2 or less vertices are left then.
 */
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#if 0
/**
 * @brief Returns height of the tree.
 */
static const int FindHeightDFS(const std::vector<std::vector<int>> &graph,
                               const int &src) {
  int height = 1;
  std::vector<bool> visited(graph.size());
  std::stack<std::pair<int, int>> dfs_stack; // {vertex, height}
  dfs_stack.push({src, 1});
  while (!dfs_stack.empty()) {
    const std::pair<int, int> pai = dfs_stack.top();
    dfs_stack.pop();
    visited[pai.first] = true;
    for (const int &vertex : graph[pai.first]) {
      if (!visited[vertex]) {
        // already visited
        dfs_stack.push({vertex, pai.second + 1});
        height = std::max(height, pai.second + 1);
        printf("%s: vertex = %d  level = %d\n", __func__, vertex,
               pai.second + 1);
      }
    }
  }
  return height;
}

/**
 * @brief Returns all vertices at the specified level in the tree.
 */
static std::vector<int> BFS(const std::vector<std::vector<int>> &graph,
                            const int &src, const int &level,
                            const bool &is_height_even = false) {
  std::vector<int> sol;
  std::vector<bool> visited(graph.size());
  std::queue<std::pair<int, int>> bfs_queue;
  bfs_queue.push({src, 1});
  while (!bfs_queue.empty()) {
    const std::pair<int, int> pai = bfs_queue.front();
    bfs_queue.pop();
    visited[pai.first] = true;
    if (pai.second == level || (is_height_even && pai.second == level + 1)) {
      sol.emplace_back(pai.first);
    }
    for (const int &vertex : graph[pai.first]) {
      if (!visited[vertex]) {
        // already visited
        bfs_queue.push({vertex, pai.second + 1});
      }
    }
  }
  return sol;
}
#endif

std::vector<int> Solve(const int &n,
                       const std::vector<std::pair<int, int>> &edge_list) {
  std::vector<std::vector<int>> graph(n);
  // form the graph
  for (int i = 0; i < n - 1; i++) {
    graph[edge_list[i].first].push_back(edge_list[i].second);
    graph[edge_list[i].second].push_back(edge_list[i].first);
  }

  std::vector<int> indegree(n);
  std::queue<int> one_indeg_que;
  for (int i = 0; i < n; i++) {
    indegree[i] = graph[i].size();
    if (graph[i].size() == 1) {
      // so to get the root to find the actual height of the tree
      one_indeg_que.push(i);
    }
  }
  int vertices = n;
  while (vertices > 2) {
    vertices -= one_indeg_que.size(); // remove the outermost layer
    int sz = one_indeg_que.size();
    int u;
    for (int i = 0; i < sz; i++) {
      u = one_indeg_que.front();
      one_indeg_que.pop();
      indegree[u] = 0; // remove the indegree of current vertex
      printf("%s: vertex to be considered: %d\n", __func__, u);
      for (const int &v : graph[u]) {
        indegree[v]--; // decrease its indegree
        if (indegree[v] == 1) {
          one_indeg_que.push(v);
        }
      }
    }
  }
  std::vector<int> sol;
  while (!one_indeg_que.empty()) {
    sol.push_back(one_indeg_que.front());
    one_indeg_que.pop();
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> edge_list(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &edge_list[i].first, &edge_list[i].second);
  }
  printf("%s: Input: n = %d\n", __func__, n);
  std::vector<int> sol = Solve(n + 1, edge_list);
  printf("%s: solution size =  %d\n", __func__, (int)sol.size());
  for (auto v : sol) {
    printf("%d  ", v);
  }
  printf("\n");
  return 0;
}

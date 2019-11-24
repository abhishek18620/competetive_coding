// https://leetcode.com/problems/course-schedule/
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string Solve(const std::vector<std::vector<int>>& graph) {
  std::stack<int> dfs_stack;
  int src = 0;
  dfs_stack.push(src);
  int vertices = graph.size();
  std::vector<int> visited(vertices, 0);
  int iter_cnt = 0;
  for(int i = 0; i < vertices; i++) {
    if(visited[i] != 0) {
      // ith vertex is already visited
      continue;
    }
    iter_cnt++;
    // DFS routine
    dfs_stack.push(i);
    visited[i] = iter_cnt;
    while(!dfs_stack.empty()) {
      int curr_vertex = dfs_stack.top();
      dfs_stack.pop();
      for(auto v : graph[curr_vertex]) {
        // edge curr_vertex ---> v
        if(visited[v] == iter_cnt) {
          // cycle detected
          return std::string("false");
        }
        else if(visited[v] == 0){
          // vertex has never been visited before
          dfs_stack.push(v);
          visited[v] = iter_cnt;
        }
        else {
          // vertex has been visited once but didn't give a cycle
          visited[v] = iter_cnt;
        }
      }
    }
  }
  return std::string("true");
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int vertices, edges;
  scanf("%d %d", &vertices, &edges);
  std::vector<std::vector<int>> graph(vertices);
  for(int i = 0; i < edges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v); // edge u->v
  }
  std::cout << Solve(graph) << std::endl;
  return 0;
}

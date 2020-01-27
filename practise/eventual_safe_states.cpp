// https://leetcode.com/problems/find-eventual-safe-states/
#include <algorithm> // for std::sort
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

// clang-format off
bool IsCyclic(const std::vector<std::vector<int>>& graph, std::vector<int>& visited, const std::vector<bool>& self_loops, const int& src,
              const int& iter_cnt, std::stack<int> dfs_stack, const std::unordered_set<int>& sink_vertices_set) {

  bool hit_a_sink_vertex = false;
  dfs_stack.push(src);
  int u;
  while(!dfs_stack.empty()) {
    u = dfs_stack.top();
    if(self_loops[u]) {
      printf("%s on %d: checking for %d but encountered a self loop on %d\n", __func__, __LINE__, src, u);
      return true;
    }
    if(!hit_a_sink_vertex && sink_vertices_set.find(u) != sink_vertices_set.end()) {
      printf("%s: checking for %d and hit a sink vertex %d", __func__, src, u);
        hit_a_sink_vertex = true;
    }
    dfs_stack.pop();
    visited[u] = iter_cnt;
    for(auto& v : graph[u]) {
      if(v == src) {
        // hit the src vertex again means we've encountered a cycle
        printf("%s on %d: found cycle for vertex %d\n", __func__, __LINE__, src);
        return true;
      }
      if(visited[v] != iter_cnt) { // not visited yet
        dfs_stack.push(v);
      }
    }
  }
  printf("%s on %d: found no cycle for vertex %d\n", __func__, __LINE__, src);
  return !hit_a_sink_vertex;
}

// Recursive one does not give right answer as hit_a_sink_vertex makes it a bit
// complicaated
bool IsCyclicRecursive(const std::vector<std::vector<int>>& graph,
                       std::vector<bool>& visited,
                       const int& src,
                       std::vector<bool>& recursion_st,
                       const std::unordered_set<int>& sink_vertices_set,
                       std::vector<int> is_involved_in_cycle,
                       bool& hit_a_sink_vertex) {
  if(visited[src]) {
    recursion_st[src] = false;
    return is_involved_in_cycle[src] == 1;
  }
    visited[src] = true;
    recursion_st[src] = true;
    for(auto& v : graph[src]) {
      if(!hit_a_sink_vertex && sink_vertices_set.find(v) != sink_vertices_set.end()) {
        printf("%s: checking for %d and hit a sink vertex %d\n", __func__, src, v);
        hit_a_sink_vertex = true;
    }

      if(!visited[v] && IsCyclicRecursive(graph, visited, v, recursion_st, sink_vertices_set, is_involved_in_cycle, hit_a_sink_vertex)) {
        printf("%s on %d: found cycle for vertex %d\n", __func__, __LINE__, src);
        is_involved_in_cycle[v] = 1;
        return true;
      }
      else if(recursion_st[v]) {
        printf("%s on %d: found cycle for vertex %d\n", __func__, __LINE__, src);
        is_involved_in_cycle[v] = 1;
        return true;
      }
    }
  recursion_st[src] = false; // remove it from recursion stack
  is_involved_in_cycle[src] = 0;
  return !hit_a_sink_vertex;
}

std::vector<int> Solve(const std::vector<std::vector<int>>& graph) {
  const int&        vertices = graph.size();
  //sanity check
  if(vertices == 0) {
    // no vertices
    return std::vector<int> ();
  }
  std::vector<bool> safe_states(vertices);
  // sink vertices
  std::unordered_set<int> sink_vertices_set;
  for (int i = 0; i < vertices; ++i) {
    if (graph[i].size() == 0) {
      sink_vertices_set.insert(i);
      printf("%s on %d: found no cycle for vertex %d\n", __func__, __LINE__, i);
      safe_states[i] = true;
    }
  }
  // dfs data structures
  std::vector<bool> visited(vertices);
  std::vector<bool> recursion_st(vertices);
  std::vector<int> is_involved_in_cycle(vertices, -1);
  bool hit_a_sink_vertex;

  for (int i = 0; i < vertices; ++i) {
    if (!safe_states[i]) {// hasn't determined the state's safety yet
      hit_a_sink_vertex = false;
      if (!visited[i] && !IsCyclicRecursive(graph, visited, i, recursion_st, sink_vertices_set, is_involved_in_cycle, hit_a_sink_vertex)) { // safe state if not a cycle
        safe_states[i] = is_involved_in_cycle[i] == 1;
      }
    }
  }

  std::vector<int> sol;
  for(int i = 0; i < vertices; ++i) {
    if(safe_states[i]) {
      sol.emplace_back(i);
    }
  }
  return sol;
}
// clang-format on

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<std::vector<int>> graph(n);
  int                           outgoiung_edges = 0;
  // input the graph
  for (int i = 0; i < n; ++i) {
    printf("%d : ", i);
    scanf("%d", &outgoiung_edges);
    graph[i].resize(outgoiung_edges);
    for (int j = 0; j < outgoiung_edges; ++j) {
      scanf("%d", &graph[i][j]);
      printf("%d  ", graph[i][j]);
    }
    printf("\n");
  }
  printf("%s: solution is as follows:\n", __func__);
  auto sol = Solve(graph);
  for (auto& v : sol) {
    printf("%d  ", v);
  }
  printf("\n");
  return 0;
}

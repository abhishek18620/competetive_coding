// https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <queue>
#include <vector>

constexpr int INF = 1e9;

enum {
  SRC    = 0,
  DEST   = 1,
  WEIGHT = 2,
};

void CreateGraph(std::vector<std::vector<std::pair<int, int>>>& graph,
                 const std::vector<std::vector<int>>&           times) {
  for (const auto& ele : times) {
    graph[ele[SRC]].emplace_back(std::make_pair(ele[DEST], ele[WEIGHT]));
  }
  return;
}

int Dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, const int& src) {
  const int         N = graph.size() - 1;
  std::vector<bool> visited(N + 1);
  std::vector<int>  distance(N + 1, INF);
  distance[src] = 0;
  std::priority_queue<std::pair<int, int>> pq; // weight, vertex
  int                                      v;
  int                                      weight;
  pq.push(std::make_pair(0, src));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    visited[u] = true;
    // printf("Visiting %d\n", u);
    for (auto nei : graph[u]) {
      v      = nei.first;
      weight = nei.second;
      if (distance[v] > distance[u] + weight) {
        // printf("Visiting %ds neighbour %d\n", u, v);
        distance[v] = distance[u] + weight;
        pq.push(std::make_pair(distance[v], v));
      }
    }
  }
  // check if all visited and fix max of all of them
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      // some vertex couldn't be visited
      return -1;
    }
  }
  // all vertices has been visited
  int sol = 0;
  for (int i = 1; i <= N; ++i) {
    sol = std::max(sol, distance[i]);
  }
  return sol;
}

int Solve(const std::vector<std::vector<int>>& times, const int& N, const int& K) {
  if (N == 0 || times.size() == 0) {
    // crappy base cases
    return -1;
  }
  std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
  CreateGraph(graph, times);
  int sol = Dijkstra(graph, K);
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  int m;
  int src;
  scanf("%d %d %d", &n, &m, &src);
  printf("%s: n = %d\n", __func__, n);
  std::vector<std::vector<int>> times(m, std::vector<int>(3));
  for (auto& arr : times) {
    scanf("%d %d %d", &arr[SRC], &arr[DEST], &arr[WEIGHT]);
    printf("src = %d dest = %d weight = %d\n", arr[SRC], arr[DEST], arr[WEIGHT]);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(times, n, src));
  return 0;
}

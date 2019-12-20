// https://leetcode.com/problems/evaluate-division/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void PrintGraph(const std::vector<std::vector<double>> &graph) {
  for (auto &arr : graph) {
    printf("\n");
    for (auto &val : arr) {
      printf("%lf   ", val);
    }
  }
  printf("\n");
}

void FillGraph(const int &n, std::vector<std::vector<double>> &graph) {
  printf("Entered %s", __func__);
  for (int i = 1; i <= n; i++) {
    graph[i][i] = 1.0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        graph[i][j] = 1.0;
        continue;
      }
      if (graph[i][j] != -1) {
        continue;
      }
      // i -> k -> j
      //  i     k      i
      // --- * ---  = ---
      //  k     j      j
      for (int k = 1; k <= n; k++) {
        if (graph[i][k] != -1.0 && graph[k][j] != -1.0) {
          graph[i][j] = graph[i][k] * graph[k][j];
          if (graph[i][j] != 0.0) {
            graph[j][i] = 1 / graph[i][j];
          }
          printf("%s: (%d, %d, k = %d) = %lf\n", __func__, i, j, k,
                 graph[i][j]);
        }
      }
    }
  }
}

std::vector<double>
Solve(const std::vector<std::pair<std::string, std::string>> &equations,
      const std::vector<double> &values,
      const std::vector<std::pair<std::string, std::string>> &queries) {
  printf("%s: Entered\n", __func__);
  std::vector<double> sol;

  std::unordered_map<std::string, int> ver_int_map;
  int idx = 0;
  for (auto &pai : equations) {
    // inputs equations
    // printf("edges %s -> %s\n", pai.first.c_str(), pai.second.c_str());
    if (ver_int_map.find(pai.first) == ver_int_map.end()) {
      ver_int_map.insert({pai.first, ++idx});
    }
    if (ver_int_map.find(pai.second) == ver_int_map.end()) {
      ver_int_map.insert({pai.second, ++idx});
    }
  }
  const int n = ver_int_map.size();
  printf("%s: total string variables = %d\n", __func__,
         (int)ver_int_map.size());
  for (auto pai : ver_int_map) {
    printf("%s: key = %s  value = %d\n", __func__, pai.first.c_str(),
           pai.second);
  }
  std::vector<std::vector<double>> graph(n + 1,
                                         std::vector<double>(n + 1, -1.0));
  std::cout << graph.size() << std::endl;
  PrintGraph(graph);
  // form the adjaceny matrix graph
  for (int i = 0; i < equations.size(); i++) {
    /*
     * u = equations[i].first
     * v = equations[i].second
     * there is an edge between u to v
     */
    const int &u = ver_int_map[equations[i].first];
    const int &v = ver_int_map[equations[i].second];
    graph[u][v] = values[i];
    if (values[i] != 0.0) {
      // 1/ val is not defined
      graph[v][u] = 1.0 / values[i];
    }
  }
  PrintGraph(graph);
  FillGraph(n, graph);
  PrintGraph(graph);
  for (const auto &pai : queries) {
    // const int& u = ver_int_map[pai.first];
    // const int& v = ver_int_map[pai.second];
    sol.emplace_back(graph[ver_int_map[pai.first]][ver_int_map[pai.second]]);
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n_eqs;
  int n_quer;
  scanf("%d", &n_eqs);
  scanf("%d", &n_quer);
  std::vector<std::pair<std::string, std::string>> equations(n_eqs);
  std::vector<double> values(n_eqs);
  std::vector<std::pair<std::string, std::string>> queries(n_quer);
  std::unordered_map<std::string, int> ver_int_map;
  printf("%s: Input: n_eqs = %d n_quer = %d\n", __func__, n_eqs, n_quer);
  for (auto &pai : equations) {
    // inputs equations
    std::cin >> pai.first >> pai.second;
    printf("edges %s -> %s\n", pai.first.c_str(), pai.second.c_str());
  }
  for (auto &val : values) {
    scanf("%lf", &val);
  }
  for (auto &pai : queries) {
    // inputs queries
    std::cin >> pai.first >> pai.second;
    printf("query = %s -> %s\n", pai.first.c_str(), pai.second.c_str());
  }
  printf("%s: I'm out of loop\n", __func__);
  auto sol = Solve(equations, values, queries);
  printf("%s: Output as follows\n", __func__);
  for (const auto &val : sol) {
    printf("%lf  ", val);
  }
  printf("\n");
  return 0;
}

// https://leetcode.com/problems/reconstruct-itinerary/
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

void FindItineraryOrder(
    const std::string src,
    std::unordered_map<std::string, std::set<std::string>> &graph,
    std::stack<std::string> &sol_stack) {
  while (graph.at(src).size() > 0) {
    const std::string v = *(graph.at(src).begin());
    graph.at(src).erase(v);
    FindItineraryOrder(v, graph, sol_stack);
  }
  sol_stack.push(src);
}

std::vector<std::string>
Solve(std::vector<std::pair<std::string, std::string>> &edge_list) {
  std::vector<std::string> sol;
  // form graph
  std::unordered_map<std::string, std::set<std::string>> graph;
  for (const auto &pai : edge_list) {
    graph[pai.first].insert(pai.second);
    if (graph.find(pai.second) == graph.end()) {
      graph[pai.second] = std::set<std::string>();
    }
  }

  for (auto pai : graph) {
    printf("%s -> ", pai.first.c_str());
    for (auto vs : pai.second) {
      printf("%s  ", vs.c_str());
    }
    printf("\n");
  }
  std::stack<std::string> sol_stack;
  FindItineraryOrder("JFK", graph, sol_stack);
  while (!sol_stack.empty()) {
    sol.emplace_back(sol_stack.top());
    sol_stack.pop();
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  std::vector<std::pair<std::string, std::string>> edge_list(n);
  const std::string u, v;
  for (int i = 0; i < n; i++) {
    std::cin >> edge_list[i].first >> edge_list[i].second;
  }
  auto sol = Solve(edge_list);
  printf("%s: sol size = %d\n", __func__, (int)sol.size());
  for (auto ap : sol) {
    printf("%s  ", ap.c_str());
  }
  printf("\n");
  return 0;
}

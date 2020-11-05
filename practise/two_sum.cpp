// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <unordered_map>
#include <vector>

std::pair<int, int> Solve(const std::vector<int>& arr, const int& target) {
  const int n = arr.size();
  if (n == 0) {
    return std::make_pair(-1, -1);
  }
  std::pair<int, int>                       sol;
  std::unordered_map<int, std::vector<int>> index_map;
  for (int i = 0; i < n; ++i) {
    index_map[arr[i]].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (index_map.find(target - arr[i]) != index_map.end()) {
      if (target == 2 * arr[i]) {
        // special case where target = 2*arr[i]
        if (index_map[arr[i]].size() >= 2) {
          sol.first  = index_map[arr[i]][0];
          sol.second = index_map[arr[i]][1];
          printf("%s %d: %d %d\n", __func__, __LINE__, sol.first, sol.second);
          return sol;
        }
        continue;
      }
      sol.first  = i;
      sol.second = index_map[target - arr[i]][0];
      printf("%s %d: %d %d\n", __func__, __LINE__, sol.first, sol.second);
      return sol;
    }
  }
  return std::make_pair(-1, -1);
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  int target;
  scanf("%d %d", &n, &target);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  auto sol = Solve(arr, target);
  printf("%s: solution = (%d, %d)\n", __func__, sol.first, sol.second);
  scanf("%d", &n);
  return 0;
}

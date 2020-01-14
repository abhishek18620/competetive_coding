// https://leetcode.com/problems/couples-holding-hands/
/* Key : SCC and Union find DS(Disjoint set DS)
 * The idea is that having all the couples holding their hands
 * will have N/2 connected components. Now each swap increases
 * one SCC so total swaps requiered would be
 * N/2 - (# of SCCs present in graph)
 * Eg : (0th SCC: 0, 1) (1st SCC: 2, 3) (2nd SCC: 3, 4) etc set of ith element  = (i >> 1)
 */
#include <iostream>
#include <unordered_map>
#include <vector>
int Find(std::unordered_map<int, int>& parent_map, const int& x) {
  if (parent_map[x] == x) {
    return x;
  }
  return Find(parent_map, parent_map[x]);
}
// Checks if x1 and x2 belong to same set
bool Union(std::unordered_map<int, int>& parent_map, const int& x1, const int& x2) {
  int set1 = Find(parent_map, x1);
  int set2 = Find(parent_map, x2);
  if (set1 != set2) {
    parent_map[set2] = set1;
    return true;
  }
  return false;
}

int Solve(const std::vector<int>& arr) {
  const int                    n = arr.size();
  std::unordered_map<int, int> parent_map; // vertex to its parent
  for (auto& ele : arr) {
    parent_map[ele] = 2 * (ele >> 1);
  }

  int total_required_scc = n >> 1;
  int sccs_present       = total_required_scc;
  printf("%s: total_required_scc = %d\n", __func__, total_required_scc);
  for (int i = 0; i < n; i += 2) {
    if (Union(parent_map, arr[i], arr[i + 1])) {
      sccs_present--;
    }
  }
  return total_required_scc - sccs_present;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr));
  scanf("%d", &n);
  return 0;
}

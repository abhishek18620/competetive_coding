// https://leetcode.com/problems/odd-even-jump/
#include <iostream>
#include <map> // binary tree
#include <vector>

constexpr int INF     = 1e9 + 9;
constexpr int NEG_INF = -1e9;

enum State {
  EVEN = 0,
  ODD  = 1,
};

struct PreProcessed {
  int largest_possible  = -1;
  int lp_idx            = -1;
  int smallest_possible = -1;
  int sp_idx            = -1;
};

void PrintSortedMap(const std::map<int, int>& s_map) {
  printf("Entered : %s\n", __func__);
  for (auto pai : s_map) {
    printf("%d = %d\n", pai.first, pai.second);
  }
}

// binary search
void PreProcess(const std::vector<int>& arr, std::vector<PreProcessed>& pre_processed) {
  const int& n                           = arr.size();
  pre_processed[n - 1].largest_possible  = arr[n - 1];
  pre_processed[n - 1].smallest_possible = arr[n - 1];
  pre_processed[n - 1].lp_idx            = n - 1;
  pre_processed[n - 1].sp_idx            = n - 1;

  std::map<int, int> sorted_map; // binary tree
  sorted_map.insert({arr[n - 1], n - 1});
  for (int i = n - 2; i >= 0; --i) {
    auto it = sorted_map.find(arr[i]);
    if (it == sorted_map.end()) {     // element not found
      sorted_map.insert({arr[i], i}); // insert the element and its idx pair

      // smallest possible value larger than arr[i]
      auto find_it = sorted_map.find(arr[i]);
      pre_processed[i].smallest_possible =
          (find_it != (std::prev(sorted_map.end()))) ? (++find_it)->first : -1;
      pre_processed[i].sp_idx =
          (pre_processed[i].smallest_possible != -1) ? (find_it)->second : -1;

      // largest possible value smaller than arr[i]
      find_it = sorted_map.find(arr[i]);
      pre_processed[i].largest_possible =
          (find_it != sorted_map.begin()) ? (--find_it)->first : -1;
      pre_processed[i].lp_idx =
          (pre_processed[i].largest_possible != -1) ? (find_it)->second : -1;

    } else {
      // element found in map so no need to insert
      // smallest possible value larger than arr[i]
      pre_processed[i].smallest_possible = it->first;
      pre_processed[i].sp_idx            = it->second;
      // largest possible value smaller than arr[i]
      pre_processed[i].largest_possible = it->first;
      pre_processed[i].lp_idx           = it->second;

      sorted_map.at(arr[i]) = i; // update the index
    }
    // PrintSortedMap(sorted_map);
  }
}

int Solve(const std::vector<int>& arr) {
  int n = arr.size();
  if (n == 0 || n == 1) {
    return n;
  }
  int                            sol = 1;
  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(2));
  std::vector<PreProcessed>      pre_processed(n);
  PreProcess(arr, pre_processed);

  int curr_ele;
  int smallest_possible;
  int sp_idx;
  int largest_possible;
  int lp_idx;
  dp[n - 1][EVEN] = true;
  dp[n - 1][ODD]  = true;
  for (int i = n - 2; i >= 0; --i) {
    curr_ele          = arr[i];
    smallest_possible = (pre_processed[i].smallest_possible != -1)
                            ? pre_processed[i].smallest_possible
                            : NEG_INF;
    sp_idx           = (smallest_possible != NEG_INF) ? pre_processed[i].sp_idx : -1;
    largest_possible = (pre_processed[i].largest_possible != -1)
                           ? pre_processed[i].largest_possible
                           : INF;
    lp_idx = (largest_possible != INF) ? pre_processed[i].lp_idx : -1;
    // update
    // printf("%s: i = %d lp_idx = %d  sp_idx = %d\n", __func__, i, lp_idx, sp_idx);
    dp[i][EVEN] = (lp_idx != -1) ? dp[lp_idx][ODD] : false;
    dp[i][ODD]  = (sp_idx != -1) ? dp[sp_idx][EVEN] : false;
    sol += dp[i][ODD]; // would be a good start only if it is used as 1st turn (odd turn)
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: Input n = %d\n", __func__, n);
  std::vector<int> arr;
  arr.resize(n);
  for (int& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: solution = %d\n", __func__, Solve(arr));
  return 0;
}

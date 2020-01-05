// https://leetcode.com/problems/odd-even-jump/
#include <iostream>
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

void PreProcess(const std::vector<int>& arr, std::vector<PreProcessed>& pre_processed) {
  const int& n                           = arr.size();
  pre_processed[n - 1].largest_possible  = NEG_INF;
  pre_processed[n - 1].smallest_possible = INF;

  for (int i = n - 2; i >= 0; --i) {
    // largest possible
    if (pre_processed[i + 1].largest_possible >= arr[i + 1]) {
      pre_processed[i].largest_possible = arr[i + 1];
      pre_processed[i].lp_idx           = i + 1;
    } else {
      pre_processed[i].largest_possible = pre_processed[i + 1].largest_possible;
      pre_processed[i].lp_idx           = pre_processed[i + 1].lp_idx;
    }
    // smallest possible
    if (pre_processed[i + 1].smallest_possible <= arr[i + 1]) {
      pre_processed[i].smallest_possible = arr[i + 1];
      pre_processed[i].sp_idx            = i + 1;
    } else {
      pre_processed[i].smallest_possible = pre_processed[i + 1].largest_possible;
      pre_processed[i].sp_idx            = pre_processed[i + 1].lp_idx;
    }
  }
}

int Solve(const std::vector<int>& arr) {
  int n = arr.size();
  if (n == 0 || n == 1) {
    return n;
  }
  int                            sol = 1;
  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(2));

  int curr_ele;
  int smallest_possible;
  int sp_idx;
  int largest_possible;
  int lp_idx;
  dp[n - 1][EVEN] = true;
  dp[n - 1][ODD]  = true;
  for (int i = n - 2; i >= 0; --i) {
    curr_ele          = arr[i];
    smallest_possible = NEG_INF;
    sp_idx            = -1;
    largest_possible  = INF;
    lp_idx            = -1;
    for (int j = i + 1; j < n; ++j) {
      // i as odd turn
      if (curr_ele <= arr[j] && arr[j] < largest_possible) {
        largest_possible = arr[j];
        lp_idx           = j;
      }
      // i as even turn
      if (curr_ele >= arr[j] && arr[j] > smallest_possible) {
        smallest_possible = arr[j];
        sp_idx            = j;
      }
    }
    // update
    printf("%s: i = %d lp_idx = %d  sp_idx = %d\n", __func__, i, lp_idx, sp_idx);
    dp[i][EVEN] = (sp_idx != -1) ? dp[sp_idx][ODD] : false;
    dp[i][ODD]  = (lp_idx != -1) ? dp[lp_idx][EVEN] : false;
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

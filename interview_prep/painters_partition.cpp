#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

constexpr auto MAX = 1e9 + 9;

int solve(int &painters, int &boards, vector<int> &boards_array,
          vector<vector<int>> &dp) {
  vector<int> prefix_sum(boards + 1, 0);
  for (int i = 1; i <= boards; i++) {
    prefix_sum[i] += prefix_sum[i - 1] + boards_array[i];
  }
  // single painter
  for (int i = 1; i <= boards; i++) {
    dp[i][1] = prefix_sum[i];
  }

  // single board
  for (int i = 1; i <= painters; i++) {
    dp[1][i] = boards_array[1];
  }

  for (int board = 2; board <= boards; board++) {
    for (int painter = 2; painter <= painters; painter++) {
      int sol = MAX;
      for (int j = 1; j <= board; j++) {
        sol = min(sol,
                  max(dp[j][painter - 1], prefix_sum[board] - prefix_sum[j]));
      }
      dp[board][painter] = sol;
    }
  }
  return dp[boards][painters];
}

int main() {
  int painters, boards;
  cin >> painters >> boards;
  vector<int> boards_array(boards + 1, 0);
  for (int i = 1; i <= boards; i++) {
    cin >> boards_array[i];
  }
  vector<vector<int>> dp(boards + 1, vector<int>(painters + 1, 0));
  cout << solve(painters, boards, boards_array, dp) << endl;
  return 0;
}

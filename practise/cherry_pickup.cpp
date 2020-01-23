// https://leetcode.com/problems/cherry-pickup/
#include <iostream>
#include <vector>

constexpr int NEG_INF  = -1 * 1e9 + 9;
static auto   get_max4 = [](const int& val1, const int& val2, const int& val3,
                          const int& val4) -> int {
  return std::max(val1, std::max(val2, std::max(val3, val4)));
};
// inlines are generally faster than lambdas
inline static int GetMax4(const int& val1, const int& val2, const int& val3,
                          const int& val4) {
  return std::max(val1, std::max(val2, std::max(val3, val4)));
}

// This is the real catch x1 + y1 == x2 + y2
int SolveRecursive(int x1, int y1, int y2, const int& n,
                   const std::vector<std::vector<int>>&        grid,
                   std::vector<std::vector<std::vector<int>>>& dp) {
  // base cases
  const int& x2 = x1 + y1 - y2;
  if (x1 >= n || y1 >= n || x2 >= n || y2 >= n) {
    return NEG_INF;
  }
  if (dp[x1][y1][y2] != -1) { // state already calculated
    return dp[x1][y1][y2];
  }
  if (x1 == n - 1 && y1 == n - 1) {
    // both traversals at same point  n-1, n-1
    return grid[x1][y1];
  }
  if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
    // hit a thorn
    return NEG_INF;
  }
  // Checks if both traversals are at different blocks Otherwise just count
  // only cherry
  int ans = grid[x1][y1] + ((y1 != y2) ? grid[x2][y2] : 0);
  ans += GetMax4(
      SolveRecursive(x1 + 1, y1, y2 + 1, n, grid, dp), // first : down,  second : right
      SolveRecursive(x1, y1 + 1, y2 + 1, n, grid, dp), // first : right, second : right
      SolveRecursive(x1, y1 + 1, y2, n, grid, dp),     // first : right, second : down
      SolveRecursive(x1 + 1, y1, y2, n, grid, dp)      // first : down, second : down
  );
  printf("%s: %d %d %d %d %d\n", __func__, x1, y1, x2, y2, ans);
  return dp[x1][y1][y2] = ans;
}

int Solve(const std::vector<std::vector<int>>& grid) {
  const int                                  n = grid[0].size();
  std::vector<std::vector<std::vector<int>>> dp(
      n, std::vector<std::vector<int>>(n, std::vector<int>(n, -1)));
  return std::max(0, SolveRecursive(0, 0, 0, n, grid, dp));
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<std::vector<int>> grid(n, std::vector<int>(n));
  for (auto& arr : grid) {
    for (auto& ele : arr) {
      scanf("%d", &ele);
      printf("%d  ", ele);
    }
    printf("\n");
  }
  printf("%s: solution = %d\n", __func__, Solve(grid));
  return 0;
}

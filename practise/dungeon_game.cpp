// https://leetcode.com/problems/grid-game/
#include <iostream>
#include <vector>

int Solve(const std::vector<std::vector<int>>& grid) {
  const int m = grid.size();
  const int n = grid[0].size();

  std::vector<std::vector<int>> dp(m, std::vector<int>(n));
  dp[m - 1][n - 1] = std::max(1 - grid[m - 1][n - 1], 1);

  // init last row
  for (int i = m - 2; i >= 0; i--) {
    dp[i][n - 1] = std::max(dp[i + 1][n - 1] - grid[i][n - 1], 1);
  }

  // init last column
  for (int j = n - 2; j >= 0; j--) {
    dp[m - 1][j] = std::max(dp[m - 1][j + 1] - grid[m - 1][j], 1);
  }

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      int down  = std::max(dp[i + 1][j] - grid[i][j], 1);
      int right = std::max(dp[i][j + 1] - grid[i][j], 1);
      dp[i][j]  = std::min(right, down);
    }
  }
  return dp[0][0];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m;
  int n;
  scanf("%d %d", &m, &n);
  printf("%s: m = %d  n = %d\n", __func__, m, n);
  std::vector<std::vector<int>> grid(m, std::vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &grid[i][j]);
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d  ", grid[i][j]);
    }
    printf("\n");
  }

  printf("%s: solution = %d\n", __func__, Solve(grid));
  return 0;
}

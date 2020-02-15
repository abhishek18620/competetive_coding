// https://leetcode.com/problems/maximal-square/
#include <iostream>
#include <vector>

struct State {
  int max_len   = 0;
  int max_width = 0;

  State(const int& len, const int& wid) {
    max_len   = len;
    max_width = wid;
  }
  void Print() const { printf("%s: len = %d   width = %d\n", __func__, this->max_len, this->max_width); }
};

inline int GetArea(const int& side) {
  printf("%s: area = %d\n", __func__, side * side);
  return side * side;
}

int Solve(const std::vector<std::vector<char>>& grid) {
  const int m = grid.size();
  // sanity check
  if (m == 0) {
    return 0;
  }
  const int                       n   = grid[0].size();
  int                             sol = 0;
  std::vector<std::vector<State>> dp(m + 1, std::vector<State>(n + 1, State(0, 0)));

  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (grid[i][j] == '0') {
        continue;
      }
      dp[i][j] = State(1, 1);
      sol      = std::max(sol, 1);
      if (i + 1 < m && j + 1 < n) {
        if (grid[i + 1][j + 1] == '0') {
          continue;
        }
        dp[i][j].max_len   = std::min(dp[i + 1][j + 1].max_len, dp[i][j + 1].max_len) + 1;
        dp[i][j].max_width = std::min(dp[i + 1][j + 1].max_width, dp[i + 1][j].max_width) + 1;
        printf("%s: (i = %d, j = %d) = max_len = %d max_wid = %d\n", __func__, i, j, dp[i][j].max_len,
               dp[i][j].max_width);

        // check diagonal element
        sol = std::max(sol, GetArea(std::min(dp[i][j].max_len, dp[i][j].max_width)));
      }
    }
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m, n;
  scanf("%d %d", &m, &n);
  printf("%s: m = %d  n = %d\n", __func__, m, n);
  std::vector<std::vector<char>> grid(m, std::vector<char>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> grid[i][j];
      // scanf("%c", &grid[i][j]);
      printf("%c  ", grid[i][j]);
    }
    printf("\n");
  }
  printf("%s: solution = %d\n", __func__, Solve(grid));
  return 0;
}

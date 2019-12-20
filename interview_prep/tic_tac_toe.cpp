// https://leetcode.com/contest/weekly-contest-165/problems/find-winner-on-a-tic-tac-toe-game/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
constexpr int INF = 1e9 + 9;

bool ValidateIndex(const int &i, const int &j, const int &m, const int &n) {
  return (i >= 0 && i < m && j >= 0 && j < n) ? true : false;
}

std::string DetermineWinner(const std::vector<std::pair<int, int>> &moves) {
  int grid[3][3];
  std::memset(grid, 0, sizeof(grid));
  // A = 1    B = -1  otherwise 0
  for (int i = 0; i < moves.size(); i++) {
    grid[moves[i].first][moves[i].second] = (i & 1) ? -1 : 1;
  }
  // check row
  int moves_sum = 0;
  for (int i = 0; i < 3; i++) {
    moves_sum = 0;
    for (int j = 0; j < 3; j++) {
      moves_sum += grid[i][j];
    }
    if (moves_sum == 3) {
      return std::string("A");
    } else if (moves_sum == -3) {
      return std::string("B");
    }
  }

  // check column
  for (int i = 0; i < 3; i++) {
    moves_sum = 0;
    for (int j = 0; j < 3; j++) {
      moves_sum += grid[j][i];
    }
    if (moves_sum == 3) {
      return std::string("A");
    } else if (moves_sum == -3) {
      return std::string("B");
    }
  }

  // diagonal
  moves_sum = 0;
  for (int i = 0; i < 3; i++) {
    moves_sum += grid[i][i];
  }
  if (moves_sum == 3) {
    return std::string("A");
  } else if (moves_sum == -3) {
    return std::string("B");
  }
  moves_sum = grid[0][2] + grid[1][1] + grid[2][0];
  if (moves_sum == 3) {
    return std::string("A");
  } else if (moves_sum == -3) {
    return std::string("B");
  }
  if (moves.size() < 9) {
    return std::string("Pending");
  }
  return std::string("Draw");
}

long long Solve(std::vector<std::vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
  // bpttom up
  long long sol = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (matrix[i][j] == 0) {
        continue;
      }
      // minimum(right (i, j+1), bottom (i+1, j), diagonal (i+1, j+1))
      if (ValidateIndex(i, j + 1, m, n) && ValidateIndex(i + 1, j, m, n) &&
          ValidateIndex(i + 1, j + 1, m, n)) {
        dp[i][j] =
            std::min(dp[i][j + 1], std::min(dp[i + 1][j], dp[i + 1][j + 1]));
      }
      dp[i][j]++;
      sol += dp[i][j];
    }
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::vector<std::pair<int, int>> moves;
  printf("%s: solution = %s\n", __func__, DetermineWinner(moves).c_str());
  return 0;
}

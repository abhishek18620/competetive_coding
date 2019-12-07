// https://leetcode.com/contest/weekly-contest-165/problems/count-square-submatrices-with-all-ones/
#include <iostream>
#include <string>
#include <vector>
constexpr int INF = 1e9 + 9;

bool ValidateIndex(const int &i, const int &j, const int &m, const int &n) {
  return (i >= 0 && i < m && j >= 0 && j < n) ? true : false;
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
  int m;
  int n;
  scanf("%d %d", &m, &n);
  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("%s: solution = %lld\n", __func__, Solve(matrix));
  return 0;
}

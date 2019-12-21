//https://leetcode.com/problems/unique-paths/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int Solve(std::vector<std::vector<int>>& grid) {
  const int& rows = grid.size();
  const int& cols = grid[0].size();
  if(rows == 1 && cols == 1) {
    return grid[0][0];
  }
  std::vector<std::vector<int> > dp(rows+1, std::vector<int>(cols+1, -1));
  //base case
  dp[rows-1][cols-1] = grid[rows-1][cols-1];
  for(int i = rows-2; i >=0; i--) {
    dp[i][cols-1] = dp[i+1][cols-1] + grid[i][cols-1];
  }
  for(int i = cols-2; i >= 0; i--) {
    dp[rows-1][i] = dp[rows-1][i+1] + grid[rows-1][i];
  }
  for(int i = rows-2; i >= 0; i--) {
    for(int j = cols-2; j>=0; j--) {
      if(dp[i][j] != -1) {
       continue;
      }
      dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
    }
  }
  return dp[0][0];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int M, N;
  scanf("%d %d", &M, &N);
  std::vector<std::vector<int>> grid(M, std::vector<int>(N, 0));
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  printf("%d", Solve(grid));
  return 0;
}

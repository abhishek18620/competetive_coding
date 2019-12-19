// https://leetcode.com/problems/unique-paths-ii/
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

long long  Solve(std::vector<std::vector<bool>>& grid, int& rows, int& cols) {
  if(rows == 1 &&  cols == 1 && !grid[0][0]) {
    return 1;
  }
  if(grid[rows-1][cols-1]) {
    return 0;
  }
  std::vector<std::vector<long long> > dp(rows+1, std::vector<long long>(cols+1, -1*1ll));
  //base case
  bool obstacle_found = false;
  // last column
  for(int i = rows - 1; i >= 0; i--) {
    if(!obstacle_found && grid[i][cols-1]) {
      obstacle_found = true;
    }
    dp[i][cols-1] = obstacle_found ? 0 : 1;
  }
  //last rows
  obstacle_found = false;
  for(int i = cols-1; i >= 0; i--) {
    if(!obstacle_found && grid[rows-1][i]) {
      obstacle_found = true;
    }
    dp[rows-1][i] = obstacle_found ? 0 : 1;
  }
  //end of base cases--------------------------------------------------------

  dp[rows-1][cols-1] = 0;
  printf("rows = %d cols = %d", rows, cols);
  for(int i = rows-1; i >= 0; i--) {
    for(int j = cols-1; j>=0; j--) {
      printf("i = %d j = %d %d %lld\n", i, j, (int)grid[i][j], dp[i][j]);
      if(dp[i][j] != -1) {
       continue;
      }
      if(grid[i][j]) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = (grid[i+1][j] ? 0 : dp[i+1][j]) + (grid[i][j+1] ? 0 : dp[i][j+1]);
    }
  }
  return dp[0][0];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int M, N;
  scanf("%d %d", &M, &N);
  std::vector<std::vector<bool>> grid(M, std::vector<bool>(N , false));
  for(int i = 0; i < M; i++) {
    int inp;
    for(int j = 0; j < N; j++) {
      scanf("%d", &inp);
      grid[i][j] = inp;
    }
  }
  printf("%lld", Solve(grid, M, N));
  return 0;
}

//https://leetcode.com/problems/unique-paths/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int Solve(int &rows, int& cols) {
  if(rows == 1 || cols == 1) {
    return 1;
  }
  std::vector<std::vector<int> > dp(rows+1, std::vector<int>(cols+1, -1));
  //base case
  for(int i = 0; i < rows; i++) {
    dp[i][cols-1] = 1;
  }
  for(int i = 0; i < cols; i++) {
    dp[rows-1][i] = 1;
  }
  dp[rows-1][cols-1] = 0;
  for(int i = rows-1; i >= 0; i--) {
    for(int j = cols-1; j>=0; j--) {
      if(dp[i][j] != -1) {
       continue;
      }
      dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }
  }
  return dp[0][0];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int M, N;
  scanf("%d %d", &M, &N);
  printf("%d", Solve(M, N));
  return 0;
}

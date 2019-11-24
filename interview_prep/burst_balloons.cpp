#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

int solve(std::vector<int>& balloons) {
  int n = balloons.size();
  std::vector<std::vector<int> > dp(n + 2, std::vector<int> (n + 2, 0));
  //state(i, j) = balloons starting from i to j
  for(int i = 1; i < n + 1; i++) {
    for(int j = i + 1; j < n + 1; j++) {
      // burst balloons from i to j
      for(int last = i; last < j + 1; last++) {
        dp[i][j] = std::max(dp[i][j], dp[i][last - 1] + balloons[i] * balloons[last] * balloons[j + 1] + dp[last + 1][j]);
      }
    }
  }
  return dp[1][n];
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> balloons(n);
  // balloons
  for(int i = 0; i < n; i++) {
    std::cin >> balloons[i];
  }
  std::cout << solve(balloons) << std::endl;
  return 0;
}

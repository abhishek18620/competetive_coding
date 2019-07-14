#include <iostream>
#include <string>
#include <vector>

int solve(std::string &balanced, std::vector<std::vector<std::vector<int>>> &dp,
          int i, int bal_x, int bal_y) {
  if (dp[i][bal_x][bal_y] != -1) {
    // state already calculated
    return dp[i][bal_x][bal_y];
  }

  if (i == balanced.length()) {
    // all characters used
    return (int)!bal_x && !bal_y;
  }
  dp[i][bal_x][bal_y] = 0;
  if (balanced[i] == '(') {
    // opening bracket should increment c_i
    // append the ith char to str x                   append the ith char to str
    // y
    dp[i][bal_x][bal_y] = solve(balanced, dp, i + 1, bal_x + 1, bal_y) +
                          solve(balanced, dp, i + 1, bal_x, bal_y + 1);
  } else if (bal_x) {
    // closing bracket should decrement bal_i and number of closing brackets
    // should be smaller than opening otherwise it'll never be a balanced string
    // append the ith char to str x
    dp[i][bal_x][bal_y] = solve(balanced, dp, i + 1, bal_x - 1, bal_y);
  } else if (bal_y) {
    // closing bracket should decrement bal_i and number of closing brackets
    // should be smaller than opening otherwise it'll never be a balanced string
    // append the ith char to str x
    dp[i][bal_x][bal_y] = solve(balanced, dp, i + 1, bal_x, bal_y - 1);
  }
  return dp[i][bal_x][bal_y];
}

int main() {
  std::string balanced;
  std::cin >> balanced;
  std::vector<std::vector<std::vector<int>>> dp(
      balanced.length() + 1,
      std::vector<std::vector<int>>(
          balanced.length() + 1, std::vector<int>(balanced.length() + 1, -1)));
  std::cout << solve(balanced, dp, 0, 0, 0) << std::endl;
  return 0;
}

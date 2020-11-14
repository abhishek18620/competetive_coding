// https://leetcode.com/problems/wildcard-matching/
#include <iostream>
#include <string>
#include <vector>

enum StateResult {
  NOT_CALCULATED = 0,
  MATCH          = 1,
  NO_MATCH       = 2,
};

StateResult SolveRecursive(const int& i, const int& j,
                           std::vector<std::vector<StateResult>>& dp,
                           const std::string& str1, const std::string& str2) {
  // base cases
  printf("%s: state(%d, %d)\n", __func__, i, j);
  if (dp[i][j] != NOT_CALCULATED) {
    // state already calculated
    return dp[i][j];
  }

  if (j >= str2.length()) {
    // exceeded pattern length
    if (i < str1.length()) {
      return NO_MATCH;
    }
    return MATCH;
  }
  if (i > str1.length()) {
    return dp[i][j] = NO_MATCH;
  }

  if (str2[j] == '*') {
    if (SolveRecursive(i, j + 1, dp, str1, str2) != MATCH) {   // matched againt empty
      if (SolveRecursive(i + 1, j, dp, str1, str2) != MATCH) { // still matching
        if (SolveRecursive(i + 1, j + 1, dp, str1, str2) != MATCH) { // matched till i
          return dp[i][j] = NO_MATCH; // * matched with empty string
        }
      }
    }
    printf("%d: @debug: Matched %d %d\n", __LINE__, i, j);
    return dp[i][j] = MATCH;
  }

  if (i >= str1.length()) {
    // nothing to match against ?
    return NO_MATCH;
  }

  if (str2[j] == '?') {
    return dp[i][j] = SolveRecursive(i + 1, j + 1, dp, str1, str2);
  }
  // both i and j are normal characters
  if (str1[i] != str2[j]) {
    return dp[i][j] = NO_MATCH;
  } else {
    // special state as it could be the last one as well
    return dp[i][j] = SolveRecursive(i + 1, j + 1, dp, str1, str2);
  }
}

/**
 * @brief str1 = string
 *        str2 = pattern
 */
bool Solve(const std::string& str1, const std::string& str2) {
  int m = str1.size();
  int n = str2.size();
  // handle bases cases
  if (m == 0) {
    if ((n == 0) || (n == 1 && str2[0] == '*')) {
      return true;
    }
    return false;
  }
  std::vector<std::vector<StateResult>> dp(
      m + 2, std::vector<StateResult>(n + 2, NOT_CALCULATED));
  const auto& sol = SolveRecursive(0, 0, dp, str1, str2);
  printf("%s: solution = %s\n", __func__, (sol == MATCH) ? "MATCHED" : "NO_MATCH");
  return (sol == MATCH);
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str1;
  std::string str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  printf("%s: Input str1 = %s  str2 = %s\n", __func__, str1.c_str(), str2.c_str());
  printf("%s: solution = %s\n", __func__, Solve(str1, str2) ? "true" : "false");
  return 0;
}

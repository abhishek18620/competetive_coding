// https://leetcode.com/problems/distinct-subsequences/
#include <iostream>
#include <string>
#include <vector>

// typedef long long long long;

int Solve(const std::string& S, const std::string& T) {
  const long long& m = S.length();
  const long long& n = T.length();
  if (m < n) {
    // handle crappy Not possible base cases
    return 0;
  }
  if (S == T || n == 0) {
    // Case 1 : equal string, then only one subsequence the string itself
    // Case 2 : T is empty, one subsequence don't use anything
    return 1;
  }
  std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1));
  // Initialise first column as 1
  for (long long k = 0; k < m; ++k) {
    dp[k][0] = 1;
  }
  dp[0][0] = 1;
  for (long long len = 1; len <= n; ++len) { // length of T covered
    for (long long i = len; i <= m; ++i) {
      dp[i][len] =
          dp[i - 1][len] +
          ((S[i - 1] == T[len - 1] && i <= m - n + len) ? dp[i - 1][len - 1] : 0);
      // printf("%s: state(%long longd, %long longd) or state(%c, %c) = %long longd\n",
      // __func__, i, len, S[i - 1], T[len - 1], dp[i][len]);
    }
  }
  return dp[m][n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string S;
  std::string T;
  std::getline(std::cin, S);
  std::getline(std::cin, T);
  printf("%s: Input S = %s   T = %s\n", __func__, S.c_str(), T.c_str());
  printf("%s: solution = %d\n", __func__, Solve(S, T));
  return 0;
}


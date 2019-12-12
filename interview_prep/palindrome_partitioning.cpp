// https://leetcode.com/contest/weekly-contest-165/problems/palindrome-partitioning-iii/
#include <iostream>
#include <string>
#include <vector>
constexpr int INF = 1e9 + 9;

int MakePalindrome(const std::string &str, const int &start, const int &end) {
  int sol = 0;
  for (int i = start, j = end; i <= j; i++, j--) {
    if (str[i] != str[j]) {
      sol++;
    }
  }
  return sol;
}

int Solve(const std::string &str, const int &k) {
  int len = str.length();
  if (len == k) {
    return 0;
  }
  std::vector<std::vector<int>> dp(len + 1, std::vector<int>(k + 1, -1));
  // base cases
  for (int i = 0; i < len + 1; i++) {
    dp[i][i + 1] = 0; // i+1 chars and i parts as well
  }
  for (int i = 0; i < len; i++) {
    dp[i][1] = MakePalindrome(str, 0, i); // single part
  }

  for (int i = 0; i < len; i++) {
    for (int parts = 1; parts <= i + 1; parts++) {
      if (parts > k) {
        // parts has exceeded k
        break;
      }
      if (dp[i][parts] != -1) {
        // already calculated
        continue;
      }
      int sol = INF;
      for (int j = parts - 2; j <= i - 1; j++) {
        if (j < 0) {
          continue;
        }
        sol = std::min(sol, dp[j][parts - 1] + MakePalindrome(str, j + 1, i));
      }
      dp[i][parts] = sol;
    }
  }
  return dp[len - 1][k];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str;
  int k;
  std::getline(std::cin, str);
  scanf("%d", &k);
  printf("%s: Input: %s  %d\n", __func__, str.c_str(), k);
  printf("%s: solution = %d\n", __func__, Solve(str, k));
  return 0;
}

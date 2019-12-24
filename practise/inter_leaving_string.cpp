// https://leetcode.com/problems/interleaving-string/
#include <iostream>
#include <string>
#include <vector>

int Solve(const std::string& s1, const std::string& s2,
          const std::string& res) {
  int m = s1.length();
  int n = s2.length();
  //  printf("m = %d n = %d\n", m, n);
  int res_len = res.length();
  if (m + n != res_len) {
    return false;
  }
  std::vector<std::vector<bool>> dp(m + 2, std::vector<bool>(n + 2));
  // getter lambda for dp[i][j], also validates the index
  auto get_index_val = [&dp](const int& i, const int& j) -> bool {
    if (i <= 0) {
      if (j <= 0) {
        return true;
      }
      return dp[0][j];
    } else {
      if (j <= 0) {
        return dp[i][0];
      }
    }
    return dp[i][j];
  };

  // dp
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 && j == 0) {
        dp[0][0] = true;
        continue;
      }
      if (get_index_val(i - 1, j) && (i - 1 >= 0) ? s1[i - 1] == res[i + j - 1]
                                                  : false) {

        dp[i][j] = true;
      } else if (get_index_val(i, j - 1) && (j - 1 >= 0)
                     ? s2[j - 1] == res[i + j - 1]
                     : false) {
        dp[i][j] = true;
      }
    }
  }
  return dp[m][n];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string s1;
  std::string s2;
  std::string res;
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  std::getline(std::cin, res);
  printf("%s: Input: s1 = %s   s2 = %s   s3 = %s\n", __func__, s1.c_str(),
         s2.c_str(), res.c_str());
  printf("%s: Input: solution %s\n", __func__,
         Solve(s1, s2, res) ? "true" : "false");
  return 0;
}

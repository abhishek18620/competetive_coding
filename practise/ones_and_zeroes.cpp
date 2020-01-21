// https://leetcode.com/problems/ones-and-zeroes/
/*
 * This question seemed to have wrong TCs or I did not understand the problem
 * completely
 * 5 3 4
 * 10
 * 0001
 * 111001
 * 1
 * 0
 *
 * 3 zeroes and 4 ones is only possible using 3rd and 5th string
 * Though 4 zeroes and 3 ones can be constructed using 1st , 2nd, 4th
 */

#include <iostream>
#include <vector>

int Solve(const std::vector<std::string>& arr, const int& m, const int& n) {
  const int        sz = arr.size();
  std::vector<int> zeroes_cnt(sz);
  std::vector<int> ones_cnt(sz);
  int              total_zeroes = 0;
  int              total_ones   = 0;
  // zeroes and ones cnt
  for (int i = 0; i < sz; ++i) {
    for (auto& ch : arr[i]) {
      if (ch == '0') {
        zeroes_cnt[i]++;
      } else {
        ones_cnt[i]++;
      }
    }
    total_zeroes += zeroes_cnt[i];
    total_ones += ones_cnt[i];
  }
  std::vector<std::vector<std::vector<int>>> dp(
      sz + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1)));

  auto check_last_state = [&](const int& i, const int& m, const int& n) {
    if (m < 0 || n < 0) {
      return -1;
    }
    if (dp[i][m][n] == 0) { // writting this one separately to avoid seg fault
      // 0 means not possible
      return -1;
    }
    // printf("%s: state(%d, %d, %d) = %d\n", __func__, i, m, n, dp[i][m][n]);
    return dp[i][m][n];
  };
  int sol        = 0;
  int last_state = 0;
  // it is possible that m < total zeroes in the first string same for ones
  if (zeroes_cnt[0] <= m && ones_cnt[0] <= n) {
    dp[0][zeroes_cnt[0]][ones_cnt[0]] = 1;
  }
  for (int i = 1; i < sz; ++i) {
    dp[i][zeroes_cnt[i]][ones_cnt[i]] = 1;
    for (int zeroes = 0; zeroes <= std::min(m, total_zeroes); ++zeroes) {
      for (int ones = 0; ones <= std::min(n, total_ones); ++ones) {
        if (!ones && !zeroes)
          continue;
        last_state = check_last_state(i - 1, zeroes - zeroes_cnt[i], ones - ones_cnt[i]);
        dp[i][zeroes][ones] =
            std::max(last_state != -1 ? last_state + 1 : 0, dp[i - 1][zeroes][ones]);
        if (dp[i][zeroes][ones] == 0) {
          // This is for creating a string using the ith string only
          if (zeroes_cnt[i] == zeroes && ones_cnt[i] == ones) {
            dp[i][zeroes][ones] = 1;
          }
        }
      }
    }
    printf("%s: dp[%d][%d][%d] = %d\n", __func__, i, m, n, dp[i][m][n]);
    sol = std::max(sol, dp[i][m][n]);
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int sz;
  int m;
  int n;
  scanf("%d %d %d", &sz, &m, &n);
  printf("%s: Input: sz = %d  m = %d  n = %d\n", __func__, sz, m, n);
  std::vector<std::string> arr(sz);
  std::getline(std::cin, arr[0]);
  for (auto& ele : arr) {
    std::getline(std::cin, ele);
    printf("%s  ", ele.c_str());
  }
  printf("\n");
  printf("%s: soluton = %d\n", __func__, Solve(arr, m, n));
  return 0;
}

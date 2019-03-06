// Q) Longest Palindromic sequence
/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-03-04
 *  File : leetcode2.cpp
 *******************************************/
#pragma comment(linker, "/ STACK: 100000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//-------------------------MACROS-------------------------------
#define trace2(x, y)                                                           \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                        \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << std::endl;
#define trace4(a, b, c, d)                                                     \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                  \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << std::endl;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

// state(i, j) = longest substring in str(i,j)


int solve(std::string &str) {
  int n = str.length();
  int dp[n+1][n+1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 1;
  }

  for (int sublen = 2; sublen <= n; ++sublen) {
    for (int i = 0; i < n - sublen + 1; ++i) {
      int j = i + sublen - 1;
      if(str[i] == str[j] and sublen == 2) {
        dp[i][j] = 2;
      }
      if(str[i] == str[j]) {
        // trace3(i+1, j-1, dp[i+1][j-1]);
        dp[i][j] = dp[i+1][j-1] + 2;
        // trace3(i, j, dp[i][j]);
      }
      else {
        dp[i][j] = std::max(dp[i][j-1], dp[i+1][j]);
      }
    }
  }
  return dp[0][n-1];
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  // freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
  std::string str;
  std::cin >> str;
  std::cout << solve(str) << std::endl;
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

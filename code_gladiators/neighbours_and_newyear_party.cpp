/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-04-17
 *  File : neighbours_and_newyear_party.cpp
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

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  int t;
  scanf("%d", &t);
  std::vector <int> houses(10009);
  std::vector <std::pair<int, int> > dp(10009);
  while(t--){
    int n;
    scanf("%d", &n);
    houses[0] = 0;
    bool allnegative = true;
    int max_ele = -1001;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &houses[i]);
      if(allnegative and houses[i] > 0) {
        allnegative = false;
      }
      if(houses[i] != 0) {
        max_ele = std::max(max_ele, houses[i]);
      }
    }
    if(allnegative) {
      printf("%d\n", max_ele);
      continue;
    }
    dp[0].first = 0;
    dp[0].second = 0;
    dp[1].first = (houses[1] < 0) ? 0:houses[1];
    dp[1].second = (houses[1] < 0) ? 0:1;
    for (int i = 2; i <= n; ++i) {
      if(houses[i] == 0) {
        // cannot be considered, Unlucky mate!!
        dp[i] = dp[i-1];
        continue;
      }
      if(houses[i] < 0) {
        dp[i] = dp[i-1];
        continue;
      }
      int ifpicked_i = dp[i-2].first + houses[i];
      int ifnotpicked_i = dp[i-1].first;
      if(ifpicked_i > ifnotpicked_i) {
        // picking i gives greater sum
        dp[i].first = ifpicked_i;
        dp[i].second = i;
      }
      else {
        // not pucking i gives more sum
        dp[i].first = ifnotpicked_i;
        dp[i].second = i-1;
      }
    }
    // calculate solution
    for(int i = n; i > 0; --i) {
      if(dp[i].second == 0) {
        break;
      }
      if(dp[i].second == i) {
        // pick i
        printf("%d", houses[i]);
        --i;
      }
      else {
        // don't pick i
        continue;
      }
    }
    printf("\n");
  }
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-07-07
 *  File : Spaceship.cpp
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

struct coordinate {
  int x, y;
};

int n;
int cost[100];
int direct_path = 0;
coordinate start, des;
coordinate warmhole[100][2];

inline int absolute(int x) {
  if(x < 0) {
    return -1 * x;
  }
  return x;
}

inline int min(int x, int y) {
  if(x < y) {
    return x;
  }
  return y;
}

int distance(coordinate &src, coordinate &des) {
  return absolute(src.x - des.x) + absolute(src.y - des.y);
}

int solve(coordinate src, coordinate des, int dis_travelled, int warmhole_choosen) {
  if (src.x == des.x and src.y == des.y) {
    // destination reached
    return 0;
  }
  if(dis_travelled >= direct_path) {
    return distance(src, des);
  }
  int ans = 9999999;
  // go without taking any warmhole
  int local_ans = distance(src, des);
  // if already in a warmohole
  for (int i = 0; i < n; ++i) {
    if (i == warmhole_choosen) {
      continue;
    }
    // from surrent to entry of the ith wormhole
    int dis = distance(src, warmhole[i][0]) + cost[i];
    if(dis >= local_ans) {
      return local_ans;
    }
    ans = min(ans, dis + solve(warmhole[i][1], des, dis_travelled + dis, i));
  }
  return min(ans, local_ans);
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  std::cin >> n;
  std::cin >> start.x >> start.y >> des.x >> des.y;
  for (int i = 0; i < n; ++i) {
    std::cin >> warmhole[i][0].x >> warmhole[i][0].y >> warmhole[i][1].x >> warmhole[i][1].y >> cost[i];
  }
  direct_path = distance(start, des);
  int ans = 0;
  int warmhole_choosen = -1;
  std::cout << solve(start, des, ans, warmhole_choosen) << std::endl;
  // Logic goes here

#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

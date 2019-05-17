/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-05-18
 *  File : AmazonProb2.cpp
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

int n, m;

void solve() {
  std::vector<int> tree[n+1];
  std::vector<int> level(n+1);
  std::vector<int> depth[n+1];
  level[1] = 0;
  int max_depth = 0;
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    std::cin >> u >> v;
    tree[u].push_back(v);
    level[v] = level[u] + 1;
    max_depth = std::max(level[v], max_depth);
    depth[level[v]].push_back(v);
  }
  /*for (int query = 0; query < m; query++) {*/
    //int L, X;
    //std::cin >> L >> X;
    //std::cout << sol[L%int(log2(max_depth))] << std::endl;
  /*}*/
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
  std::cin >> n >> m;
  solve();
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

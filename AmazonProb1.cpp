/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-05-18
 *  File : AmazonProb1.cpp
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

int n, q;

void solve() {
  std::vector<int> arr;
  std::vector<bool> repeated;
  repeated.resize(q+1);
  for (int query = 0; query < q; query++) {
    //trace2(query, n)
    int ele;
    std::cin >> ele;
    int l = std::lower_bound(arr.begin(), arr.end(), ele) - arr.begin();
    //trace2(ele, l);
    arr.insert(arr.begin() + l, ele);
    if(query > 0 and arr[l] == arr[l+1]) {
      repeated[l] = repeated[l+1] = true;
    }
        // find sum
    long long ans = 0;
    for (int i = 1; i < query+1; ++i) {
      if(!repeated[i]) {
        //trace2(repeated[i], ans);
        ans += arr[i-1] + 1;
      }
      if(!repeated[i-1]) {
        //trace2(repeated[i-1], ans);
        ans += arr[i] - 1;
      }
      /*if(arr[i] != arr[i-1]) {*/
        //ans += arr[i] - 1;
        //ans += arr[i-1] + 1;
      /*}*/
    }
    if (query == 0) {
      ans = n + 1;
    } else {
      if (!repeated[0]) {
        // trace2(repeated[0], ans);
        ans = ans + 1;
      }
      if (!repeated[query]) {
        // trace2(repeated[query], ans);
        ans += n;
      }
    }

    std::cout << ans << std::endl;
  }
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("random_input.txt", "rt", stdin);
  freopen("output.txt","w",stdout);
#endif
  std::cin >> n >> q;
  // Logic goes here
  solve();
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

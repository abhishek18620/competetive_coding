/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-01-24
 *  File : RegularExpression.cpp
 *******************************************/
#pragma comment(linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
#define INF 999999
#define fio                                                                    \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb push_back
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n", t)
#define printl(t) printf("%lld\n", t)
#define printstr(t) printf("%s\n", t.c_str())
#define trace2(x, y)                                                           \
  cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                                                        \
  cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << endl;
#define trace4(a, b, c, d)                                                     \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)                                                  \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifdef LOCAL_DEFINE
#include <assert.h>
#else
#define debug(args...) // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
const double EPS = 1e-6;

int scanstr(char *str) {
  register char c = getchar();
  register int len = 0;
  if (!(~c))
    return -1;
  while (c < 33 && ~c)
    c = getchar();
  while (c != 10 && c != 32 && ~c) {
    str[len] = c;
    c = getchar();
    len++;
  }
  str[len] = '\0';
  return 1;
}
void writel(ll n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  ll i = 10;
  char output_buffer[11];
  output_buffer[10] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
int power(int x, unsigned int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1)
      res = res * x;

    y = y >> 1;
    x = x * x;
  }
  return res;
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here

#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
  // cin>>t;
#endif
  return 0;
}

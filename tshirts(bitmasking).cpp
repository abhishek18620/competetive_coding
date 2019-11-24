// TEMPLATE //
// ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
// YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
// MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER
// ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio                                                                    \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test                                                                   \
  int t;                                                                       \
  scan(t);                                                                     \
  while (t--)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb push_back
using namespace std;

// GLOBALS
const ll MOD = 1e9 + 7;
ll dp[1 << 10][102];
bool a[12][102];

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

void scan(int &x) {
  register int c = gc();
  x = 0;
  for (; c < 48 || c > 57; c = gc())
    ;
  for (; c > 47 && c < 58; c = gc())
    x = (x << 1) + (x << 3) + c - 48;
}

void scanl(ll &x) {
  register ll c = gc();
  x = 0;
  for (; c < 48 || c > 57; c = gc())
    ;
  for (; c > 47 && c < 58; c = gc())
    x = (x << 1) + (x << 3) + c - 48;
}

int main() {
  // fio;
  int n, te, mask, num;
  test {
    scan(n);
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    // take input as string
    f(i, 1, n + 1) {
      string s, out;
      stringstream ss;
      getline(cin, s);
      ss << s;
      while (ss >> out) {
        stringstream convert(out);
        convert >> te;
        a[i][te] = 1;
      }
    }

    // DP begins
    // dp(i,j)=j tshirts been alredy alloted
    // bitmask of i (indexes having 1 are already alloted a tshirt as order
    // doesn't matter)
    dp[0][0] = 1;
    f(i, 0, 1 << n) {
      f(j, 1, 101) { dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD; }
      // now need to check which bits are set in bitset of i
      // which are still left to be alloted
      f(j, 1, n + 1) {
        // if(j th bit is set in i)
        bool set = i & (1 << (j - 1));
        if (!set) {
          mask = i | (1 << (j - 1));
          f(k, 1, 101) {
            if (a[j][k]) // checking if tshirt k is available for person j
              dp[mask][k] = (dp[mask][k] + dp[i][k - 1]) % MOD;
          }
        }
      }
    }
    writel(dp[(1 << n) - 1][100]);
  }
  cin >> t;
  return 0;
}

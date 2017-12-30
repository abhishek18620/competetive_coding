///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Dec 30 2017               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#pragma comment(linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
#define INF 999999
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test \
    int t;   \
    scan(t); \
    while (t--)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb push_back
#define error(args...)                         \
    {                                          \
        vector<string> _v = split(#args, ','); \
        err(_v.begin(), args);                 \
    }
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
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it, s) f(auto it \
                       : s)
#define foreach(v, c) f(__typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define foreachr(v, c) f(__typeof((c).rbegin()) v = (c).rbegin(); v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#ifdef LOCAL_DEFINE
#include <assert.h>
#else
#define debug(args...) // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d)   \
    if ((d) >= MOD) \
        d %= MOD;
#define MODNEGSET(d) \
    if ((d) < 0)     \
        d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) \
    if ((d) >= MOD)  \
        d -= MOD;
#define MODADDWHILESET(d) \
    while ((d) >= MOD)    \
        d -= MOD;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

int scanstr(char *str)
{
    register char c = getchar();
    register int len = 0;
    if (!(~c))
        return -1;
    while (c < 33 && ~c)
        c = getchar();
    while (c != 10 && c != 32 && ~c)
    {
        str[len] = c;
        c = getchar();
        len++;
    }
    str[len] = '\0';
    return 1;
}

int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;

        y = y >> 1;
        x = x * x;
    }
    return res;
}
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt", "rt", stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    map<string, int> a;
    a["mon"] = 0;
    a["tues"] = 1;
    a["wed"] = 2;
    a["thurs"] = 3;
    a["fri"] = 4;
    a["sat"] = 5;
    a["sun"] = 6;
    while (t--)
    {
        int n, i, j;
        string s;
        cin >> n >> s;
        int b[7] = {0};
        f(i, 0, 7)
            b[i] = 4;
        if (n == 28)
        {
            f(i, 0, 7)
                    cout
                << b[i] << " ";
        }
        if (n == 29)
        {
            int x = a[s];
            b[x]++;
            f(i, 0, 7)
                    cout
                << b[i] << " ";
        }
        else if (n == 30)
        {
            int x = a[s];
            b[(x) % 7]++;
            b[(x + 1) % 7]++;
            f(i, 0, 7)
                    cout
                << b[i] << " ";
        }
        else if (n == 31)
        {
            int x = a[s];
            b[(x) % 7]++;
            b[(x + 1) % 7]++;
            b[(x + 2) % 7]++;
            f(i, 0, 7)
                    cout
                << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
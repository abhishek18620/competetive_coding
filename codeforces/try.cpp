#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
 
#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
 
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 
typedef long long int slong;
 
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
#ifdef VSP4 
    #include "debug.h"    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif
 
const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
 
const int MAXN = 500;
const int SQRTN = 650;
const int LOGN = 60;
const int INT_INFINITY = 1001001001;
 
const slong LONG_INFINITY = 1001001001001001001ll;
const slong LONG_LIMIT = 200100100100101ll;
 
const slong MAX_LIMIT = 1000000000000000000ll;
 
const int LIMIT = 1e6;
 
string str;
 
int main()
{
    freopen("INP.txt","rt",stdin);
    //freopen("output.txt", "w", stdout);
    
    clock_t begin = clock();
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t, i, j, u, v, type;
    string str;
 
    cin >> t;
 
    while (t--)
    {
        cin >> str;
 
        slong ans = 0;
 
        for (i = 0; i < str.size();)
        {
            //i-1 is different character
 
            int uptil = i;
 
            for (j = i; j < str.size(); j++)
            {
                if (str[j] == str[i])
                {
                    uptil = j;
                }
                else
                {
                    break;
                }
            }
 
            int size = uptil-i+1;
 
            ans += 1ll*size*(size+1)/2 - size; //this current
 
            if ((i-1) >= 0 && (uptil+1) < str.size())
            {
                if (str[(i-1)] == str[uptil+1])
                {
                    ans++; //middle string
                }
            }
 
            i = uptil+1;
        }
 
        cout << ans << "\n";
 
    }
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
 
    cerr << elapsed_secs;
    
    return 0;
}
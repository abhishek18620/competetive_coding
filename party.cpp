///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sun Nov 26 2017               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#include <bits/stdc++.h>
using namespace std;
#define M 1000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it,s) for(auto it: s)
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define foreachr(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

#ifdef LOCAL_DEFINE
    #include<assert.h>
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

int scanstr(char *str)
{
    register char c = getchar();
    register int len = 0;
    if(!(~c)) return -1;
    while(c < 33 && ~c) c = getchar();
    while(c != 10 && c != 32 && ~c){
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
            res = res*x;

        y = y>>1; x = x*x;
    }
    return res;
}
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
int parties[109][2],dp[109][509];

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int budget,party;
    scan2(budget,party);
    while(budget>0 or party>0)
    {
        f(i,1,party+1)
            scan2(parties[i][0],parties[i][1]); //cost , fun
        f(i,0,party+1)
            f(j,0,budget+2)
                dp[i][j]=0;

        f(i,1,party+1)
        {
            int cost=parties[i][0];
            int fun=parties[i][1];
            f(j,1,budget+1)
            {
                if(cost<=j)
                {
                    dp[i][j]=max(dp[i-1][j-cost]+fun,dp[i-1][j]);
                    // // if fun is greater
                    // if(dp[i-1][j-cost].F+fun>dp[i-1][j].F)
                    // {
                    //     dp[i][j]=mp(dp[i-1][j-cost].F+fun,dp[i-1][j-cost].S+cost);
                    // }
                    // else if (dp[i-1][j-cost].F+fun<dp[i-1][j].F)
                    // {
                    //     dp[i][j]=dp[i-1][j];
                    // }
                    // else    // fun are equal
                    // {
                    //     dp[i-1][j]=mp(dp[i-1][j].F,min(dp[i-1][j-cost].S+cost,dp[i-1][j].S));
                    // }
                }
                else
                    dp[i][j]=dp[i-1][j];    
            }
        }
        int solfun=dp[party][budget],solbudget=0;
        f(i,1,budget+1)
        {
//            printf("budget %d =  %d %d\n",i,dp[party][i].S,dp[party][i].F);
            if(dp[party][i]==solfun)
            {
                solbudget=i;
                break;
            }
        }
        printf("%d %d\n",solbudget,solfun);
        scan2(budget,party);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int n;
        cin>>n;
    #endif
    return 0;
}

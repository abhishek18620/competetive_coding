// DYNAMIC PROGRAMMING ( DP with  BINARY SEARCH)
// GRID
///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Nov 18 2017               //
///////////////////////////////////////////
// It's my template. Don't steal it ;)
#include <bits/stdc++.h>
using namespace std;
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
#define viter(s) for (auto it: s)
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

#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
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
const int M = 10;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;
int readStr(char *str)
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

//GLOABLS
int n,m,l,r,dp[32][M];
char str[32][M];

int rec_Bsearch(int x, int y, int lim)
{
    int tot=0;
    f(i,1,n+1)
    {
        int lo=y,hi=m,mid,recs,sol=y-1;
        while(hi>=lo)
        {
            recs=0;
            mid=lo+((hi-lo)>>1);
            //recs between (x,y,i,mid)
            recs=dp[i][mid]-(dp[x-1][mid]+dp[i][y-1])+dp[x-1][y-1];
            if(recs>lim)
                hi=mid-1;
            else
            {
                lo=mid+1;
                sol=mid;
            }
        }
        tot+=(sol-y+1);
    }
    return tot;
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    scan2(n,m);
    f(i,1,n+1)
        readStr(&str[i][1]);
    scan2(l,r);
    //state(i,j) = numbers of ones in rectangle 0,0 to i,j
    memset(dp,0,sizeof(int)*(m+2)*(n+2));
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(str[i][j]=='1');
        }
    }
    int sol=0;
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            sol+=rec_Bsearch(i,j,r);
            sol-=(l>0)?rec_Bsearch(i,j,l-1):0;
        }
    }
    print(sol);
    //we can look for every subrectangle possible between 4 points
    //which would take O(m^2*n^2) so a special optimisation
    //look for rectangles having (l-1) 1s and (r) 1s
    //solution would be recs(r)-recs(l-1)
    //this does look like interval searching ,canbe done with bsearch apparently

    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
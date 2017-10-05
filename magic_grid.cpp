///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 509
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define gc getchar_unlocked
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
//#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;
//GLOBALS
const int INF= 1e9+7;
int dp[SZ][SZ],a[SZ][SZ],r,c;

void scan(int &x){
    register int c = gc();
    bool neg=0;
    x=0;
    for(;c<48 || c>57;c=gc())
        if(c=='-')
        {
            neg=1;
            c=gc();
            break;
        }
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
    x*=(neg)?-1:1;
}

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("input.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    while(t--)
    {
        scan(r); scan(c);
        f(i,0,r)
            f(j,0,c)
                scan(a[i][j]);
        dp[r-1][c-1]=1;
        int x;
        fr(j,c-2,0)
        {
            x=dp[r-1][j+1]-a[r-1][j];
            dp[r-1][j]=(x>=1)?(x):(1);
        }
        fr(i,r-2,0)
        {
            x=dp[i+1][c-1]-a[i][c-1];
            dp[i][c-1]=(x>=1)?(x):(1);
        }
        fr(i,r-2,0)
            fr(j,c-2,0)
            {
                x=min(dp[i+1][j],dp[i][j+1])-a[i][j];
                dp[i][j]=(x>=1)?(x):(1);
            }
        //f(i,0,r){ f(j,0,c) cout<<dp[i][j]<<' '; cout<<'\n'; }
        print(dp[0][0]);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>c;
    #endif
    return 0;
}

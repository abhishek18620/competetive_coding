///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 104
#define INF 1e9+7
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;

//Globals
int dp[M][M],n,m,u,v,d,p;

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/C-small-practice.in","rt",stdin);
    freopen("./kickstart/output.txt","w",stdout);
    #endif
    int t; scan(t);
    int tt=1;
    while(t--)
    {
        scan(n); scan(m); scan(p);
        f(i,0,n+1)
            f(j,0,n+1)
                dp[i][j]=INF;
        f(i,0,n+1)
            dp[i][i]=0;
        f(i,0,m)
        {
            scan(u); scan(v); scan(d);
            u--; v--;
            dp[u][v]=dp[v][u]=d;
        }
        //floyd warshall
        f(k,0,n)
        {
            f(i,0,n)
            {
                f(j,0,n)
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
        double te1=0,te=0;
        f(i,1,n)
            te1+=dp[0][i];
        f(i,1,n)
        {
            f(j,0,n)
                te+=dp[i][j];    
        }
        double p1 = p-1, r = -1.0/float(n-1);
        p1+=(1.0/(n-1))*(1-pow(r,p-2))/(1-r);
        if(p%2==0)
            p1 = p1 + pow(1.0/(n-1),p-1);
        else
            p1 = p1 - pow(1.0/(n-1),p-1);
        p1 = (p1*(n-1))/n;
        double p2 = p - p1;
        double ans = (p1*te)/((n-1)*(n-1)) + (p2*te1)/(n-1);
        printf("Case #%d: %.9lf\n",tt++,ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

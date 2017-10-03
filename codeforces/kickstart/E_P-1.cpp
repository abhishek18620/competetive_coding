///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 300
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
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;

//GLOBALS
int valid[M][M][M],dp[M][M][M],ans[M],t;
char s[M];
int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/INP_l.in","r",stdin);
	freopen("./kickstart/output.txt","w",stdout);
    #endif
    scan(t);
	f(tt,1,t+1)
	{
		scanf("%s",(s+1));
		int n=strlen(s+1);
		CLR(valid);
		f(i,1,n+1)
			f(j,i+1,n+1)
				valid[i][i][j]=(s[i]==s[j]);
		f(len,2,n+1)
			for(int i=1;i+len-1<n+1;i++)
				for(int j=i+len;j+len-1<n+1;j++)
					valid[i][i+len-1][j]=(valid[i][i+len-2][j]&(s[i+len-1]==s[j+len-1]));
		
        f(i,0,n+1)
        {
            ans[i]=INF;
		    f(j,0,n+1)
		        f(k,0,n+1)
                    dp[i][j][k]=INF;
        }
                    
		dp[0][1][0]=0;
		ans[0]=1;
        
        //DP begins
		f(i,1,n+1)
		{
			dp[i][1][0]=dp[i-1][1][0]+1;
			ans[i]=dp[i][1][0];
            f(j,1,i)
            {
				for(int k=j;k+(k-j+1)<=i;k++)
				{
					dp[i][j][k]=dp[i-1][j][k]+1;
					if(valid[j][k][i-(k-j)])
					{
						dp[i][j][k]=min(dp[i][j][k],dp[i-(k-j+1)][j][k]+1);
						dp[i][j][k]=min(dp[i][j][k],ans[i-(k-j+1)]+2);
					}
					ans[i]=min(ans[i],dp[i][j][k]);
                }
            }
		}
		printf("Case #%d: %d\n",tt,ans[n]);
    }
    #ifdef LOCAL_DEFINE
    cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
    int m;
    cin>>m;
    #endif
}
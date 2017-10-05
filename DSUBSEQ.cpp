///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 100010
#define INF 1e17
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

const int mod=1000000007;
char str[SZ];
int last[30],dp[SZ];

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("input.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    gets(str);
    while(t--)
    {
        fill(last,last+27,-1);
        gets(str+1);
        int n=strlen(str+1);
        char ch;
        dp[0]=1;
        f(i,1,n+1)
        {
            int ch=str[i];
            int prv_occ=last[ch-'A'];
            dp[i]=(dp[i-1]*2)%mod;    
            if(prv_occ!=-1)    //it has occured before
                dp[i] = (dp[i] - dp[last[ch-'A'] - 1] + mod)%mod;
            last[ch-'A']=i;
        }
        print(dp[n]);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

/******************************************
*  Author : wshek
*  Created On : Sun Oct 15 2017
*  File : 440C.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 1000000009
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
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

bool isprime[M];
int dp[M];
void optimised_sieve()
{
    memset(isprime,1,sizeof(isprime));
    for(int i = 2; i * i<= M; i++)
    {
        if (isprime[i])
        {
            for(int j = i * i; j<= M; j+=i) 
                isprime[j] =0;
        }
    }
}

int main()
{
	fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    optimised_sieve();
    int n; scan(n);
    memset(dp,0,sizeof(dp));
    dp[1]=0;
    dp[2]=0;
    dp[3]=0;
    dp[4]=0;
    f(i,4,M)
    {
        f(i,4,M)
        {
            int div=n/i;
            int rem=n%i;
            if(dp[rem]!=0)
            {
                dp[i]=div+dp[rem];
            }
        }
    }
    int te;
    f(i,0,n)
    {
        scan(te);
        if(dp[i]==0)
            print(-1);
        else
            print(dp[te]);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

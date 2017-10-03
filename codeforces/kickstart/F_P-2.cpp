///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 100
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

// bool isempty(int l ,int r)
// {
//     f(i,rear,fr)
//     {
//         if(que[i]!=0)
//             return 0;
//     }
//     return 1;
// }

// void rec(int pos,int skill,int l, int r)
// {
//     if(dp[pos]!=-1)
//         return dp[pos][];
//     else
//     {
//         dp[pos]=max(dp[])
//     }
// }

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/B-large-practice.in","rt",stdin);
    freopen("./kickstart/output.txt","w",stdout);
    #endif
    int t,tt=1; scan(t);
    int n,e,a[1009];
    while(t--)
    {
        scan(e); scan(n);
        f(i,0,n)
            scan(a[i]);
        sort(a,a+n);
        int ans=0,sol=0,curr=e,i=0,j=n-1;
        while(i<=j)
        {
            if(curr>a[i])
            {
                sol++;
                curr-=a[i];
            }
            else    //energy gaining from avilable max
            {
                if(sol>0 and i<j)
                {
                    curr+=a[j]-a[i];
                    j--;
                }
            }
            i++;
        }
        printf("Case #%d: %d\n",tt++,sol);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

/******************************************
*  Author : wshek   
*  Created On : Tue Sep 26 2017
*  File : 436D.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 10000
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
#define write(t) printf("%d\n",t)
#define writel(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

struct nodes
{
    int t,d,p,ind;
};
bool comp(const nodes &lhs, const nodes &rhs)
{
  return lhs.d < rhs.d;
}

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n;
    scan(n);
    nodes node[n+1];
    int dp[n+1][2009];
    vector<int> recons;
    f(i,0,n)
    {
        scan(node[i].t);
        scan(node[i].d);
        scan(node[i].p);
        node[i].ind=i+1;
    }
    sort(node,node+n,comp);
    int nmax=node[n-1].d;
    memset(dp,0,sizeof(dp));
    //dp[0][nodet[0]]=node[0].p;    
    f(j,0,nmax)
    {
        if(j<node[0].d and j>=node[0].t)
        {
            //recons[j].insert(node[0].ind);
            dp[0][j]=node[0].p;
        }
    }
    f(i,1,n)
    {
        f(j,1,nmax+1)
        {
            if(j<node[i].d and j>=node[i].t) //item is still safe
            {
                if(dp[i-1][j-node[i].t]+node[i].p>=dp[i-1][j])
                {
                    dp[i][j]=dp[i-1][j-node[i].t]+node[i].p;
                    //recons[j]=recons[j-node[i].t];
                    //recons[j].insert(node[i].ind);    
                    //printf("pushing %d in %d \n",node[i].ind,j);
                }
                else //if(dp[i-1][j-t[i]]+p[i]<dp[i-1][j]))
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int sol=0,ind=0;
    f(i,0,nmax+1)
        if(dp[n-1][i]>sol)
        {    
            sol=dp[n-1][i];
            ind =i;
        }
    write(sol);
    // 0-1 knapsack reconstruction
    f(i,0,n)
    {
        f(j,1,nmax+1)
        {
            if(sol==dp[i][j])
            {
                int x=i,y=j,curr=sol;
                while(curr>0)
                {
                    if(dp[x-1][y]==curr)
                        x--;
                    else
                    {
                        recons.eb(node[x].ind);
                        curr-=node[x].p;
                        y-=node[x].t;
                        x--;
                    }
                }
                int lim=recons.size();
                printf("%d\n",lim);
                fr(i,lim-1,0)
                    printf("%d ",recons[i]);
                printf("\n");
                return 0;
            }
        }
    }
    
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

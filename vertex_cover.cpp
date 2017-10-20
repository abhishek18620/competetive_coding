/******************************************
*  Author : abhishek18620   
*  Created On : Tue Oct 17 2017
*  File : vertex_cover.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 10
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
#define eb emplace_back
using namespace std;
//GLOBALS
vector<int> GR[M];
int n,u,v,w;
int dp[M][2];
bool visited[M][2];

int fun(int st,int parent ,int skipped)
{
    //st can be choosen or skipped
    if(visited[st][skipped])
        return dp[st][skipped];
    int lim=GR[st].size();
    visited[st][skipped]=1;
    int sol=0;
    f(i,0,lim)
    {
        int v=GR[st][i];
        if(v==parent)
            continue;
        if(skipped==0)
            sol+=fun(v,st,1);
        else
            sol+=min(fun(v,st,0),fun(v,st,1));
            
    }
    sol+=skipped;
    dp[st][skipped]=sol;
    return sol;
}

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
    fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    while(scanf("%d",&n)==1)
    {
        memset(visited,0,sizeof(visited));
        f(i,0,n)
            GR[i].clear();
        f(i,0,n-1)
        {
            scan(u); scan(v);
            --u; --v;
            GR[u].eb(v);
            GR[v].eb(u);
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int ans=min(fun(0,-1,0),fun(0,-1,1));
        printf("%d\n",ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

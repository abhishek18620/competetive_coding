///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 1009
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

//Globals
int gr[M][M],col[M],n,m,u,v;
queue<int> que,emp;    

bool bipartite(int src)
{
    que.push(src);
    col[src]=1;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        f(i,0,n)
        {
            if(gr[v][i]==1 and col[i]==-1 and v!=i)
            {
                col[i]=1-col[v];
                que.push(i);
            }
            else if(gr[v][i]==1 and col[i]==col[v] and v!=i)
                return 0;
        }
    }
    return 1;
}

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("INP.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    while(t--)
    {
        scan(n); scan(m);
        f(i,0,n+1)
            f(j,0,n+1)
                gr[i][j]=1;

        f(i,0,m)
        {
            scan(u); scan(v);
            u--; v--;
            gr[u][v]=gr[v][u]=0;    //complementing
        }
        f(i,0,n)
            col[i]=-1;
        //bipartite or not
        bool ans=1;
        que=emp;
        f(i,0,n)
        {
            if(col[i]==-1)
            {
                if(!bipartite(i))
                {
                    ans=0;
                    break;
                }
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

//PRIM'S ALGORITHM
//MINIMUM SPANNING TREE(MST)
///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Thu Nov 16 2017                       //
///////////////////////////////////////////
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
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

typedef pair<int,int> pai;


bool comp(int x, int y)
{
    return x>y;
}

vector< pair<int,int> > GR[10];

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int m,n,u,v,w;
    scan(n); scan(m);   //vertices and edges
    f(i,0,m)
    {
        scan(u); scan(v); scan(w);
        GR[u].eb(mp(v,w));
        GR[v].eb(mp(u,w));
    }
    //priority queue
    priority_queue< pai,vector< pai >,greater<pai> > pq;
    int visited[10];
    int dis[10];
    f(i,0,10)
    {
        visited[i]=0;
        dis[i]=INF;
    }
    dis[0]=0;
    pq.push(mp(0,0));
    int cost=0;
    while(!pq.empty())
    {
        int u=pq.top().S;
        int w=pq.top().F;
        pq.pop();
        if(visited[u]==0)
        {
            visited[u]=1;
            cost+=w;
        }
        else
            continue;
        int lim=GR[u].size();
        f(i,0,lim)
        {
            int v=GR[u][i].F;
            int x=GR[u][i].S;
            if(dis[v]>x)
            {
                dis[v]=x;
                if(visited[v]==0)
                    pq.push(mp(dis[v],v));
            }
        }
    }    
    print(cost);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

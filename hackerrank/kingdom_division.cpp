///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Fri Jan 05 2018               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 100009
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
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define trace2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it,s) for(auto it: s)
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define foreachr(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#ifdef LOCAL_DEFINE
    #include<assert.h>
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

int scanstr(char *str)
{
    register char c = getchar();
    register int len = 0;
    if(!(~c)) return -1;
    while(c < 33 && ~c) c = getchar();
    while(c != 10 && c != 32 && ~c){
        str[len] = c;
        c = getchar();
        len++;
    }
    str[len] = '\0';
    return 1;
}

int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        y = y>>1; x = x*x;
    }
    return res;
}
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
int mulmod(int x,int y)
{
    ll te=1ll*(x%MOD) *1ll*(y%MOD);
    return te%MOD;
    //return ((1ll*(x%MOD) * (y%MOD))%MOD);
}


ll dp[M][2]; //state(root,owner 0=reggie 1=bettie)
ll inv[M][2]; // invalid states

struct Graph
{
    vector<int> adj[M];
    bool visited[M];
    vi order;
    void bfs(int root)
    {
        queue<int> qe;
        qe.push(root);
        while(!qe.empty())
        {
            int v=qe.front();
            qe.pop();
            if(visited[v])
                continue;
            visited[v]=1;
            order.eb(v);
            viter(u,adj[v])
            {
                if(!visited[u])
                    qe.push(u);
            }
        }
    }

    void AddEdge(int u,int v)
    {
        adj[v].eb(u);
        adj[u].eb(v);
    }
    void init(int n)
    {
        memset(visited,0,sizeof(visited));
        // f(i,0,n+2)
        //     adj[i].clear();
    }
};


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n,u,v;
    scan(n);
    Graph graph;
    graph.init(n);
    f(i,0,n-1)
    {
        scan2(u,v);
        graph.AddEdge(--u,--v);
    }
    graph.bfs(0);
    memset(graph.visited,0,sizeof(graph.visited));
    reverse(ALL(graph.order));

    viter(u,graph.order)
    {
        graph.visited[u]=1;
        // calculating invalid states
        // if(graph.adj[u].size()==1)    //leaf
        // {
        //     dp[u][0]=dp[u][1]=1;
        //     inv[u][0]=inv[u][1]=1;
        //     //visited[u]=1;
        //     continue;
        // }
        dp[u][0]=dp[u][1]=inv[u][0]=inv[u][1]=1;
        //calculating invalid states
        f(owner,0,2)
        {
            viter(v,graph.adj[u])
            {
                if(graph.visited[v])
                    inv[u][owner]=(inv[u][owner]*dp[v][!owner])%MOD;
            }
        }
        //dp
        f(owner,0,2)
        {
            int sub=1;
            int ctr=0;
            viter(v,graph.adj[u])
            {
                if(graph.visited[v])
                {
                    dp[u][owner]=(dp[u][owner]*(inv[v][owner]+dp[v][owner]+dp[v][!owner]))%MOD;  //total combs
                    //trace2(owner,!owner);
                    //sub=mulmod(sub,dp[v][!owner]);
                }
            }
            dp[u][owner]-=inv[u][owner];
            if(dp[u][owner]<0) dp[u][owner]+=MOD;
        }
    }
    // int ans=0;
    // f(i,0,n)
    // {
    //     int v=graph.order[i];
    //     trace2(v,(dp[v][0]+dp[v][1])%MOD);
    //     //ans=max(ans,dp[graph.order[i]][0]+dp[graph.order[i]][1]);
    // }
    ll sol=(dp[0][0]+dp[0][1])%MOD;
    printl(sol);
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

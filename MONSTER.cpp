///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Fri Jan 12 2018               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
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
#define trace2(x, y)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
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
const int M = (1<<17)+2;
vi health;
int alive;
int done=0;

void uffff(int x)
{
        if(done[x]==cnt or sol<=0)
            return;
        done[x]=cnt;
        if(x<n)
        {
            if(a[x]>0)
            {
                a[x]-=y;
                if(a[x]<=0) sol--;
            }
        }
        for(int iBit=0;iBit<=18;iBit++)
        {
            if(x & (1<<iBit)) //ith bit is set
            {
                //u=v^(1<<iBit); //unset ith bit
                //an edge from u-->v
                uffff(x^(1<<iBit));
            }
        }
}


struct Graph
{
    int vertices;
    vector<vi> adj;
    vi visited;
    int sz;
    void dfs(int x, int y)
    {
        stack<int> st;
        st.push(x);
        while(!st.empty())
        {
            int u=st.top();
            visited[u]=done;
            if(health[u]>0)
            {
                health[u]-=y;
                if(health[u]<=0) alive--;
            }
            st.pop();
            viter(v,adj[u])
            {
                if(visited[v]!=done) st.push(v);
            }
        }
    }

    void AddEdge(int u,int v)
    {
        adj[v].eb(u);
        //adj[u].eb(v);
    }

    void create_graph();

    void init(int n)
    {
        adj.resize(M+1);
        vertices=n;
        sz=1;
        int te=n;
        while(te>>1)
        {
            sz++,te>>=1;
        }
        visited.resize(M+2);
        create_graph();
        //memset(visited,0,sizeof(visited));
    }
};

void Graph::create_graph()
{
    int u,v;
    f(v,0,M+1)
    {
        fr(iBit,16,0)
        {
            if(v & (1<<iBit)) //ith bit is set
            {
                u=v^(1<<iBit); //unset ith bit
                //an edge from u-->v
                if(u!=0) AddEdge(u,v);
            }
        }
    }
}


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n;
    scan(n);
    alive=n;
    health.resize(n+2);
    bool sub2=1;
    f(i,0,n)
    {
        scan(health[i]);
        if(sub2 and health[i]!=1) sub2=0;
    }
    // Graph graph;
    // graph.init(n-1);
    int q,x,y,u,v; scan(q);
    if(!sub2)
    {
        f(que,0,q)
        {
            scan2(x,y);
            if(health[0]>0)
            {
                health[0]-=y;
                if(health[0]<=0) alive--;
            }
            f(k,1,x+1)
            {
                if((k&x)==k)
                {
                    if(health[k]>0)
                    {
                        health[k]-=y;
                        if(health[k]<=0) alive--;
                    }
                }
            }
            print(alive);
        }
        return 0;
    }
    vector<bool> visited(10000002);
    stack<int> st;
    f(que,1,262144)
    {
        scan2(x,y);
        if(alive<=0)
        {
            print(alive);
            continue;
        }
        st.push(x);
        if(x<=1000000)
            if(visited[x])  continue;//already visited
        int te=x;
        int till=1;
        while(te>>1)
        {
            till++;
            te>>=1;
        }
        while(!st.empty())
        {
            v=st.top();    
            visited[v]=1;
            if(health[v]>0) health[v]=0,alive--;
            if(alive<=0) break;
            st.pop();
            //trace2(v,alive);
            f(iBit,0,till+1)
            {
                if(v & (1<<iBit)) //ith bit is set
                {
                    u=v^(1<<iBit); //unset ith bit
                    if(u!=0)
                    {
                        if(u<=1000000)
                            if(visited[u]) continue;
                        st.push(u);
                    }
                }
            }   
        }
        print(alive);
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}



#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
#define trace2(x, y)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
using namespace std;

vector<int> a;
int done[1000002];
int q,x,y,u,v,sol,n,cnt=0;

void readint(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;c<48 || c>57;c=getchar_unlocked());
    for(;c>47 && c<58;c=getchar_unlocked())
        x=(x<<1)+(x<<3)+c-48;
}


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    readint(n);
    sol=n;
    a.resize(n+2);
    bool sub2=1;
    for(int i=0;i<n;i++)
    {
        readint(a[i]);
        //if(sub2 and a[i]!=1) sub2=0;
    }
    readint(q);
    for(int que=0;que<q;que++)
    {
        cnt++;
        readint(x);
        readint(y);
        if(x>262143)
            x=x&262143;
        uffff(x);
        printf("%d\n",sol);
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
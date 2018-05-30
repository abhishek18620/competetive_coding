/******************************************
*  Author : abhishek18620
*  Created On : 2018-05-31
*  File : LCA_dp.cpp
*******************************************/
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1009
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
void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
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

/*
    LCA using DP:
    state(node , j)= (2^j)th ancestor of node
    there will be depth , subtree's size for every node
*/

vector<vi> tree;
vi depth;
const int logN=12;
int pa[M][logN];

void dfs(int curr , int parent , int _depth)
{
    pa[curr][0]=parent;
    depth[curr]=_depth;
    //subsize[curr]=1;
    viter(child,tree[curr])
    {
        if(child!=parent)
        {
            dfs(child,curr,_depth+1);
            //subsize[curr]+=subsize[child];
        }
    }
}

int LCAquery(int u, int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    f(i,0,logN)
        if((diff>>i)&1) u=pa[u][i]; //just dividing diff by 2
    if(u==v) return u;

    fr(i,logN-1,0)
        if(pa[u][i]!=-1 and pa[u][i]!=pa[v][i])
            u=pa[u][i], v=pa[v][i];

    return pa[u][0];
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    f(tt,1,t+1)
    {
        printf("Case %d:\n",tt);
        int n;
        scan(n);
        tree.clear();
        depth.clear();
        //subsize.clear();
        tree.resize(n+1);
        depth.resize(n+1);
        //subsize.resize(n+1);
        f(u,0,n)
        {
            int m,v;
            scan(m);
            f(j,0,m)
            {
                scan(v); v--;
                tree[u].eb(v);
                tree[v].eb(u);
            }
        }
        memset(pa,-1,sizeof(pa));
        dfs(0,-1,0);
        //dp preprocess fo r LCA
        f(i,0,n)
        {
            f(j,1,logN)
                if(pa[i][j-1]!=-1)
                    pa[i][j]=pa[pa[i][j-1]][j-1];
        }

        int q; scan(q);
        f(i,0,q)
        {
            int u,v;
            scan2(u,v);
            u--; v--;
            print(LCAquery(u,v)+1);
        }
    }

    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        //cin>>t;
    #endif
    return 0;
}



///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Dec 30 2017               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
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

//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------

vector<pii> gr[M];
int dis[M];
bool visited[M];
queue<int> q,emp;
int n,src,des,X1,Y1,X2,Y2,X3,Y3;

int bfs()
{
    int tot=0;
    if(src>n or des>n or src<1 or des<1)
        return 0;
    q=emp;
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
	q.push(src);
    visited[src]=1;
	while(!q.empty())
	{
		int z = q.front();
        q.pop();
		int sz= gr[z].size();
        for(int i=0;i<sz;i++)
        {
            int v=gr[z][i].F;
            int w=gr[z][i].S;
            bool poss=0;
            if(visited[v])
            {
                continue;
            }
            else
            {
                q.push(v);
                visited[v]=1;
            }
            if(w%2==0) 
            {
                if( w>=X1 and w<=Y1)
                    poss=1;
                else poss=0;
            }
            if(w%3==0)
            {
                if(w>=X2 and w<=Y2)
                    poss=1;
                else poss=0;
            }
            if(w%5==0)
            {
                if(w>=X3 and w<=Y3)
                    poss=1;
                else poss=0;
            }
            if(poss)
            {
                tot+=w;
            }
            if(v==des)
            {
                return tot;
            }
        }
	}
    return tot;
 }


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int q,u,v,c;
    scan2(n,q);
    f(i,0,n-1)
    {
        scan3(u,v,c);
        gr[u].eb(mp(v,c));
        gr[v].eb(mp(u,c));
    }
    int last=0;
    int in[8];
    f(i,0,q)
    {
        f(j,0,8)
            scan(in[j]);

        src=in[0]+last;
        des=in[1]+last;
        X1=in[2]+last;
        Y1=in[3]+last;
        X2=in[4]+last;
        Y2=in[5]+last;
        X3=in[6]+last;
        Y3=in[7]+last;
        last=bfs();
        print(last);
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

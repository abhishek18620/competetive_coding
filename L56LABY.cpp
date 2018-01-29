///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : 2018-01-27                    //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
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
/*#define scan(d) scanf("%d", &d)*/
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
void scan(int &x)
{
    register int c = gc();
    bool neg=(c=='-')?1:0;
    x = 0;
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
    x*=(neg)?-1:1;
}


int grid[M][M],Time[M][M],n,m;
queue<pii> que;

bool valid(int x ,int y)
{
    if(x>=0 and x<m and y>=0 and y<n)
        return 1;
    return 0;
}

void bfs()
{
    f(x,0,m)
    {
        f(y,0,n)
        {
            if(grid[x][y]>0)
            {
                Time[x][y]=grid[x][y];
                que.push(mp(x,y));
            }
        }
    }
    while(!que.empty())
    {
        pii curr=que.front();
        que.pop();
        int x=curr.F , y=curr.S;
        if(Time[x][y]<0) continue;
        // Check if can enter and Time taken > 0
        if(valid(x-1,y) and grid[x-1][y]!=-1 and Time[x-1][y]< Time[x][y]-1)
        {
            Time[x-1][y]=Time[x][y]-1;
            que.push(mp(x-1,y));
        }
        if(valid(x,y+1) and grid[x][y+1]!=-1 and Time[x][y+1]< Time[x][y]-1)
        {
            Time[x][y+1]=Time[x][y]-1;
            que.push(mp(x,y+1));
        }
        if(valid(x+1,y) and grid[x+1][y]!=-1 and Time[x+1][y]< Time[x][y]-1)
        {
            Time[x+1][y]=Time[x][y]-1;
            que.push(mp(x+1,y));
        }
        if(valid(x,y-1) and grid[x][y-1]!=-1 and Time[x][y-1]< Time[x][y]-1)
        {
            Time[x][y-1]=Time[x][y]-1;
            que.push(mp(x,y-1));
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
    int t; scan(t);
    while(t--)
    {
        scan(m);
        scan(n);
        f(i,0,m)
            f(j,0,n) scan(grid[i][j]);
        memset(Time,-1,sizeof(Time));
        bfs();
        f(x,0,m)
        {
            f(y,0,n)
            {
                // cout<<Time[x][y]<<" ";
                if(grid[x][y]==-1) printf("B");
                else if(Time[x][y]>=0) printf("Y");
                else printf("N");
            }
            printf("\n");
        }
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>t;
    #endif
    return 0;
}

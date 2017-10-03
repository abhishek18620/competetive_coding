///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 100
#define INF 1e17
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
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

//GLOBALS
int n,m,u,v;
vector<int> TR[SZ];
ll a[SZ],q[SZ],level[SZ],xval[SZ],que[SZ];
//NOT REALLY A BIG FAN OF deque stl
//SO JUST IMPLEMENTED IT FROM SCRATCH
//BREADTH FIRST SEARCH
void BFS()
{
    f(i,0,n+1)
        level[i]=-1;
     //deletion and insertion respec.
     //high school stuff
    int front=0,rear=0;
    que[0]=level[0]=0;
    while(front<=rear)
    {
        int v=que[front++];
        for(int x:TR[v])
        {
            if(level[x]==-1)
            {
                level[x]=level[v]+1;
                rear++;
                que[rear]=x;
            }
        }
    }
}

void solve()
{
    BFS();
    int Lmax=0;
    f(i,0,n)
    {
        if(level[i]>Lmax)
            Lmax=level[i];
    }
    memset(xval,0,(Lmax+1)*sizeof(ll));
    //calculating values of xor per level
    f(i,0,n)
        xval[level[i]]^=a[i];
    //calculate nearest power of 2 <=Lmax
    //perms possible for Xd0 as per levels present in it
    ll tot=1;
    while(tot<=Lmax)
        Lmax<<=1;
    f(i,1,tot)
    {
        
    }
}

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("INP.txt","rt",stdin);
    #endif
    scanf("%d %d",&n,&m);
    f(i,0,n-1)
    {
        scanf("%d %d",&u,&v);
        TR[u].eb(v);
        TR[v].eb(u);
    }
    f(i,0,n)
        scanf("%lld",&a[i]);
    f(i,0,m)
        scanf("%lld",&q[i]);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

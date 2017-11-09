///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Thu Nov 02 2017               //
///////////////////////////////////////////
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

vector<int> a[M];
struct outer
{
    int dis,back,front;
}outers[M];

inline int getmin(int x, int tot)
{
    return min(x,abs(tot-x));
}

int GetShortestDis(int i,int u ,int v)
{
    int tot=*(a[i].end()-1);
    int dis=abs(a[i][v]-a[i][u]);
    return getmin(dis,tot);
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

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n,m,ai,u,v,w,te;
    int t; scan(t);
    while(t--)
    {
        scan(n); scan(m);
        f(i,1,n+1)
        {
            scan(ai);
            int sum=0;
            a[i].eb(0);
            f(j,0,ai)
            {
                scan(te);
                sum+=te;
                a[i].eb(sum);
            }
        }
        //now cycles
        int sum=0;
        scan(u); scan(v); scan(w);
        outers[1].front=u;
        outers[(1%n)+1].back=v;
        outers[1].dis=0;
        sum+=w;
        f(i,2,n+1)
        {
            scan(u); scan(v); scan(w);
            //u--; v--;
            outers[i].front=u;
            int temp=GetShortestDis(i,outers[i].front,outers[i].back);
            outers[i].dis=sum+temp;//GetShortestDis(i,outers[i].front,outers[i].back);
            sum=outers[i].dis+w;
            outers[(i%n)+1].back=v;
            // if(i!=1)
            //     sum+=w+GetShortestDis(i,outers[i].front,outers[i].back);
            // else
            //     sum+=w;
        }
        //queries
        int c1,v1,c2,v2,sol;
        f(i,0,m)
        {
            scan(v1); scan(c1); scan(v2); scan(c2);
            //clockwise
            int dis1=outers[c2].dis-outers[c1].dis-GetShortestDis(c2,outers[c2].back,v2);
            //anticlockwise
            int dis2=outers[n].dis-abs(outers[c2].dis-outers[c1].dis)+GetShortestDis(c1,outers[c1].back,v1)+GetShortestDis(c2,outers[c2].front,v2);
            sol=min(dis1,dis2);
            print(sol);
        }
        f(i,1,n+1)
            a[i].clear();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

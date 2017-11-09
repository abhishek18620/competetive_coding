///////////////////////////////////////////
//  Author : bvcoe_coders                 //
//  Date : Sat Nov 04 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
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
#define viter(s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

vector<int> GR[M];
int Ax[M],Fx[M],Gx[M];
queue<int> que,cl;

void update(int x, int w)
{
    if(x==0)
    {
        Ax[x]=w;
        Fx[x]=w;
        Gx[x]=1;
    }
    else
        Ax[x]=w;
    
    que.push(x);
    int v,u,lim;
    while(!que.empty())
    {
        v=que.front();
        que.pop();
        lim=GR[v].size();
        //parent=v
        f(i,0,lim)
        {
            u=GR[v][i];
            que.push(u);
            if(Fx[v]+1 < Ax[u])
            {
                Fx[u]=Ax[u];
                Gx[u]=1;
            }
            else if(Fx[v]+1 > Ax[u])
            {
                Fx[u]=Fx[v]+1;
                Gx[u]=Gx[v];
            }
            else
            {
                Fx[u]=Fx[v]+1;
                Gx[u]=Gx[v]+1;
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
    int n,q;
    scan(n); scan(q);
    f(i,0,n)
        scan(Ax[i]);
    
    //ids[0]=0;
    int te;
    f(i,1,n)
    {
        scan(te);   //edge a[i]--->i
        te--;
        GR[te].eb(i);
    }
    int ch,x,w;
    Fx[0]=Ax[0];
    Gx[0]=1;
    //initial setup
    update(0,Ax[0]);

    f(i,0,q)
    {
        scan(ch);
        if(ch==0)
        {
            scan(x); scan(w);
            x--;
            update(x,w);
        }
        else
        {
            scan(x);
            x--;
            printf("%d %d\n",Fx[x],Gx[x]);
        }
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

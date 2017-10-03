///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 6
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

//GLOBALS
const int mod=1e9+7;

int a[M],adj[M][M],col[M],ctr=0,n;
queue<int> que,emp;

//geekforgeeks
inline ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res=(res*x)%mod;
        x = (x*x)%mod;
        y = y>>1;
    }
    return res;
}

bool bipartite(int src,int val)
{
    que.push(src);
    col[src]=1;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        f(i,0,n)
        {
            if(adj[v][i]>val and col[i]==-1 and v!=i)
            {
                col[i]=1-col[v];
                que.push(i);
            }
            else if(adj[v][i]>val and col[i]==col[v] and v!=i)
                return 0;
        }
    }
    return 1;
}

int bdivide()
{
    int low=0,high=mod,mid=0,sol=0;
    while(low<=high)
    {
        //ctr++;  //diff
        f(i,0,n+2)
            col[i]=-1;
        mid=(high+low)>>1;    
        bool ans=1;
        f(i,0,n)
        {
            if(col[i]==-1)
            {
                if(!bipartite(i,mid))
                {
                    ans=0;
                    que=emp;
                    break;
                }
            }   
        }
        if(ans)
        {
            sol=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return sol;   
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
        scan(n);
        f(i,0,n)
            scan(a[i]);
        //pre calc
        f(i,0,n)
        {
            adj[i][i]=0;
            f(j,0,i)
                if(i!=j)
                   adj[j][i]=adj[i][j]=min(power(a[i],a[j]),power(a[j],a[i]));
        }
        print(bdivide());
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

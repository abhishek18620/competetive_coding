#include <bits/stdc++.h>
#define SIZE 1000009
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
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
 
int n,m,u,v;
vector<int> TR[SIZE];
ll visited[SIZE],diff,r,arr[SIZE],ans[SIZE];
ll days[SIZE];
 
//WANT SOMETHING ITERATIVE !! STILL THINK IT NEEDS SOME MEMOISATION 
//SENSED A BIT OF PATTERN BUT CAN'T BE ARSED SORTA..!!! ;)
//DOING A LOTTA OF BLACKHAT STUFF THESE DAYS
//LIVING BEST OF MY LIFE
ll XOR(ll &x, ll &y)
{
   return (x | y) & (~x | ~y);
}

void DFS_REC(int st)
{
    visited[st]=diff;
    int lim=TR[st].size();
    fuck(i,0,lim)
    {
        int nei=TR[st][i];
        if(visited[nei]!=diff)
        {
            DFS_REC(nei); 
            arr[st]=XOR(arr[st],arr[nei]);
        }
    }
}
 
void solve()
{
    diff=0;
    ans[0]=arr[0];
    fuck(i,1,r+2)
    {
        diff++;
        DFS_REC(0);
        ans[i]=arr[0];
    }
}
 
int main()
{
    freopen("INP.txt","rt",stdin);
    scan(n); scan(m);
    fuck(i,0,n-1)
    {
        scan(u); scan(v);
        TR[u].push_back(v);
        TR[v].push_back(u);
    }
    fuck(i,0,n)
        scanl(arr[i]);
    r=0;
    ll te;
    fuck(i,0,m)
    {
        scanl(te);
        days[i]=te;
        if(te>r)
            r=te;
    }
    solve();
    fuck(i,0,m)
    {
        int idx=days[i];
        printl(ans[idx]);
    }
    cin>>m;
    return 0;
}
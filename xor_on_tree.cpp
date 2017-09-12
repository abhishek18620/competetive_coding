/******************************************
*  Author : elliot   
*  Created On : Thu Sep 07 2017
*  File : xor_on_tree.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 200009
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
vector<ll> tree[M];
ll visited[M];
ll n,m,u,v,l,r,ctr;
ll a[M],sol[M];
pair<ll,int> q[M];

ll dfs(int st)
{
    visited[st]=ctr;
    int lim=tree[st].size();
    f(i,0,lim)
    {
        int nei=tree[st][i];
        if(visited[nei]!=ctr)
        {
            visited[nei]=ctr;
            a[st]^=dfs(nei);
        }
    }
    return a[st];
}

void solve()
{
    int idx=0,l=q[0].F,r=q[m-1].F;
    ctr=0;
    ll te;
    f(i,l,r+1)
    {
        ctr++;
        if(i==q[idx].F)
        {
            sol[q[idx].S]=dfs(0);
            idx++;
            continue;
        }
        te=dfs(0);
    }
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

void scan(int &x){
    	register int c = gc();
    	bool neg=0;
		x=0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=0;
    	x = 0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }
int main()
{
    fio;
#ifdef LOCAL_DEFINE
    freopen("INP.txt","rt",stdin);
#endif
    scanf("%d %d",&n,&m);
    f(i,0,n-1)
    {
        scanf("%d %d",&u,&v);
        tree[u].pb(v);
    }
    f(i,0,n)
        scanf("%lld",&a[i]);
    f(i,0,m)
    {
        scanf("%lld",&q[i].F);
        q[i].S=i;
    }
    sort(a,a+m);
    solve();
    f(i,0,m)
        printf("%lld\n",sol[i]);
#ifdef LOCAL_DEFINE
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
#endif
    cin>>n;
	return 0;
}

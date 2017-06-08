// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define pai pair<int,int>
using namespace std;

//GLOBALS
vector<int> dp;
int n;
ll mod=1e9+7;

//----------------------------------------------------UTILITY FUNCTIONS-----------------------------------------//
//--------------------------------------------------------------------------------------------------------------//
ll mod_mult(ll a,ll b)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

//----------------------------------------------------END OF UTILITY PHASE----------------------------------------------------------------//

//CALCULTE USING BRANCHING
ll calculte(ll ex)
{
    ll ans=16,lim1=0,lim2=0;
    if(ex < 4) 
        return (1<<ex);
    else if(ex%4==0)
        lim1=ex/4;
    else
    {
        lim1=ex/4;
        lim2=ex%4;
    }
    ll lim=ex/4;
    f(i,0,lim1-1)
    {
        ans*=mod_mult(ans,16);
    }
    ans=mod_mult(ans,(1<<lim2));
    return ans;
}

void dfs(bool vis[],vector<int> tr[],ll &ans,int i)
{
    stack<int> v;
    v.push(i);
    ll prv;
    while(!v.empty())
    {
        int ver=v.top();
        v.pop();
        int sz=tr[ver].size();
        f(i,0,sz)
        {
            int node=tr[ver][i];
            v.push(node);
            vis[node]=1;
        }
        //total ways to color nodes
        //logic is rather than calculating powers each time 
        //i should store exponents of 2(ans is exponent of 2)
        if(sz!=0)
            ans+=sz;
        else
            ans--;
    }
}
//dfs gives u sthe order
void solve(vector<int> tr[])
{
    bool vis[n];
    f(i,0,n)
        vis[i]=0;
    ll ans=1;
    f(i,0,n)
    {
        if(!vis[i])
            dfs(vis,tr,ans,i);
    }
    //calculate final answers with modulo
    //as we can't store 2^(10^5 -1) we should branch this
    cout<<calculte(ans)<<endl;
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
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	fio;
	scan(n);
    vector<int> tr[n];
    f(i,0,n-1)
    {
        int u,v;
        //u---->v(v is a child of u)
        scan(u); scan(v);
        tr[--u].pb(--v);
    }
    solve(tr);
    cin>>n; 
	return 0;
}
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 100006
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
using namespace std;

//GLOBALS   
vector< pair<ll,ll> > gr[M];
ll u,v,c,k,ini,sol=-1,spec;
int n,m;
bool visited[M];

//DFS(to check reachabilty)
void dfs(ll s,ll tot)
{
    visited[s]=1;
    f(i,0,gr[s].size())
    {
        ll ini=gr[s][i].F;
        spec=gr[s][i].S;
        if(!visited[ini])
        {
            if(spec <=k)
            {
//                tot = tot ^ spec;
                if(ini==v)
                {
                    sol=tot^spec;
                    return;
                }
                else
                    dfs(ini,tot^spec);

            }
            else
            {
                if(ini==v)
                {
                    sol=tot;
                    return;
                }
                else
                    dfs(ini,tot);
            }
        }    
    }
    return;
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
    // ll u,v,c;
    // int m;
	test
	{
        scan(n);
        f(i,0,n-1)
        {
            scanl(u); scanl(v); scanl(c);
            gr[--u].pb(mp(--v,c));
            gr[v].pb(mp(u,c));
        }
        scan(m);
        f(i,0,m)
        {
            scanl(u); scanl(v); scanl(k);
            --u; --v;
            memset(visited,0,sizeof(visited));
            sol=-1;
            dfs(u,0);
            if(sol==-1)
                cout<<"0"<<endl;
            else
                cout<<sol<<endl;
        }
        f(i,0,n)
            gr[i].clear();
	}
    cin>>t;
	return 0;
}

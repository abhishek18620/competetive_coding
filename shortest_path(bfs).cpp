#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define M 100005
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
using namespace std;
typedef pair<ll, ll> pai;
#define INF 100000000000000000
 
queue< ll >q;
ll dp[M][1];
vector<pai>gr[M];
 
void bfs(ll x,ll y)
{
 
	q.push(x);
	dp[x][y]=0;
	while(!q.empty())
	{
		ll z = q.front();
		for(ll i=0;i<gr[z].size();i++){
			if(dp[gr[z][i].first][y]>dp[z][y]+gr[z][i].second){
				dp[gr[z][i].first][y]=dp[z][y]+gr[z][i].second;
				q.push(gr[z][i].first);
			}
		}
		q.pop();
 
	}
 }

 void scanl(ll &x){
        	register ll c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
        }
 
int main()
{
	fio;
	ll tt;
	scanl(tt);
	while(tt--)
	{
		ll n, k, x, m, w, u, v, src;
            scanl(n); scanl(k); scanl(x); scanl(m); scanl(src);
	    f(i,1,n+1)
		{
			dp[i][0]=INF;
			dp[i][1]=INF;
			dp[i][2]=INF;
			gr[i].clear();
		}
 
		f(i,1,k+1)
            {
                f(j,i+1,k+1)
                {
                    gr[i].push_back(make_pair(j,x));
                    // BIDIRECTIONAL
                    gr[j].push_back(make_pair(i,x));
                }
            }
            f(i, 0, m)
            {
                // u----->v
                scanl(u); scanl(v); scanl(w);
                // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
                gr[u].push_back(make_pair(v, w));
                gr[v].push_back(make_pair(u, w)); //if graph is undirected
            }
 
 
		bfs(src,0);
		f(i,1,n+1)
        	cout<<dp[i][0]<<" ";
        cout<<endl;
	}
		//printf("%lld\n",ans);
	cin>>tt;
    return 0;
}
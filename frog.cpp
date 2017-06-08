#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;
#define mp(i,j) make_pair(i,j)
typedef pair<ll,ll> pai;

//COMPARATOR
bool comp(const pai &lhs, const pai &rhs)
{
  return lhs.second < rhs.second;
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
	ll n,k,p;   // no. of frogs , max dis , pairs 
    scanl(n); scanl(k); scanl(p);
    vector<pai>dis;
	ll dp[n];
	f(i,0,n)
	{
		ll u; scanl(u);
		dis.push_back(mp(u,i));	//u and index
	}
	sort(dis.begin(),dis.end());
	// cout<<"\nafter sorting :	";
	// f(i,0,n)
	// 	cout<<"\nfirst :	"<<dis[i].first<<"	second	:	"<<dis[i].second;
	// dp[dis[0].second]=dis[0].second;
	
	//D P
	f(i,1,n)
	{
		if(dis[i].first - dis[i-1].first <=k)
			dp[dis[i].second]=dp[dis[i-1].second];
		else
			dp[dis[i].second]=dis[i].second;
	}
	f(i,0,p)
	{
		ll u,w;
		scanl(u); scanl(w);
		if(dp[w-1] == dp[u-1])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	cin>>n;
	return 0;
}
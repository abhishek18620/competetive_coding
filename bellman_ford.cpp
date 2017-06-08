#include <bits/stdc++.h>
#define M 100
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
//#define test ll t; scanl(t); while(t--)
#define pr_qu priority_queue<pai, vector<pai>, greater<pai> >
using namespace std;
typedef pair<ll,ll> pai;
//global vars
ll m, n, w, u, v, src,des;
// int find_ver(int k,vector<pai> rev_gr[M])
// {
// 	int min_dis=M;
// 	f(i,0,rev_gr[v].size())
// 	{
// 		if(rev_gr[v][i].second < min_dis)
// 			min_dis=rev_gr[v][i].second;
// 	}
// 	return min_dis;
// }
//COMPARATOR
template <typename K, typename V>
bool comp(const pair<K,V>& lhs, const pair<K,V>& rhs)
{
  return lhs.second < rhs.second;
}

//DFS(to check reachabilty)
bool dfs(vector<pai> gr[M],ll s, ll t)
{
	bool visited[n]={0};
	stack<ll> st;
	st.push(s);
	visited[s]=1;
	while(!st.empty())
	{
		ll v=st.top(); st.pop(); 
		f(i,0,gr[v].size())
		{
			ll ini=gr[v][i].first;
			if(!visited[ini])
				st.push(ini);
				visited[ini]=1;
			if(visited[t])
				return 1;
		}
	}
	if(visited[t])
		return 1;
	else
		return 0;
}

// BELLMAN FORD
void b_ford(vector<pai> rev_gr[M])
{
	vector<ll> dis;	//dis vec
	f(i,0,m)
		dis.push_back(INF);
	dis[src]=0;
	f(i,0,m)
	{
		//outgoing edges in rev_gr are incoming edges in gr
		ll sz=rev_gr[i].size();
		f(j,0,rev_gr[i].size())
		{
			ll s=rev_gr[i][j].first;
			ll wei=rev_gr[i][j].second;
			if(dis[s]!=INF and dis[i]>dis[s]+wei)
				dis[i]=dis[s]+wei;
		}
	}

	//CHECKING -ve CYCLES(traverse all edges ONCE MORE)
	f(i,0,m)
	{
		f(j,0,rev_gr[i].size())
		{
			ll s=rev_gr[i][j].first;
			ll wei=rev_gr[i][j].second;
			if(dis[s]!=INF and dis[i]>dis[s]+wei)
				cout<<"\n !!!Negative cycle for :	"<<i;	//do what needs to be done in case of -ve cycle
		}	
	}
	// PRINTING
	f(i,0,dis.size())
	cout<<"\n"<<src+1<<"--->"<<i+1<<"  = "<<dis[i];
}

int main()
{
	//fio;
	int t; cin>>t;
	while(t--)
	{
        vector<pai> gr[M],rev_gr[M];	// graph
    	//pr_qu pq; //priority queue for O(mlgn)
		cin>>m>>n;                                     //m == vertices  n== edges 
		f(i, 0, n)
		{
			// u----->v
			cin>>u>>v>>w;
			// gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
			gr[u-1].push_back(make_pair(v-1, w));
			rev_gr[v-1].push_back(make_pair(u-1, w)); //reversed graph
		}
		cin>>src>>des;
		src--; des--;
		bool res=dfs(gr,src,des);
		if(res)
			b_ford(rev_gr);
		else
			cout<<"\n!!!DESTINATION IS NOT REACHABLE!!!";
	}
	cin>>t;
	return 0;
}
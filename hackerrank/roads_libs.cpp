#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define M 100009
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define mp(i,j) make_pair(i,j)
#define gc() getchar_unlocked()
#define test int t; cin>>t; while(t--)
using namespace std;
typedef pair<ll,ll> pai;
typedef pair< ll , pai> ext_pai;

//GLOBALS
//GRAPH
vector<pai> gr[M];
vector<int> SCC;
bool visited[M];
ll cost=0,cl,cr;
// DFS
void dfs(vector<pai> gr[] ,ll s , bool visited[], ll ind)
{
    ll count=1;
    stack<ll> ver;
    ver.push(s);
    visited[s]=1;
    while(!ver.empty())
    {
        ll st=ver.top();
        ver.pop();
        //TRAVERSE ALL NEIGHBOURS
        //I USED THIS BECAUSE RECUSRION MIGHT LEAD TO STACK OVERFLOW
        f(i,0,gr[st].size())
        {
            ll v=gr[st][i].first;   // neighbour
            if(!visited[v])
            {
                //order.push(v);  //for finishing time
                ver.push(v);
                visited[v]=1;
                count++;
            }
        }
    }
    SCC.push_back(count);
    //cost+=cr*(count-1);
}


//FIND SCCs
void conn_comp(vector<pai> gr[], ll n)
{
    //stack<int> order;
    memset(visited,0,n);

    // NO NEED TO GIVE FINISHING TIMES CAUSE EDGES ARE BIDIRECTIONAL
    ll ind=1;
    f(i,0,n)
    {
        if(!visited[i])         // not yet visited
        {
            dfs(gr,i,visited,ind);
            ind++;
        }
    }
    //number of libs
    //cost+=cl*(ind-1);
    //return ind;
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

void scanl(ll &x){
		register ll c = gc();
		x = 0;
		for(;c<48 || c>57;c=gc());
		for(;c>47 && c<58;c=gc())
			x=(x<<1)+(x<<3)+c-48;
	}



int main()
{
    test
	{
        ll n,m;
        scanl(n); scanl(m); scanl(cl); scanl(cr);   //n=nodes , m=existing roads
        f(i,0,n)
            gr[i].clear();
        f(i, 0, m)
        {
            ll u,v;
            // u----->v
            scanl(u); scanl(v);
            // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
            gr[--u].push_back(mp(--v, 1));
            gr[v].push_back(mp(u, 1)); //if graph is undirected
        }
        //CALCULATED SCCS
        conn_comp(gr,n);
        int sz=SCC.size();
        //GREEDY APPROACH
        f(i,0,sz)
        {
            int c1=cr*(SCC[i]-1)+cl;
            int c2=cl*SCC[i];
            cost+=min(c1,c2);
        }
        //ll new_v=conn_comp(gr,n) - 1;
        //cout<<"\n calculated solution is :      "<<cost<<endl;
        writel(cost);
        cost=0;
        SCC.clear();
    }
    cin>>t;
	return 0;
}
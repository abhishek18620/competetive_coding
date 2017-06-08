#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define mp(i,j) make_pair(i,j)
#define test int t; cin>>t; while(t--)
using namespace std;
typedef pair<ll,ll> pai;
typedef pair< ll , pai> ext_pai;

//GLOBALS
vector<ll> SCC;
//COMPARATOR
bool comp(const ext_pai &lhs, const ext_pai &rhs)
{
  return lhs.first < rhs.first;
}

//UNION FIND DS(operations)
int root(int x, ll id[])
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y, ll id[])
{
    int p = root(x,id);
    int q = root(y,id);
    id[p] = id[q];
}

//KRUSKKAL'S ALGO   (MST)
// MAZA AA GYA
ll MST(ext_pai roads[] , int k, int new_v)
{
    ll id[new_v];
    f(i,0,new_v)
        id[i]=i;

    ll u, v;
    ll cost, min_cost = 0;
    f(i,0,k)
    {
        u = roads[i].second.first;
        v = roads[i].second.second;
        u--; v--;
        cost = roads[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(u,id) != root(v,id))
        {
            min_cost += cost;
            union1(u,v,id);
        }    
    }
    return min_cost;
}

// DFS
void dfs(vector<pai> gr[] ,ll s , bool visited[], ll scc_ind[], ll ind)
{
    stack<ll> ver;
    ver.push(s);
    visited[s]=1;
    while(!ver.empty())
    {
        ll st=ver.top();
        ver.pop();
        scc_ind[st]=ind;
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
                scc_ind[v]=ind;     // indicates which scc
            }
        }
    }
}


//FIND SCCs
ll conn_comp(vector<pai> gr[], ll n)
{
    //stack<int> order;
    bool visited[n];
    ll scc_ind[n];
    memset(visited,0,sizeof(visited));

    // NO NEED TO GIVE FINISHING TIMES CAUSE EDGES ARE BIDIRECTIONAL
    ll ind=1;
    f(i,0,n)
    {
        if(!visited[i])         // not yet visited
        {
            dfs(gr,i,visited,scc_ind,ind);
            ind++;
        }
    }
    f(i,0,n)
        SCC.push_back(scc_ind[i]);
    return ind;
}

int main()
{
    // For getting input from input.txt file
    freopen("/home/abhi/Desktop/input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("/home/abhi/Desktop/output.txt", "w", stdout);
	test
	{
        ll n,m,k;
        cin>>n>>m;                  //n=nodes , m=existing roads
        //GRAPH
        vector<pai> gr[n];
        f(i, 0, m)
        {
            ll u,v;
            // u----->v
            cin >> u >> v;
            // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
            gr[--u].push_back(mp(--v, 1));
            gr[v].push_back(mp(u, 1)); //if graph is undirected
        }
        //CALCULATED SCCS
        ll new_v=conn_comp(gr,n) - 1;
        
        // cout<<"THE SCC IS : "<<endl;
        // f(i,0,SCC.size())
        //  cout<<"scc for"<< i <<"    is: "<<SCC[i]<<endl;

        
        cin>>k;
        ext_pai roads[k];
        // ENTER NEW ROADS
        f(i,0,k)
        {
            ll u,v,w;
            cin>>u>>v>>w;       --u;--v;
            roads[i]=mp(w,mp(SCC[u],SCC[v]));
        }
        //NOW TURN FOR MINIMUM SPANNING TREE
        // DIMAG KHARAB HO GYA
        vector<pai> new_gr[new_v];
        
        // sort edges
        sort(roads,roads+k,comp);
        // TIME FOR FINAL STAGE
        ll sol = MST(roads,k,new_v);
        cout<<"\n calculated solution is :      "<<sol<<endl;
        SCC.clear();
    }
    cin>>t;
	return 0;
}
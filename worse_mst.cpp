#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define mp(i,j) make_pair(i,j)
#define test int t; cin>>t; while(t--)
using namespace std;
typedef pair<int,int> pai;
typedef pair< ll , pai> ext_pai;
typedef pair< int, ext_pai> index_pair; //index mp( w, mp(src,des))
//GLOBALS
vector<int> ans;
int frq=0;
//COMPARATOR
bool comp(const index_pair &lhs, const index_pair &rhs)
{
  return lhs.second.first > rhs.second.first;
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
ll MST(index_pair roads[] , int k, int new_v)
{
    ll id[new_v];
    f(i,0,new_v)
        id[i]=i;

    ll u, v;
    ll cost, min_cost = 0;
    f(i,0,k)
    {
        u = roads[i].second.second.first;
        v = roads[i].second.second.second;
        int pos= roads[i].first;
        //u--; v--;
        cost = roads[i].second.first;
        // Check if the selected edge is creating a cycle or not
        if(root(u,id) != root(v,id))
        {
            ans.push_back(pos);
            frq++;
            min_cost += cost;
            union1(u,v,id);
        }    
    }
    return min_cost;
}


int main()
{
    //fio;
    int n,m,k;
    cin>>n>>m>>k;                  //n=nodes , m=existing roads
    index_pair roads[m+1];
    // ENTER NEW ROADS
    f(i,0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;       --u;--v;
        roads[i]=mp(i+1,mp(w,mp(u,v)));
    }
    //NOW TURN FOR MINIMUM SPANNING TREE
    // DIMAG KHARAB HO GYA
    //vector<pai> new_gr[new_v];
    
    // sort edges
    sort(roads,roads+m,comp);
    
    // cout<<"\n SORTED ROADS ARE : ";
    // f(i,0,m)
    //     cout<<"\n ROAD :    "<<roads[i].first<<"   "<<roads[i].second.second.first+1<<"------>"<<roads[i].second.second.second+1<<"  =  "<<roads[i].second.first;
    // // TIME FOR FINAL STAGE
    ll sol = MST(roads,m,n);
    //cout<<"\nCalculated solution is :      "<<sol<<endl;
    cout<<frq<<endl;
    f(i,0,ans.size())
        cout<<ans[i]<<" ";
    cin>>m;
	return 0;
}
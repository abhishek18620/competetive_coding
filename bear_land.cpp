
//KEEP THIS FACT IN MIND CONNECTING A DENSE GRAPH(super connected) CAN BE VERY COSTLY
#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define mp(i,j) make_pair(i,j)
#define M 100004
typedef long long ll;
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
#define f(i, j, k) for (ll i = j; i < k; i++)
using namespace std;
typedef pair<ll, ll> pai;
ll INF=numeric_limits<ll>::max();
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second > p2.second;
    }
};    
    //GLOBALS
    vector<pai> gr[M];
    ll dis[M];
    priority_queue<pai, vector<pai>, Prioritize > pq;

    void dijkstra(ll src , ll n)
    {
        f(i,0,n)
            dis[i]=INF;
        dis[src]=0;
        pq.push(mp(src,0));
        while (!pq.empty())
        {
            ll v = pq.top().first;
            ll d = dis[v];
            pq.pop();
            f(i, 0, gr[v].size())
            {
                ll ver = gr[v][i].first;
                ll wei = gr[v][i].second;
                if (dis[ver] > d + wei)
                {
                    dis[ver] = d + wei;
                    pq.push(make_pair(ver, dis[ver]));
                }
            }
        }
    }

    void scan(int &x){
        	register int c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
        }
     
    void scanl(ll &x){
        	register ll c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
        }
     
    //MAIN
    int main()
    {
        fio;
        test
        {
            ll n, k, x, m, w, u, v, src;
            scanl(n); scanl(k); scanl(x); scanl(m); scanl(src);                                           //m == vertices  n== edges 
            src--;
            f(i,0,n)
                gr[i].clear();

            if(src<k)
            {
                // THERES ONLY ONE EDGE SO SD WILL BE X ONLY;
                f(i,0,k)
                {
                    if(i!=src)
                    {
                        // CONNECT ALL VERS TO SRC
                        gr[src].push_back(mp(i,x));
                        gr[i].push_back(mp(src,x));
                    }
                }
                f(i,0,k)
                    dis[i]=x;
                dis[src]=0;
                //INPUT
                f(i, 0, m)
                {
                    // u----->v
                    scanl(u); scanl(v); scanl(w);
                    // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
                    gr[--u].push_back(make_pair(--v, w));
                    gr[v].push_back(make_pair(u, w)); //if graph is undirected
                }
                dijkstra(src,n);
            }
            else        // SRC >= K
            {
                dis[src]=0;
                f(i, 0, m)
                {
                    // u----->v
                    scanl(u); scanl(v); scanl(w);
                    // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
                    gr[--u].push_back(make_pair(--v, w));
                    gr[v].push_back(make_pair(u, w)); //if graph is undirected
                }
                dijkstra(src,n);
                //FIND MIN DIS VERTEX
                ll min = INF;
                int ind=-1;
                f(i,0,k)
                {
                    if(dis[i]<min and i!=src)
                    {
                        min=dis[i];
                        ind=i;
                    }
                }
                f(i,0,k)
                {
                    if(i!=ind)
                    {
                        // CONNECT ALL VERS TO SRC
                        gr[ind].push_back(mp(i,x));
                        gr[i].push_back(mp(ind,x));
                    }
                }
                dijkstra(src,n);
            }
            
            f(i,0,n)
                cout<<dis[i]<<" ";
            cout<<endl;
            }
        cin>>t;
        return 0;
    } 
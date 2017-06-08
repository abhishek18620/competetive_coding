#include <bits/stdc++.h>
#define M 10000
#define INF 999999
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
using namespace std;
typedef pair<ll, ll> pai;

void dijkstra(priority_queue<pai, vector<pai>, greater<pai> > &pq , vector<pai> gr[M] , vector<ll>& dis)
{
    while (!pq.empty())
    {
        ll v = pq.top().first;
        ll d = pq.top().second;
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

int main()
{
    ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
    vector<pai> gr[M];
    vector<ll> dis;
    priority_queue<pai, vector<pai>, greater<pai> > pq;
    ll m, n, w, u, v, src,b;
    cin >> m >> n;                                           //m == vertices  n== edges 
    f(i, 0, n)
    {
        // u----->v
        cin >> u >> v >> w;
        // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
        gr[--u].push_back(make_pair(--v, w));
        //gr[v].push_back(make_pair(u, w)); //if graph is undirected
    }
    cin>>src>>b;
    f(i,0,m)
        dis.push_back(INF);
    dis[--src] = 0;
    pq.push(make_pair(src, 0));
    //cout<<"\nthe sisze is "<<pq.size();
    dijkstra(pq,gr,dis);
    if(dis[b-1] == INF)
    cout<<"NO"<<endl;
    else
    cout<<dis[b-1]<<endl;
    //pq.clear();
    }
    return 0;
}
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define viter(it,s) for (auto it: s)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll INF= 2001001001001001001ll;

vector< vector<pll> > gr;
vll dis,a;
priority_queue< pll, vector <pll> , greater<pll> > pq;

void dijkstra(ll src)
{
    int n=dis.size();
    f(i,0,n)
        dis[i]=INF;
    dis[src]=0;
    pq.push(mp(0,src));
    while(!pq.empty())
    {
        ll u=pq.top().S;
        pq.pop();
        viter(p,gr[u])
        {
            ll v=p.F;
            ll wei=p.S;
            if(dis[v]> dis[u]+wei)
            {
                dis[v]=dis[u]+wei;
                pq.push(mp(dis[v],v));
            }
        }
    }
}

int main()
{
	ll n,m;
    scanl2(n,m);
    gr.resize(n+1);
    dis.resize(n+1);
    a.resize(n+1);
    ll u,v,w;
    f(i,0,m)
    {
        scanl3(u,v,w);
        gr[u].emplace_back(v,w);
        gr[v].emplace_back(u,w);
    }
    f(i,1,n+1)  scanl(a[i]);
    f(i,1,n+1)
    {
        dijkstra(i);
        ll sol=INF;
        f(j,1,n+1)
        {
            if(dis[j]==INF)
                sol=min(sol,dis[j]);
            else
            {
                sol=min(sol,2*dis[j]+a[j]);
            }
        }
        printf("%lld ",sol);
    }
    return 0;
}

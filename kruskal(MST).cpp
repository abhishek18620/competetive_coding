// KRUSKAL MST
// UNION FIND DS OR DISJOINT SETS
/******************************************
*  Author : abhishek18620   
*  Created On : Mon Oct 30 2017
*  File : kruskal(MST).cpp
*******************************************/
#include <bits/stdc++.h>
#define M 10009
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
#define eb emplace_back
using namespace std;

//GLOBALS
char str[11];
int n,m,u,v;
ll w;
//union find ds
int parent[M];
vector< pair< ll,pair<int ,int> > > edges;   //gr[i]--[j1,w1]--[j2,w2]--[j3,w3]...

int find_parent(int x)
{
    while(parent[x]!=x)
    {
        parent[x]=parent[parent[x]]; //update parents
        x=parent[x];
    }
    return x;
}

void set_union(int x, int y)
{
    int px=find_parent(x);
    int py=find_parent(y);
    parent[px]=parent[py];
}

ll kruskal()
{
    ll sol=0;
    int lim=edges.size();
    f(i,0,lim)
    {
        w=edges[i].F;
        u=edges[i].S.F;
        v=edges[i].S.S;
        if(find_parent(u)!=find_parent(v))    //not forming a cycle
        {
            sol+=w;
            set_union(u,v);
        }
    }
    return sol;
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
    	bool neg=0;
		x=0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=0;
    	x = 0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }
int main()
{
    //fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    test
    {
        scan(n);
        f(i,0,n)
        {
            scanf("%s",str);    //no significance
            scan(m);
            f(j,0,m)
            {
                scan(u);
                scanl(w);
                edges.eb(mp(w,mp(i,--u)));
            }
        }
        sort(edges.begin(),edges.end());
        f(i,0,n+1)
            parent[i]=i;
        
        ll ans=kruskal();
        writel(ans);
        edges.clear();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

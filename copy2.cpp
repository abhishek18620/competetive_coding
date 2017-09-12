#include <bits/stdc++.h>
#define M 1000009
#define INF 999999
#define rep(i, j, k) for (int i = j; i < k; i++)
#define eb emplace_back
#define pb push_back
using namespace std;


vector<int> graph[M];
int b[M],visited[M],a[M][3],n,q,ctr;
long long prv=0;
struct status
{
    int l,r;
    //bool flip;
}A[M];

bool dfs(int u,int v)
{
    stack<int> ver;
    ver.push(v);
    prv++;
    visited[v]=prv;
    //gender[s]=1;    //let i be male
    while(!ver.empty())
    {
        int st=ver.top();
        ver.pop();
        int lim=graph[st].size();
        rep(i,0,lim)
        {
            int nei=graph[st][i];   // neighbour
            if(visited[nei]!=prv)
            {
                swap(A[nei].l,A[nei].r);
                if(nei==u)
                    return 0;
                //A[nei].flip=1;
                ver.push(nei);
                visited[nei]=prv;        
                    
            }
        }
    }
    return 1;
}

bool solve()
{
    bool sol=1;
    rep(i,0,q)
    {
        int u=a[i][0];
        int v=a[i][1];
        int diff=a[i][2];
        if(diff==1)
        {
            //both are unset
            if(b[u]!=ctr and b[v]!=ctr)
            {
                b[u]=b[v]=ctr;
                if(u!=v)
                {
                    A[u].l=0; A[v].l=1;
                    A[u].r=1; A[v].r=0;
                    graph[u].pb(v);
                    graph[v].pb(u);
                }
                else
                {
                    A[u].l=0; A[u].r=1;
                }
            }
            //one of em is set
            else if(b[u]==ctr and b[v]!=ctr)
            {
                b[v]=ctr;
                A[v].l=1-A[u].l;
                A[v].r=1-A[u].r;
                graph[u].pb(v);
                graph[v].pb(u);
            }
            //one of em is set
            else if(b[v]==ctr and b[u]!=ctr)
            {
                b[u]=ctr;
                A[u].l=1-A[v].l;
                A[u].r=1-A[v].r;
                graph[v].pb(u);
                graph[u].pb(v);
            }
            else //both are set
            {
                if((A[u].l==1 and A[v].l==0) or (A[u].l==0 and A[v].l==1))
                {
                    graph[u].pb(v);
                    graph[v].pb(u);
                    continue;
                }
                else
                {
                    //A[v].flip=1;
                    //A[u].flip=0;
                    swap(A[v].l,A[v].r);
                    bool res=dfs(u,v);
                    if(!res)
                        return 0;
                }
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
        else    //diff=0
        {
            //both are unset
            if(b[u]!=ctr and b[v]!=ctr)
            {
                b[u]=b[v]=ctr;
                if(u!=v)
                {
                    A[u].l=0; A[v].l=0;
                    A[u].r=1; A[v].r=1;
                    graph[u].pb(v);
                    graph[v].pb(u);
                }
                else
                {
                    A[u].l=0; A[u].r=1;
                }
            }
            //one of em is set
            else if(b[u]==ctr and b[v]!=ctr)
            {
                b[v]=ctr;
                A[v].l=A[u].l;
                A[v].r=A[u].r;
                graph[u].pb(v);
                graph[v].pb(u);
            }
            //one of em is set
            else if(b[v]==ctr and b[u]!=ctr)
            {
                b[u]=ctr;
                A[u].l=A[v].l;
                A[u].r=A[v].r;
                graph[u].pb(v);
                graph[v].pb(u);
            }
            else //both are set
            {
                if((A[u].l==0 and A[v].l==0) or (A[u].l==1 and A[v].l==1))
                {
                    graph[u].pb(v);
                    graph[v].pb(u);
                    continue;
                }
                else
                {
                    //A[v].flip=1;
                    //A[u].flip=0;
                    swap(A[v].l,A[v].r);
                    bool res=dfs(u,v);
                    if(!res)
                        return 0;
                }
                graph[u].pb(v);
                graph[v].pb(u);
            }
        }
    }
    return 1;
}


int main()
{
    ctr=0;
    int t; scanf("%d",&t);
    while(t--)
	{
        rep(i,1,n+1)
            graph[i].clear();
        scanf("%d %d",&n,&q);
        ctr++;
        bool sol=1;
        int te1,te2,val;
        for(int i=0;i<q;i++)
        {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][0]==a[i][1] and a[i][2]!=0)
                sol=0;
            //A[a[i][0]].flip=A[a[i][1]].flip=0;
        }
        if(!sol)
        {
            printf("no\n");
            continue;
        }
        sol=solve();
        if(sol)
            printf("yes\n");
        else
            printf("no\n");
    }
    cin>>t;
	return 0;
}

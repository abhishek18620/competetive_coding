#include "bits/stdc++.h"
using namespace std;



/*      GRAPH       */

struct Graph
{
    int vertices;
    vector<vi> adj;
    vi visited;
    int sz;
    void dfs(int x, int y)
    {
        stack<int> st;
        st.push(x);
        while(!st.empty())
        {
            int u=st.top();
            visited[u]=done;
            if(health[u]>0)
            {
                health[u]-=y;
                if(health[u]<=0) alive--;
            }
            st.pop();
            viter(v,adj[u])
            {
                if(visited[v]!=done) st.push(v);
            }
        }
    }

    void AddEdge(int u,int v)
    {
        adj[v].eb(u);
        //adj[u].eb(v);
    }

    void create_graph();

    void init(int n)
    {
        adj.resize(M+1);
        vertices=n;
        sz=1;
        int te=n;
        while(te>>1)
        {
            sz++,te>>=1;
        }
        visited.resize(M+2);
        create_graph();
        //memset(visited,0,sizeof(visited));
    }
};

void Graph::create_graph()
{
    int u,v;
    f(v,0,M+1)
    {
        fr(iBit,16,0)
        {
            if(v & (1<<iBit)) //ith bit is set
            {
                u=v^(1<<iBit); //unset ith bit
                //an edge from u-->v
                if(u!=0) AddEdge(u,v);
            }
        }
    }
}

/*     SEGMENT TREE     */

struct node
{
    int gcd;
    void init(int x)
    {
        gcd=x;
    }
    void merge(node &l , node&r)
    {
        gcd=__gcd(l.gcd , r.gcd);
    }
};
vector<node> seg;

void build(int idx, int l ,int r)
{
    if(l==r)
    {
        seg[idx].gcd=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    seg[idx].merge(seg[idx<<1],seg[idx<<1|1]);
}

void update(int idx,int l,int r,int updidx,int updval)
{
    if(l==r)
    {
        seg[idx].gcd=updval;
        return;
    }
    int mid=(l+r)>>1;
    if(updidx >= l and updidx <=mid)
    {
        update(idx<<1,l,mid,updidx,updval);
    }
    else
    {
        update(idx<<1|1,mid+1,r,updidx,updval);
    }
    seg[idx].merge(seg[idx<<1],seg[idx<<1|1]);
}

bool query(int idx,int l,int r,int Ql,int Qr,int x)
{
    if(changes>1) return 0;
    if(seg[idx].gcd %x ==0) return 1;

    //seg[idx].gcd is not a multiple of x 
    if(l==r)    //can't process the whole segment at once if not a multiple
    {
        changes++;
        if(changes>1) return 0;
        else return 1;
    }
    int mid=(l+r)>>1;
    bool resL=1,resR=1;
    if(Qr<=mid)  //query range lies in left subtree
        resL=query(idx<<1,l,mid,Ql,Qr,x);
    else if(Ql>mid)    //query range lies in right tree
        resR=query(idx<<1|1,mid+1,r,Ql,Qr,x);
    else    //query range lies in both trees 
    {
        resL=query(idx<<1,l,mid,Ql,mid,x);
        resR=query(idx<<1|1,mid+1,r,mid+1,Qr,x);
    }
    if(resL and resR) return 1;
    return 0;
}


/* FENWICK TREE */

struct fenwick
{
    vector<int> fenw;
    int n;
    void ini(int sz)
    {
        n=sz;
        fenw.clear();
        fenw.resize(n,0);
    }
    void update(int idx, int x)
    {
        while(idx<n)
        {
            fw[idx]+=x;
            idx|=(idx+1);
        }
    }
    int query(int l)  //Value at l
    {
        int r=0;
        while(l>=0)
        {
            r+=fenw[l];
            l&=(l+1);
            --l;
        }
        return r;
    }
};
// TOPOLOGICAL SORTING
/******************************************
*  Author : abhishek18620   
*  Created On : Sat Oct 21 2017
*  File : topological_sorting.cpp
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
int n,m,u,v,ctr,in[M];
vector<int> GR[M],order;
set<int> traverse;

void topo()
{
    int u,v;
    ctr=0;
	set<int>::iterator it;
    while(!traverse.empty())
    {
		u = *traverse.begin();
		traverse.erase(traverse.begin());
        order.eb(u);
        ctr++;
        f(i,0,GR[u].size())
        {
			v=GR[u][i];
			in[v]--;
            if(!in[v])
                traverse.insert(v);
		}
	}
}



// void topo()
// {
//     int v,lim;
//     f(i,0,n)
//         visited[i]=0;
//     f(i,0,n)
//     {
//         if(visited[i])
//             continue;
//         if(st.empty())
//         {
//             if(hit[i]==in[i])
//                 order.eb(i);
//             st.push(i);
//             //order.eb(i);
//         }
//         while(!st.empty())
//         {
//             v=st.top();
//             visited[v]=1;
//             st.pop();
//             lim=GR[v].size();
//             f(i,0,lim)
//             {
//                 hit[GR[v][i]]++;
//                 if(hit[GR[v][i]]==in[GR[v][i]])
//                     order.eb(GR[v][i]);
//                 if(!visited[GR[v][i]])   //already visited means back cycle
//                 {
//                     st.push(GR[v][i]);
//                     //order.eb(GR[v][i]);
//                 }
//             }
//         }
//     }
// }


void scan(int &x)
{
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

int main()
{
    fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    bool possible=0;
    scan(n); scan(m);
    f(i,0,m)
    {
        scan(u); scan(v);
        --u; --v;
        //out[u]++;
        in[v]++;
        GR[u].eb(v);
    }
    f(i,0,n)
        if(in[i]==0)
            traverse.insert(i);
        
    topo();
    if(ctr==n)
    {
        f(i,0,n)
            printf("%d ",order[i]+1);
        printf("\n");
    }        
    else
        printf("Sandro fails.\n");

    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

#include <bits/stdc++.h>
#define f(i, j, k) for (long int i = j; i < k; i++)
#define M 100000
using namespace std;
long int n,m,s;
vector<long int> tr[M];
bool visited[M]={0};
long int top[M],df[M],c_top=0,c_df=0,que,u,v;
 
void dfs(long int s)
{
    visited[s]=1;
    df[s]=c_df++;
    f(i,0,tr[s].size())
    {
        if(!visited[tr[s][i]])
            dfs(tr[s][i]);
    }
    top[s]=c_top++;
}
 
int main()
{
    cin>>n;
    f(i,0,n-1)
    {
        cin>>u>>v;      //u---->v
        tr[u-1].push_back(v-1);
        tr[v-1].push_back(u-1);
    }
    dfs(0);
    cin>>que;
    f(i,0,que)
    {
        long int x,y,z;
        cin>>x>>y>>z;
 
        if(x==0)
        {
            if(top[y-1]>top[z-1] and df[y-1]<df[z-1])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            if(top[y-1]<top[z-1] and df[y-1]>df[z-1])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
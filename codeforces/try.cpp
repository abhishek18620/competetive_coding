#include<bits/stdc++.h>
#define ft first
#define sd second
using namespace std;
int n,m;
int visited[1001][1001];
int a[1001][1001];
void dfs(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return ;
    visited[i][j]=1;
    if(a[i][j] >= a[i+1][j] && !visited[i+1][j])
        dfs(i+1,j);
    if(a[i][j] >= a[i-1][j] && !visited[i-1][j])
        dfs(i-1,j);
    if(a[i][j] >= a[i][j+1] && !visited[i][j+1])
        dfs(i,j+1);
    if(a[i][j] >= a[i][j-1] && !visited[i][j-1])
        dfs(i,j-1);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        //int n,m;
        cin>>n>>m;
 
        memset(visited,0,sizeof(visited));
 
        vector< pair<int,int> > v;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                v.push_back({a[i][j],i*m+j})  ; // linear indexing
            }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            int x = v[i].sd/m;
            int y = v[i].sd%m;
            if(!visited[x][y])
            {
                dfs(x,y);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}
 
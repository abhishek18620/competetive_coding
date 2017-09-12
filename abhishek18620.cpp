#include <bits/stdc++.h>
#define SIZE 100
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;
 
int n,m,u,v;
vector<int> TR[SIZE],leaf;
ll visited[SIZE],done[SIZE],diff,r,arr[SIZE],ans[SIZE],days[SIZE],mark;
//WANT SOMETHING ITERATIVE !! STILL THINK IT NEEDS SOME MEMOISATION 
//SENSED A BIT OF PATTERN BUT CAN'T BE ARSED SORTA..!!! ;)
//DOING A LOTTA OF BLACKHAT STUFF THESE DAYS
//LIVING BEST OF MY LIFE
 
 
// void DFS_REC(int st)
// {
//     visited[st]=diff;
//     int lim=TR[st].size();
//     fuck(i,0,lim)
//     {
//         int nei=TR[st][i];
//         if(visited[nei]!=diff)
//         {
//             DFS_REC(nei); 
//             arr[st]=XOR(arr[st],arr[nei]);
//         }
//     }
// }
 
ll XOR(ll &x, ll &y)
{
   return (x | y) & (~x | ~y);
}

stack<int> st;
void DFS_ITER()
{
    st.push(0);
    int cnt=0;
    while(!st.empty())
    {
        int v=st.top();
        visited[v]=diff;    
        int lim=TR[v].size();
        fuck(i,0,lim)
        {
            int nei=TR[v][i];
            if(visited[nei]!=diff)
            {
                cnt++;
                st.push(nei);
            }
        }
        if(cnt==0)  //means all done from this vertex
        {
            done[v]=diff;
            st.pop();
            fuck(i,0,lim)
            {
                int nei=TR[v][i];
                if(done[nei]!=diff)
                {
                    arr[nei]=XOR(arr[nei],arr[v]);
                }
            }
        }
        cnt=0;
    }
}
 
void solve()
{
    diff=0;
    ans[0]=arr[0];
    fuck(i,1,r+2)
    {
        cout<<"iteration : "<<i<<endl;
        diff++;
        DFS_ITER();
        //tree repeating itself
        if(arr[0]==ans[0])
        {
            mark=i;
            break;
        }
        ans[i]=arr[0];
    }
}
 
int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("INP.txt","rt",stdin);
    #endif
    scan(n); scan(m);
    fuck(i,0,n-1)
    {
        scan(u); scan(v);
        TR[u].push_back(v);
        TR[v].push_back(u);
        //mem[u][u]=1;
    }
    
    fuck(i,0,n)
        scanl(arr[i]);
    r=0;
    fuck(i,0,m)
    {
        scanl(days[i]);
        if(days[i]>r)
            r=days[i];
    }
    solve();
    ll sol=-1;
    // fuck(i,0,m)
    // {
    //     if(mark==-1)
    //         printl(ans[days[i]]);
    //     else
    //     {
    //         sol=days[i]%mark;
    //         printl(ans[sol]);
    //     }
    // }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
} 
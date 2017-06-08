#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define M 10
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define test ll t; scanl(t); while(t--)
using namespace std;

//GLOBALS
vector<int> gr[M];
bool visited[M];
int gender[M];

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

// DFS
bool dfs(int s)
{
    stack<int> ver;
    ver.push(s);
    visited[s]=1;
    gender[s]=1;    //let i be male
    while(!ver.empty())
    {
        int st=ver.top();
        ver.pop();
        f(i,0,gr[st].size())
        {
            int v=gr[st][i];   // neighbour
            if(!visited[v])
            {
                ver.push(v);
                visited[v]=1;
                if(gender[v] == -1) // gender uncertain
                {
                    if(gender[st]==1)
                        gender[v]=0;
                    else
                        gender[v]=1;
                }
                else        //gender already calculated
                {
                    if(st == gender[v])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    fio;
    int sc=1;
	test
	{
        int n;
        ll m;
        scan(n); scanl(m);                  //n=nodes , m=existing roads
        f(i,0,n+1)
        {
            gender[i]=-1;
            visited[i]=0;
            gr[i].clear();
        }

        f(i, 0, m)
        {
            int u,v;
            // u----->v
            scan(u); scan(v);
            // gr[i] = (v,w) ==> theres as an edge from i--->v weighing w
            gr[--u].push_back(--v);
            //gr[v].push_back(u); //if graph is undirected
        }
        bool res;
        f(i,0,n)
        {
            if(!visited[i])
                res = dfs(i);            
            if(!res)
                break;
        }
        if(!res)
            cout<<"Scenario #"<<sc<<":"<<endl<<"Suspicious bugs found!"<<endl;
        else
            cout<<"Scenario #"<<sc<<":"<<endl<<"No suspicious bugs found!"<<endl;
        sc++;
    }
    cin>>t;
	return 0;
}
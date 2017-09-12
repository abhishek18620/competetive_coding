/******************************************
*  Author : elliot   
*  Created On : Sat Sep 02 2017
*  File : fill_the_matrix.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define SZ 10
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
vector<int> GR[SZ];
int b[SZ],visited[SZ],moves[SZ][3],n,q,counter1;
long long counter2=0;
struct indexes
{
    int l,r;
}mem[SZ];

bool DFS_iter(int u,int v)
{
    stack<int> vertex;
    vertex.push(v);
    counter2++;
    visited[v]=counter2;
    while(!vertex.empty())
    {
        int st=vertex.top();
        vertex.pop();
        int lim=GR[st].size();
        f(i,0,lim)
        {
            int nei=GR[st][i];
            if(visited[nei]!=counter2)
            {
                swap(mem[nei].l,mem[nei].r);
                if(nei==u)
                    return 0;
                vertex.push(nei);
                visited[nei]=counter2;        
                    
            }
        }
    }
    return 1;
}

bool solve()
{
    bool sol=1;
    f(i,0,q)
    {
        int u=moves[i][0];
        int v=moves[i][1];
        int diff=moves[i][2];
        if(diff==1)
        {
            if(b[u]!=counter1 and b[v]!=counter1)
            {
                b[u]=b[v]=counter1;
                if(u!=v)
                {
                    mem[u].l=0; mem[v].l=1;
                    mem[u].r=1; mem[v].r=0;
                    GR[u].eb(v);
                    GR[v].eb(u);
                }
                else
                {
                    mem[u].l=0; mem[u].r=1;
                }
            }
            else if(b[u]==counter1 and b[v]!=counter1)
            {
                b[v]=counter1;
                mem[v].l=1-mem[u].l;
                mem[v].r=1-mem[u].r;
                GR[u].eb(v);
                GR[v].eb(u);
            }
            else if(b[v]==counter1 and b[u]!=counter1)
            {
                b[u]=counter1;
                mem[u].l=1-mem[v].l;
                mem[u].r=1-mem[v].r;
                GR[v].eb(u);
                GR[u].eb(v);
            }
            else
            {
                if((mem[u].l==1 and mem[v].l==0) or (mem[u].l==0 and mem[v].l==1))
                {
                    GR[u].eb(v);
                    GR[v].eb(u);
                    continue;
                }
                else
                {
                    swap(mem[v].l,mem[v].r);
                    bool res=DFS_iter(u,v);
                    if(!res)
                        return 0;
                }
                GR[u].eb(v);
                GR[v].eb(u);
            }
        }
        else
        {
            if(b[u]!=counter1 and b[v]!=counter1)
            {
                b[u]=b[v]=counter1;
                if(u!=v)
                {
                    mem[u].l=0; mem[v].l=0;
                    mem[u].r=1; mem[v].r=1;
                    GR[u].eb(v);
                    GR[v].eb(u);
                }
                else
                {
                    mem[u].l=0; mem[u].r=1;
                }
            }
            else if(b[u]==counter1 and b[v]!=counter1)
            {
                b[v]=counter1;
                mem[v].l=mem[u].l;
                mem[v].r=mem[u].r;
                GR[u].eb(v);
                GR[v].eb(u);
            }
            else if(b[v]==counter1 and b[u]!=counter1)
            {
                b[u]=counter1;
                mem[u].l=mem[v].l;
                mem[u].r=mem[v].r;
                GR[u].eb(v);
                GR[v].eb(u);
            }
            else
            {
                if((mem[u].l==0 and mem[v].l==0) or (mem[u].l==1 and mem[v].l==1))
                {
                    GR[u].eb(v);
                    GR[v].eb(u);
                    continue;
                }
                else
                {
                    swap(mem[v].l,mem[v].r);
                    bool res=DFS_iter(u,v);
                    if(!res)
                        return 0;
                }
                GR[u].eb(v);
                GR[v].eb(u);
            }
        }
    }
    return 1;
}
//input and output
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
    counter1=0;
    test
    {
        //clearing  graph
        f(i,1,n+1)
            GR[i].clear();
        scan(n); scan(q);
        counter1++;
        bool sol=1;
        int te1,te2,val;
        for(int i=0;i<q;i++)
        {
            scan(moves[i][0]); scan(moves[i][1]); scan(moves[i][2]);
            if(moves[i][0]==moves[i][1] and moves[i][2]!=0)
                sol=0;
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

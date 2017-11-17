///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Thu Nov 17 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 10
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

vector<int> a[M];
struct outer
{
    int dis,back,front;
}outers[M];

inline int getmin(int x, int tot)
{
    return min(x,abs(tot-x));
}

int GetShortestDis(int i,int u ,int v)
{
    u--; v--;
    int tot=*(a[i].end()-1);
    int dis=abs(a[i][v]-a[i][u]);
    return getmin(dis,tot);
}

void scan(int &x)
{
    register int c = gc();
    bool neg=(c=='-')?1:0;
    x = 0;
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
    x*=(neg)?-1:1;
}

void write(int n)
{
	if(n<0){n=-n;putchar('-');}
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n,m,ai,u,v,w,te;
    int t; scan(t);
    while(t--)
    {
        scan(n); scan(m);
        f(i,1,n+1)
        {
            scan(ai);
            int sum=0;
            a[i].eb(0);
            f(j,0,ai)
            {
                scan(te);
                sum+=te;
                a[i].eb(sum);
            }
        }
        //now cycles
        int sum=0;
        scan(u); scan(v); scan(w);
        outers[1].front=u;
        outers[(1%n)+1].back=v;
        outers[1].dis=0;
        sum+=w;
        int k=0;
        for(k=2;k<n+1;k++)
        {
            scan(u); scan(v); scan(w);
            outers[k].front=u;
            int temp=GetShortestDis(k,outers[k].front,outers[k].back);
            outers[k].dis=sum+temp;//GetShortestDis(i,outers[i].front,outers[i].back);
            sum=outers[k].dis+w;
            outers[(k%n)+1].back=v;
            // if(i!=1)
            //     sum+=w+GetShortestDis(i,outers[i].front,outers[i].back);
            // else
            //     sum+=w;
        }
        sum+=GetShortestDis(1,outers[1].front,outers[1].back);
        //queries
        int c1,v1,c2,v2,sol;
        f(i,0,m)
        {
            scan(v1); scan(c1); scan(v2); scan(c2);
            if(c1>c2)
            {
                swap(c1,c2);
                swap(v1,v2);
            }
            //clockwise
            int dis1=abs(outers[c2].dis-outers[c1].dis)-GetShortestDis(c2,outers[c2].front,outers[c2].back)+GetShortestDis(c2,outers[c2].back,v2)+GetShortestDis(c1,outers[c1].front,v1);
            //anticlockwise
            int dis2=sum-(abs(outers[c2].dis-outers[c1].dis)+GetShortestDis(c1,outers[c1].front,outers[c1].back))+GetShortestDis(c1,outers[c1].back,v1)+GetShortestDis(c2,outers[c2].front,v2);
            sol=min(abs(dis1),abs(dis2));
            write(sol);
        }
        f(i,1,n+1)
            a[i].clear();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
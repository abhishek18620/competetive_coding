/******************************************
*  Author : abhishek18620
*  Created On : 2018-03-31
*  File : LCAtoRMQ
*******************************************/
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
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
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define trace2(x, y)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it,s) for(auto it: s)
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define foreachr(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

#ifdef LOCAL_DEFINE
    #include<assert.h>
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

int scanstr(char *str)
{
    register char c = getchar();
    register int len = 0;
    if(!(~c)) return -1;
    while(c < 33 && ~c) c = getchar();
    while(c != 10 && c != 32 && ~c){
        str[len] = c;
        c = getchar();
        len++;
    }
    str[len] = '\0';
    return 1;
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
int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        y = y>>1; x = x*x;
    }
    return res;
}
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------


/*
Euler: Euler Tour
Levels of nodes in Euler Tour( lev[Euler[i]] ) : level(i)
1st occur. of node i in Euler Tour : H[1,n]-H[i]
*/
int n,check=1;
vector< vector<int> > graph;
vector<int> Euler,level,visited,firstocc;
vii a;
int edgedel[M][M];

//WARNING : EULER TOUR NEEDS TO BE FIXED


// Euler Tour
void EulerTour()
{
    int oddst=-1;
    f(i,0,n)
    {
        if(graph[i].size()&1)
        {
            oddst=i;
            break;
        }
    }
    stack<int> st;
    st.push(oddst);
    level[oddst]=0;
    while(!st.empty())
    {
        int u=st.top();
        int ind=0;
        st.pop();
        Euler.eb(u);
        if(visited[u]!=check)
        {
            visited[u]=check;
            firstocc[u]=Euler.size()-1;
        }
        viter(v,graph[u])
        {
            if(edgedel[u][v]!=check and edgedel[v][u]!=check)
            {
                st.push(v);
                level[v]=level[u]+1;
                edgedel[u][v]=edgedel[v][u]=check;
            }
        }
        //trace4(ind,u,st.size(),!st.empty());
    }
    return;
}




// RMQ(Segment Tree)
struct node
{
    pii ele;
    void init(pii x)
    {
        ele=x;
    }
    void merge(node &l , node&r)
    {
        ele=min(l.ele , r.ele);
    }
};
vector<node> seg;

void build(int idx, int l ,int r)
{
    if(l==r)
    {
        seg[idx].ele=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    seg[idx].merge(seg[idx<<1],seg[idx<<1|1]);
}

pii query(int idx,int l,int r,int Ql,int Qr)
{
    if(l==r or (Ql==l and Qr==r))    //can't process the whole segment at once if not a multiple
        return seg[idx].ele;
    int mid=(l+r)>>1;
    pii resL,resR;
    if(Qr<=mid)  //query range lies in left subtree
        return query(idx<<1,l,mid,Ql,Qr);
    else if(Ql>mid)    //query range lies in right tree
        return query(idx<<1|1,mid+1,r,Ql,Qr);
    else    //query range lies in both trees
    {
        resL=query(idx<<1,l,mid,Ql,mid);
        resR=query(idx<<1|1,mid+1,r,mid+1,Qr);
        //trace5(l,r,mid,resL,resR);
        return min(resL,resR);
    }
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    while(t--)
    {
        check++;
        scan(n);
        graph.resize(n+1);
        f(i,1,n+1)
        {
            int m,child; scan(m);
            f(j,0,m)
            {
                scan(child);
                graph[i].eb(child);
            }
        }
        level.resize(n+1);
        visited.resize(n+1);
        firstocc.resize(n+1);
        a.resize(n+1);
        //preprocessing
        EulerTour();
        viter(v,Euler)
        {
            cout<<v<<endl;
            a[v]={level[v],v};
        }
        seg.resize(n<<2);
        build(1,1,n);
        int Q,l,r; scan(Q);
        f(i,0,Q)
        {
            scan2(l,r);
            pii sol=query(1,1,n,l,r);
            trace5(l,r,i,sol.F,sol.S);
            //print(sol);
        }
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>t;
    #endif
    return 0;
}


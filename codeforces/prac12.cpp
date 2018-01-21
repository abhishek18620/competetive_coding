// Segment Tree
/******************************************
*  Author : Terminal_Kido
*  Created On : Sun Jan 21 2018
*  File : prac12.cpp
*******************************************/
// It's my template. Don't you dare to select and copy it ;)
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
#define viter(it,s) for (auto it: s)
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
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
vi a;
int changes;

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

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n;
    scan(n);
    a.resize(n+1);
    f(i,1,n+1)
        scan(a[i]);
    seg.resize(n<<2);
    build(1,1,n);
    int q,type,l,r,x; scan(q);
    f(i,0,q)
    {
        scan(type);
        if(type==1)
        {
            changes=0;
            scan3(l,r,x);
            if(query(1,1,n,l,r,x))
            {
                if(changes>1) printf("NO\n");
                else printf("YES\n");
            }
            else printf("NO\n");
        }
        else
        {
            scan2(l,x);
            update(1,1,n,l,x);
        }
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

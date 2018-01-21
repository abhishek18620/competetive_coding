// SEGMENT TREE
// NORMAL UPDATE AND QUERYING
///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Mon Nov 22 2017               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#include <bits/stdc++.h>
using namespace std;
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
//#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795

#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

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
const int M = 5e5+9;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

void scan(int &x)
{
    register int c = gc();
    x = 0;
    for(;c<48 || c>57;c=gc());
    for(;c>47 && c<58;c=gc())
        x=(x<<1)+(x<<3)+c-48;
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
int readStr(char *str)
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
//GLOBALS
int n,q,L,R;
struct node
{
    int left,right,sz;
    ll val;
    node()
    {
        left=right=sz=0;
        val=0;
    }
    node(int x)
	{
        left=right=val=x;
        sz=1;
    }
	void merge(node &l,node &r)
	{
        if(l.sz==0)
            *this=r;
        else if(r.sz==0)
            *this=l;
        else
        {
            left=l.left+(l.left==l.sz)*r.left;
            right=r.right+(r.right==r.sz)*l.right;
            val=l.val+r.val+1LL*l.right*r.left;
            sz=l.sz+r.sz;
        }
    }
} segL[M<<2],segR[M<<2];    //segL for maxes less than L and segR for maxes less than R

void build(int ind, int l, int r)
{
    if(l==r)
    {
        segL[ind]=node(1);
        segR[ind]=node(1);
        return;
    }
    int mid=(l+r)>>1;
    build(ind<<1,l,mid);
    build(ind<<1|1,mid+1,r);
    segL[ind].merge(segL[ind<<1],segL[ind<<1|1]);
    segR[ind].merge(segR[ind<<1],segR[ind<<1|1]);
}
    
void update(int idx, int l , int r, int ind, int val)
{
    if(l==r)
    {
        segL[idx]=node(val<=L);
        segR[idx]=node(val<=R);
        return;
    }
    int mid=(l+r)>>1;
    if(l<=ind and ind<=mid)
    {
        update(idx<<1,l,mid,ind,val);
    }
    else
    {
        update(idx<<1|1,mid+1,r,ind,val);
    }
    segL[idx].merge(segL[idx<<1],segL[idx<<1|1]);
    segR[idx].merge(segR[idx<<1],segR[idx<<1|1]);
}

void query(node &ans,int ind, int l, int r, int u ,int v, char LorR)
{
    node *seg;
    if(LorR=='L')
        seg=segL;
    else
        seg=segR;
    if(l==u and r==v)
    {
        ans=seg[ind];
        return;
    }
    int mid=(l+r)>>1;
    if(v<=mid)  //search range lies in left subtree
        query(ans,ind<<1,l,mid,u,v,LorR);
    else if(u>mid)    //search range lies in right tree
        query(ans,ind<<1|1,mid+1,r,u,v,LorR);
    else    //search range lies in both trees 
    {
        node left,right;
        query(left,ind<<1,l,mid,u,mid,LorR);
        query(right,ind<<1|1,mid+1,r,mid+1,v,LorR);
        ans.merge(left,right);
    }
}


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    scan(n);scan(q);scan(L);scan(R);
    //scan4(n,q,L,R);
    L--;
    int ch,l,r;
    build(1,0,n-1);
    f(i,0,q)
    {
        scan(ch); scan(l); scan(r);
        //scan3(ch,l,r);
        if(ch==1)
        {
            l--;
            update(1,0,n-1,l,r);
        }
        else
        {
            l--; r--;
            node ans1,ans2;
            query(ans1,1,0,n-1,l,r,'R');
            query(ans2,1,0,n-1,l,r,'L');    
            writel(ans1.val-ans2.val);
        }
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

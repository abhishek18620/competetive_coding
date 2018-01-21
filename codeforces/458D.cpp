/******************************************
*  Author : Terminal_Kido
*  Created On : Sat Jan 20 2018
*  File : 458D.cpp
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
int BSIZE,n;
vi a,agcd;
int getBlock(int ind)
{
    return ind/BSIZE;
}
int gcdarr(int l , int r)
{
    int res = a[l];
    f(i,l+1,r+1)
        res = __gcd(a[i], res);
    return res;
}

bool changeable(int l, int r, int x)
{
    bool found=0;
    f(ind,l,r+1)
    {
        if(a[ind]%x!=0)
        {
            if(found) return 0;
            else found=1;
        }
    }
    return 1;
}

bool type1(int l , int r , int x)
{
    int leftblock=getBlock(l);
    int rightblock=getBlock(r);
    int defycnt=0;
    bool found=0;
    int blockgcd=1;
    f(block,leftblock+1,rightblock)
    {
        int currgcd=agcd[block];
        blockgcd=__gcd(blockgcd,currgcd);
        if(currgcd%x!=0)
        {
            if(found) return 0;
            int left=block*BSIZE;
            int right=left+BSIZE-1;
            if(!changeable(left,right,x)) return 0;
            found=1;
            // if(currgcd%x!=0) //divisible so just need to decrement smallest element
            // {
            //     if(!changeable(left,right,x)) return 0; 
            //     //else found=1;
            // }
        }
    }
    //solve boundaries
    int leftgcd=gcdarr(l,BSIZE*(leftblock+1)-1);
    int rightgcd=gcdarr(BSIZE*(rightblock),r);
    if(found)   // one element already changed
    {
        if(leftgcd==x and rightgcd==x) return 1;
    }
    else    // no element has been changed yet
    {
        if(leftgcd%x!=0 and rightgcd%x!=0) return 0;
        else
        {
            if(leftgcd%x==0 and rightgcd%x==0) return 1;
            else if(leftgcd%x!=0)
            {
                return changeable(l,BSIZE*(leftblock+1)-1,x);
            }
            else
                return changeable(BSIZE*(rightblock),r,x);
        }
    }
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
    a.resize(n);
    f(i,0,n) scan(a[i]);
    BSIZE=sqrt(n);
    int sqrtn=sqrt(n);
    int l=0;
    int r=sqrtn-1;
    //gcd calcultor for blocks
    f(i,0,sqrtn)
    {
        agcd.eb(gcdarr(l,r));
        l=r+1;
        r=r+sqrtn;
    }
    if(l<n)
    {
        agcd.eb(gcdarr(l,n-1));
    }
    int q,type,x; scan(q);
    f(i,0,q)
    {
        scan(type);
        if(type==1)
        {
            scan3(l,r,x);
            l--; r--;
            if(type1(l,r,x)) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            scan2(l,x);
            l--; a[l]=x;
            int block=getBlock(l);
            agcd[block]=gcdarr(block*BSIZE,block*BSIZE+BSIZE-1);
        }
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

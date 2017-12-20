/******************************************
*  Author : wshek
*  Created On : Sat Dec 16 2017
*  File : 451E.cpp
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


int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n;
    scan(n);
    int a[n+1];//need[n+1],need2[n+1];
    bool sq[n+1];
    int cntsqr=0;
    memset(sq,0,sizeof(sq));
    f(i,0,n)
    {
        scan(a[i]);
        if(a[i]==0)
        {
            sq[i]=1;
            cntsqr++;
            continue;
        }
        float check=sqrt(a[i]);
        if(check==int(check))
        {
            sq[i]=1;
            cntsqr++;
        }
        else
        {
            int sqr=int(check);
            int closest=min(a[i]-sqr*sqr,(sqr+1)*(sqr+1)-a[i]);
        }
    }
    int required=n/2-cntsqr;
    ll ans=0;
    if(required>0)
    {
        vector<int> need;
        f(i,0,n)
        {
            int sqr=sqrt(a[i]);
            if(sqr*sqr != a[i])
            {
                need.eb(min(a[i]-sqr*sqr,(sqr+1)*(sqr+1)-a[i]));
            }
        }
        sort(ALL(need));
        f(i,0,required)
            ans+=1ll*need[i];
    }
    else if(required < 0)   //need to remove its sq
    {
        required=-1*required;
        int notzero=0;
        f(i,0,n)
        {
            if(sq[i] and a[i]!=0)
                notzero++;
        }
        ans=min(required,notzero);
        required-=ans;
        ans+=required*1ll*2;
    }
    printl(ans);
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

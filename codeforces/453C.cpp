/******************************************
*  Author : Terminal_Kido
*  Created On : Tue Dec 19 2017
*  File : 453C.cpp
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
    int h; scan(h);
    int a[h+1],poiamb=-1;
    bool amb=0;
    scan(a[0]);
    int n=a[0];
    f(i,1,h+1)
    {
        scan(a[i]);
        if(a[i-1]>1 and a[i]>1 and !amb)
        {
            amb=1;
            poiamb=i;
        }
        n+=a[i];
    }
    if(!amb)
    {
        printf("perfect\n");
        return 0;
    }
    int t1[n+2],t2[n+2];
    int ctr=1;
    t1[1]=t2[1]=0;
    f(i,1,h+1)
    {
        int sz=a[i];
        if(i==poiamb)
        {
            t1[ctr+1]=ctr-(a[i-1]-1);
            t2[ctr+1]=ctr;
            f(j,2,sz+1)
            {
                t1[ctr+j]=t2[ctr+j]=ctr;
            }
            ctr+=sz;
            continue;
        }
        f(j,1,sz+1)
            t1[ctr+j]=t2[ctr+j]=ctr;
        ctr+=sz;
    }
    printf("ambiguous\n");
    f(i,1,n+1)
        printf("%d ",t1[i]);
    printf("\n");
    f(i,1,n+1)
        printf("%d ",t2[i]);
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
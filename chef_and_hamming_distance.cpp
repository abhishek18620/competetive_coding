///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Tue Dec 05 2017               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#include <bits/stdc++.h>
using namespace std;
#define M 100009
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
#define viter(it,s) for(auto it: s)
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

//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
int n,a[M],b[M],frq[M+2][2];
vector<int> loners;

bool find(int ind)
{
    int ele=a[ind];
    bool find=0;
    f(i,0,n)
    {
        if(a[i]!=ele)
        {
            swap(a[i],a[ind]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    f(i,0,M+1)
        frq[i][0]=frq[i][1]=-1;
    while(t--)
    {
        memset(frq,-1,sizeof(frq));
        scan(n);
        int dist=0,pairs=0;
        int lim=0;
        f(i,0,n)
        {
            scan(a[i]);
            if(frq[a[i]][0]==-1)
                frq[a[i]][0]=i;
            else
                frq[a[i]][1]=i;
            lim=max(a[i],lim);
        }
        pair<int,int> lst=mp(-1,-1);
        f(i,1,lim+1)
        {
            if(frq[i][0]!=-1)
            {
                if(frq[i][1]!=-1)   //pairs
                {
                    if(lst.F!=-1)   //ready to swap
                    {
                        swap(a[lst.F],a[frq[i][0]]);
                        swap(a[lst.S],a[frq[i][1]]);
                        lst=mp(-1,-1);
                    }
                    else
                    {
                        lst=mp(frq[i][0],frq[i][1]);
                    }
                }
                else    //singletons
                    loners.emplace_back(frq[i][0]);
            }
        }
        int sz=loners.size();
        int score=n;
        if(sz>=2)
        {
            int ini=0,end=sz-1;
            if(lst.F!=-1)
            {
                swap(a[loners[0]],a[lst.F]);
                swap(a[loners[1]],a[lst.S]);
                ini=2;
            }
            if(sz%2!=0)
                end=sz-2;
            f(i,ini,end)
            {
                swap(a[loners[i]],a[loners[i+1]]);
                i++;   
            }
            if(sz%2!=0) //odd loners
            {
                if(!find(loners[sz-1]))
                    score--;
            }
        }
        else if(sz==1)
        {
            if(lst.F!=-1)
            {
                swap(a[loners[0]],a[lst.F]);
                if(!find(lst.S))
                    score--;
            }
            else if(!find(loners[0]))
                score--;
            if(n==3)
                score--;
        }
        else
        {
            if(lst.F!=-1 and !find(lst.F))
                    score--;
            if(lst.S!=-1 and !find(lst.S))
                    score--;
        }
        printf("%d\n",score);
        f(i,0,n)
            printf("%d ",a[i]);
        printf("\n");
        loners.clear();
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<3.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sun Jan 15 2018               //
///////////////////////////////////////////
// It's my template. Don't you dare to select and copy it ;)
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000009
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
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define trace2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
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

void scan(int &x){
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

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
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------

void checker_util()
{
    f(x,10,1000001)
    {
        ll Sum=(1ll*x*(x+1))>>1;
        if(Sum&1)
            Sum--;
        Sum>>=1;
        //cout<<Sum<<endl;
        ll CurrSum=0;
        int used=0;
        fr(i,x,0)
        {
            if(CurrSum+i<=Sum)
            {
                CurrSum+=i;
                used++;
            }
            else
            {
                if(i>Sum-CurrSum)
                    used++;
                //trace4(n,i,Sum,Sum-CurrSum);
                break;
            }
            //trace2(Sum,CurrSum);
            //assert(CurrSum+i>Sum);
        }
        int left=x-used;
        //trace3(n,used,left);            
        assert(left>x/2);  //case of failure
    }
}

int check[M];

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
        int x,n; scan(x); scan(n);
        memset(check,0,sizeof(int)*(n+2));
        check[x]=2;
        ll Sum=(1ll*n*(n+1))>>1;
        Sum-=x;
        if(Sum&1)
        {
            printf("impossible\n");
            continue;
        }
        Sum>>=1;
        //cout<<Sum<<endl;
        ll CurrSum=0;
        int used=0;
        bool poss=1;
        fr(i,n,1)
        {
            if(CurrSum+i<=Sum)
            {
                if(i==x) continue;
                check[i]=1;
                CurrSum+=i;
                used++;
            }
            else
            {
                if(i>Sum-CurrSum)
                {
                    if(Sum-CurrSum==x)
                    {
                        if(x==1)
                        {
                            if(i<=2)
                                poss=0;
                            check[i+1]=0;
                            check[i]=check[2]=1;
                            break;
                        }
                        else if(x==2)
                        {
                            if(i<=3)
                                poss=0;
                            check[i+1]=0;
                            check[i]=check[3]=1;
                            break;
                        }
                        else
                            continue;
                    }
                    check[Sum-CurrSum]=1;
                    used++;
            //        trace2(Sum,CurrSum);
                    break;
                }
                //trace4(n,i,Sum,Sum-CurrSum);
            }
            //trace2(Sum,CurrSum);
            //assert(CurrSum+i>Sum);
        }
        if(!poss)
        {
            printf("impossible\n");
            continue;
        }
        f(i,1,n+1)
        {
            printf("%d",check[i]);
        }
        cout<<endl;
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>t;
    #endif
    return 0;
}

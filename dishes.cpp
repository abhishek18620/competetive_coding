// DYNAMIC PROGRAMMING
///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 10
#define INF 1e18+9
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scanf("%d",&t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//#define scan(x) scanf("%d",&x)
//#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;

vector<int> a[M];
ll dp[M];
int n,m;

inline int OtherIndex(int j,int len)
{
   return j==0?len-1:j-1;
}

ll solve()
{
    ll poss1,poss2,prvposs1,prvposs2;
    int sz;
    f(i,0,n)
    {
        sz=a[i].size();
        poss1=poss2=-1*INF;
        f(j,0,sz)
        {
            ll beg=a[i][j];
            ll end=a[i][OtherIndex(j,sz)];
            if(i==0)
                dp[j]=0;
            else
                dp[j]=max(prvposs1-beg*i,prvposs2+beg*i);
            
            poss1=max(poss1,dp[j]+end*(i+1));
            poss2=max(poss2,dp[j]-end*(i+1));
        }
        prvposs1=poss1;
        prvposs2=poss2;
    }
    ll sol=0;
    f(i,0,sz)
        sol=max(sol,dp[i]);
    return sol;
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


int main()
{
    //fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    test
    {
        scan(n);
        //memset(dp,0,sizeof(dp));
        int te;
        //input
        f(i,0,n+1)
            a[i].clear();
        f(i,0,n)
        {
            scan(m);
            f(j,0,m)
            {
                scan(te);
                a[i].eb(te);
            }
        }

        ll ans=solve();
        writel(ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

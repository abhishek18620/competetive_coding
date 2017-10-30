///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Oct 28 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 750009
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
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
using namespace std;

int n,a[M],sol[M];

inline int modsum(int a, int b)
{
    return ((a%mod)+(b%mod))%mod;
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
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    while(t--)
    {
        memset(sol,0,sizeof(sol));
        scan(n);
        f(i,0,n)
            scan(a[i]);
        sort(a,a+n);
        f(i,0,n)
        {
            int ele=a[i];
            sol[ele]++;
            for(int j=ele+ele;j<M;j+=ele)
                if(sol[j]+sol[ele]>=mod) sol[j]=(sol[j]+sol[ele])-mod;
        }
        int ans=0;
        f(i,0,n)
            if(ans+sol[a[i]]>=mod) ans=(ans+sol[a[i]])-mod;
        print(ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
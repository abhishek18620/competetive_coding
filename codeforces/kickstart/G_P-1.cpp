/******************************************
*  Author : abhishek18620   
*  Created On : Sat Oct 21 2017
*******************************************/
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
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
#define MOD 1000000007
using namespace std;

//GLOBALS
int a,n,p;

ll modmul(ll a,ll b,ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
        res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = modmul(res,x,p);

        y = y>>1; x = modmul(x,x,p);
    }
    return res;
}

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/A-large-practice.in","rt",stdin);
    freopen("./kickstart/output.txt","w",stdout);
    #endif
    int t; scan(t);
    ll x,ans;
    f(tt,1,t+1)
    {
        scan(a); scan(n); scan(p);
        // a=a%p;
        // //(a^n!)%p
        // ans=a;
        // fr(i,n,1)
        // {
        //     //int times=i;
        //     ans=ans%p;
        //     x=ans;
        //     //ans=x;
        //     f(j,0,i-1)
        //     {
        //         ans=modmul(ans,x,p);
        //     }
        // }
        f(i,1,n+1)
        {
            a=power(a,i);
        }
        printf("Case #%d: %d\n",tt,a);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}
    
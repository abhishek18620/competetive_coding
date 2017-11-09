///////////////////////////////////////////
//  Author : bvcoe_coders                 //
//  Date : Sat Nov 04 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 60
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
// #define scan(t) scanf("%d",&t)
// #define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

int a[M],n;

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
        scan(n);
        f(i,0,n)
            scan(a[i]);
        int sum=0,pro=0,ans=0;
        f(i,0,n)
        {
            sum=a[i];
            pro=a[i];
            f(j,i+1,n)
            {
                if(pro==sum)
                    ans++;
                pro*=a[j];
                sum+=a[j];
            }
            if(sum==pro)
                ans++;
        }
        print(ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

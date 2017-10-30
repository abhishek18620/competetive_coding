///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Thu Oct 26 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define M 100
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
#define viter(it,s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

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
    char a[M];
    int t; scan(t);
//    scanf("%s",a);
    while(t--)
    {
        scanf("%s",a);
        int len=strlen(a);
        vector<int> blocks;
        int curr=1;
        f(i,1,len)
        {
            if(a[i]!=a[i-1])
            {
                blocks.eb(curr);
                curr=1;
            }
            else
                curr++;
        }
        blocks.eb(curr);
        int ind=0,prvind=0;
        ll ans=0;
        viter(sz,blocks)
        {
            ans+=1ll*sz*(sz-1)/2;
            if(ind+sz<len)
                ind+=sz;
            if(ind-prvind>1)
            {
                if(a[ind]==a[prvind])
                    ans++;
                prvind=ind-1;
            }
        }
        printl(ans);
        blocks.clear();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int n;
        cin>>n;
    #endif
    return 0;
}

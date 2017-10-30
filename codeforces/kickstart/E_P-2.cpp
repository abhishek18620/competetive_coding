// Map is implemented as balanced tree structure that is why 
//it is possible to maintain an order between the elements (by specific tree traversal).
//Time complexity of map operations is O(Log n) while for unordered_set, it is O(1) on average.

/******************************************
*  Author : abhishek18620   
*  Created On : Sat Oct 21 2017
*******************************************/
#include <bits/stdc++.h>
#define M 5009
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
#define viter(i,s) for (auto i: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
int n,a[M];
set<ll>st;
map<ll,ll> frq;

// range=[x,y]
ll btw(ll x,ll y)
{
    return (upper_bound(a,a+n,y) - lower_bound(a,a+n,x));
}

ll NC2(ll n)
{
	return (n *1ll*(n - 1))/2;
}
ll NC3(ll n)
{
	return (n*(n - 1)*(n - 2))/6;
}

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/B-large-practice.in","rt",stdin);
    freopen("./kickstart/output.txt","w",stdout);
    #endif
    int t; scan(t);
    f(tt,1,t+1)
    {
        scan(n);
        f(i,0,n)
        {
            scan(a[i]);
            frq[a[i]]++;
            st.insert(a[i]);
        }
        ll l,fr,ans=0,same;
        sort(a,a+n);
        viter(it,frq)       //equal lengthed sides
        {
            l=it.F; fr=it.S;
            if(fr>=2)   //opposte sides
            {
                same=NC2(fr);
                f(y,0,n)
                {
                    ll x=a[y];
                    if(x==l)
                        continue;
                    // range= [a+1,a+2*same_one(l)-1]  a<b
                    ll te=btw(x+1,x+2*l-1);
                    if(l>=x+1 and l<=x+2*l-1)
                        te-=fr;
                    ans+=te*same;             
                }
            }
        }
        // third side is the same lengthed too
        viter(it,st)
        {
            if(frq[it]<3)
                continue;
            same+=NC3(frq[it]);
            viter(j,st)
            {
                if(it!=j)
                {
                    if((j>it and j<=3*it-1) or j<it)
                        ans+=NC3(frq[it])*frq[j];
                }
            }
        }
        st.clear();
        frq.clear();
        printf("Case #%d: %lld\n",tt,ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

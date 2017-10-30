/******************************************
*  Author : wshek
*  Created On : Thu Oct 26 2017
*  File : 443A.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 10000
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
#define MOD 1000000007
using namespace std;

vector< pair<int,int> > a;

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n,u,v;
    scan(n);
    f(i,0,n)
    {
        scan(u);
        scan(v);
        a.eb(mp(u,v));
    }
    int ans=0,ind=-1;
    f(i,0,n)
    {
        int min=a[0].F+(i*a[0].S);
        f(j,0,n)
        {
            if(min>a[j].F+(i*a[j].S))
                ind=j;
        }
        ans=a[ind].F+(i*a[ind].S);
        a[ind].F=INF;
    }
    print(ans);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

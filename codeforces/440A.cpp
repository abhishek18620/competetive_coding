/******************************************
*  Author : wshek
*  Created On : Sun Oct 15 2017
*  File : 440A.cpp
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

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif

    int a[10],b[10],te,n,m;
    scan(n); scan(m);
    f(i,0,10)
        a[i]=b[i]=0;

    f(i,0,n)
    {
        scan(te);
        a[te]=1;
    }
    f(i,0,m)
    {
        scan(te);
        b[te]=1;
    }
    int mina=-1,minb=-2;
    
    f(i,1,10)
    {
        if(a[i]==1 and b[i]==1)
        {
            print(i);
            return 0;    
        }
    }
    
    f(i,1,10)
    {
        if(a[i]==1)
        {
            mina=i;
            break;
        }
    }
    f(i,1,10)
    {
        if(b[i]==1)
        {
            minb=i;
            break;
        }
    }
    int sol=0;
    if(mina<minb)
    {
        sol=mina*10+minb;
        print(sol);
    }
    else if(minb<mina)
    {
        sol=minb*10+mina;
        print(sol);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

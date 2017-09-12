/******************************************
*  Author : wshek   
*  Created On : Tue Aug 29 2017
*  File : 430B.cpp
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
#define write(t) printf("%d",t)
#define writel(t) printff("%lld",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

int main()
{
    fio;
    int r,d,xi,yi,ri,p,ans=0;
    scan(r); scan(d); scan(p);
    float centre_dis=0.0;
    int addition=0;
    while(p--)
    {
        scan(xi); scan(yi); scan(ri);
        centre_dis=sqrt(yi*yi+xi*xi);
        addition=d+ri;
        if(centre_dis>=addition)
        {
            if(centre_dis<=abs(r-ri))
                ans++;
        }
    }
    printf("%d\n",ans);
    cin>>r;
	return 0;
}

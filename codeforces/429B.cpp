/******************************************
*  Author : wshek   
*  Created On : Fri Aug 18 2017
*  File : 429B.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 1000000
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
    int n; scan(n);
    ll a[n],sum=0;
    bool second=1;
    f(i,0,n)
    {
        scanl(a[i]);
        sum+=a[i];
    }
    if(sum&1)
    {
        printf("First\n");
    }
    else
    {
        f(i,0,n-1)
        {
            if(a[i]&1)
            {
                second=0;
                break;
            }
        }
        if(second)
            printf("Second\n");
        else
            printf("First\n");
    }
    cin>>n;
    return 0;
}

/******************************************
*  Author : wshek   
*  Created On : Mon Sep 25 2017
*  File : 436C.cpp
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
    int a,b,k,f;
    scan(a); scan(b); scan(f); scan(k);
    int ans=0;
    if(b<f)
    {
        print(-1);
        return 0;
    }
    int cir=1,need=2*(a-f),curr=b-f;
    if(k==1)
    {
        need=a-f; curr=b-f;
        if(need>b)
        {
            print(-1);
            //return 0;
        }
        else if(need>curr)
            print(1);
        else
            print(0);
        return 0;
    }
    bool ret=0;
    while(cir<k)
    {
        if(need>b)
        {
            ans=-1;
            break;
        }
        if(need>curr)   //refuel
        {
            ans++;
            cir++;
            curr=b-need;
            if(ret)
            {
                need=2*(a-f);
                ret=0;
            }
            else
            {
                need=2*f;
                ret=1;
            }
        }
        else
        {
            curr=curr-need;
            cir++;
            if(ret)
            {
                need=2*(a-f);
                ret=0;
            }
            else
            {
                need=2*f;
                ret=1;
            }
        }
    }
    if(ans!=-1)
    {
        if(k&1)
        {
            if(curr<a-f)
                ans++;
        }
        else if(curr<f)
            ans++;
    }
    print(ans);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

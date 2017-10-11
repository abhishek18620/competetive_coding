/******************************************
*  Author : wshek
*  Created On : Thu Oct 05 2017
*  File : 438B.cpp
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

//l<r
bool btw(int hand, int l , int r)
{
    if(hand >l and hand<r)
        return 1;
    return 0;
}

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int h,m,s,t1,t2;
    scan(h); scan(m); scan(s); scan(t1); scan(t2);
    int t1s=t1*5,t2s=t2*5;
    if(t1s==60)
        t1s=59;
    if(t2s==60)
        t2s=59;
    // if(btw(h,t1,t2) and btw(m,t1,t2) and btw(s,t1,t2))
    //         dir1=1;
    int l1,r1,l2,r2,l1s,r1s,l2s,r2s;
    if(t1<t2)
    {
        l1=t1; r1=t2;
        l1s=t1s; r1s=t2s;
    }
    else    //t1>t2
    {
        l1=t2; r1=t1;
        l1s=t2s; r1s=t1s;
    }
    //check
    bool ans=0,enter=0,hb=0,mb=0,sb=0;
    if(btw(h,l1,r1))    //check if hands in upper segment
    {
        hb=1;
        if(btw(m,l1s,r1s))
        {
            mb=1;
            if(btw(s,l1s,r1s))
                sb=1;
        }
    }
    else if(btw(m,l1s,r1s))
    {
        mb=1;
        if(btw(s,l1s,r1s))
            sb=1;
    }
    else if(btw(s,l1s,r1s))
            sb=1;
    //printing
    if((hb and mb and sb) or (!hb and !mb and !sb))
        printf("YES\n");
    else
        printf("NO\n");

    // if(!enter)    //check if hands in lower segment
    // {
    //     if(t1<t2)
    //     {
    //         l1=t1; r1=t2;
    //         l1s=t1s; r1s=t2s;
    //     }
    //     else    //t1>t2
    //     {
    //         l1=t2; r1=t1;
    //         l1s=t2s; r1s=t1s;
    //     }

    //     if(btw(h,l1,r1))
    //     {
    //         if(btw(m,l1s,r1s))
    //         {
    //             if(btw(s,l1s,r1s))
    //                 ans=1;
    //         }
    //     }

    // }

    // if(ans)
    //     printf("YES\n");
    // else
    //     printf("NO\n");
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}
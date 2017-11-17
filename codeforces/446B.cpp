/******************************************
*  Author : wshek
*  Created On : Fri Nov 17 2017
*  File : 446B.cpp
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
#define printl(t) printf("%lld\n",t)
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
    int n;
    scan(n);
    int a[n+2];
    pair<int,int> cankill[n+2];
    f(i,1,n+1)
        scan(a[i]);
    cankill[1]=mp(0,0);
    f(i,2,n+1)
    {
        if(i-a[i]<=i-1)
        {
            if(i-a[i]==0)
                cankill[i]=mp(1,i-1);
            else
                cankill[i]=mp(i-a[i],i-1);
        }
        else
            cankill[i]=mp(0,0);
        //alive[i]=mp(0,i-1);
    }
    int alive=n,ptr1=n-1,ptr2=0;
    //people between ptr2 and ptr 1 are all alive
    fr(i,n,1)
    {
        if(cankill[i].F!=0)
        {
            if(ptr1>i-1)
                ptr1=i-1;
            if(cankill[i].F<=ptr1) //can kill upto ptr1
            {
                if(cankill[i].F<1)
                {
                    alive-=ptr1;
                    break;
                }
                //kill everyone ptr==ptr2
                alive-=ptr1-cankill[i].F+1;
                ptr1=cankill[i].F-1;
            }
            // else
            // {
            //     //kill who can be killed and update ptr2
            //     if(cankill[i].F<=ptr2)
            //     {
            //         alive-=ptr2-cankill[i].F+1;
            //         ptr2=cankill[i].F-1;
            //     }
            // }
        }
    }
    print(alive);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

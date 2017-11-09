///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 100
#define INF 1e17
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
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
        freopen("INP.txt","w",stdout);
    #endif
    long long l=1;  
    long long r=10000;
        //r/=(t+1);
        // cout<<4<<endl;
        // f(j,1,5)
        // {
            cout<<10000<<" "<<30000;
            cout<<endl;
            f(i,0,10000)
                cout<<i+1<<" ";
            cout<<endl;
            f(i,0,9999)
                cout<<i+1<<" ";
            cout<<endl;
            int te=1000000000;
            f(i,0,30000)
                cout<<"0 1 "<<(te--)<<endl;
            // {
            //     //srand(i);
            //     cout<<(rand()%(l-r+1))<<" ";
            // }
            cout<<"\n";
        //}

    // #ifdef LOCAL_DEFINE
    //     cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
    //     cin>>m;
    // #endif
    return 0;
}
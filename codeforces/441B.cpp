/******************************************
*  Author : wshek
*  Created On : Mon Oct 16 2017
*  File : 441B.cpp
*******************************************/
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
#define viter(s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

int n,k,m;
vector<int> a;

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int te;
    scan(n); scan(k); scan(m);
    f(i,0,n)
    {
        scan(te);
        a.eb(te);
    }
    struct rem{
        int ctr=0;
        vector<int> nums;
    } mem[M];

    f(i,0,m)
    {
        mem[i].ctr=0;
    }
    f(i,0,n)
    {
        int r=a[i]%m;
        mem[r].ctr++;
        mem[r].nums.eb(a[i]);
    }
    bool possible=0;
    f(i,0,m)
    {
        if(mem[i].ctr>=k)
        {
            possible=1;
            printf("Yes\n");
            f(j,0,k)
            {
                printf("%d ",mem[i].nums[j]);
            }
            printf("\n");
            break;
        }
    }
    if(!possible)
        printf("No\n");
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}
/******************************************
*  Author : wshek
*  Created On : Fri Nov 17 2017
*  File : 446C.cpp
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



int gcd(int a, int b)
{
    if(b == 0)
    {
            return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}



int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n;
    scan(n);
    int a[n+1],onesi[n+1];
    int arrgcd=0,ones=0;
    f(i,0,n)
    {
        scan(a[i]);
        onesi[i]=ones+(a[i]==1);
        ones=onesi[i];
        arrgcd=__gcd(arrgcd,a[i]);
    }
    if(arrgcd>1)
    {
        printf("-1\n");
        return 0;
    }
    if(ones>0)
    {
        print(n-ones);
        return 0;
    }

    //find smallest segment whose gcd=1
    int gcdij=0,ans=INF;
    f(i,0,n)
    {
        gcdij=0;
        f(j,i,n)
        {
            gcdij=__gcd(gcdij,a[j]);
            if(gcdij==1)
            {
                int steps = j-i+(n-1); // (j-i+1)to make j th elemnt 1 and then n-1 to propagate this value 
                ans=min(ans,steps);
            }
        }
    }
    print(ans);
    int x,y,res;
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

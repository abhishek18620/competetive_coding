    /******************************************
    *  Author : wshek
    *  Created On : Fri Nov 17 2017
    *  File : 446A.cpp
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
        int n,a,max1,max2; scan(n);
        int b[n+1];
        ll rem=0;
        f(i,0,n)
        {
            scan(a);
            rem+=1LL*a;
        }
        f(i,0,n)
        {
            scan(b[i]);
        }
        max1=b[0]; max2=b[1];
        if(max1<max2) swap(max1,max2);
        f(i,2,n)
        {
            if(b[i]>=max1)
            {
                max2=max1;
                max1=b[i];
            }
            else if(b[i]>=max2)
            {
                max2=b[i];
            }
        }
        if(ll(max1)+ll(max2)>=rem)
            printf("YES\n");
        else
            printf("NO\n");
        #ifdef LOCAL_DEFINE
            cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
            cin>>n;
        #endif
        return 0;
    }

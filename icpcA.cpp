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


int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    int n,m,d,D;
    while(t--)
    {
        scan(n);
        scan(m);
        scan(d);
        scan(D);

        int minreq=n*d;
        int maxreq=n*D;
        if(maxreq<m or minreq>m)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            f(i,1,n+1)
            {
                f(j,0,(m/n))
                {
                    int k=i+j;
                    if(k>n)
                        k-=n;
                    printf("%d %d\n",i,k);
                }
            }
            if(m%n!=0)
            {        
                f(i,1,(m%n)+1)	
                {
                    int k=i-1;
                    if(k==0)
                        k=n;
                    printf("%d %d\n",i,k);
                }
            }
        }
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

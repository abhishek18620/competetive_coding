#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i, j, k) for (int i = j; i < k; i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

bool check(ll n)
{
	if(n==1 or n==7)
		return 1;
	else if(n/10==0)
	    return 0;
	ll x,sum=0;
    while(n!=0)
    {
	    x=n%10;
		sum = sum + x*x;
		n=n/10;	
	}
	check(sum);
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    ll t,n,m; cin>>t;
    while(t--)
    {
        int count=0;
        cin>>n>>m;
        f(i,n,m+1)
        {
            if(check(i)==1)
                count++;
        }
        cout<<count<<endl;
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

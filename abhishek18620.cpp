#include <bits/stdc++.h>
#define M 100009
#define INF 999999
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
using namespace std;


//GLOBALS
ll a[M],sum[M];
int main()
{
	fnf;
	int t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll sum1=0, sum2=0;
        ll ctr=0;
        ll te;
        fuck(i,0,n)
            cin>>a[i];
        sort(a,a+n);
        sum[0]=0;
        fuck(i,1,n+1)
        {
            if(a[i-1]<0)
            {
                sum1+=a[i-1];
                sum[i]=sum[i-1]+a[i-1];
            }
            else
            {
                sum2+=a[i-1];
                ctr++;
            }
        }
        ll ans=sum2*ctr+sum1;
        if(a[n-1]<=0) 
            cout<<sum1<<endl;
        else
        {
            int ctr_new=ctr;
            int ind=n-1-ctr;
            ll sum_new=sum2;
            fuck_rev(i,ind,0)
            {
                sum_new=sum2+sum[ind+1]-sum[i];
                ll temp_ans=sum_new*(++ctr_new) + sum[i];
                if(temp_ans > ans)
                    ans=temp_ans;
            }
            cout<<ans<<endl;
        }
    }
    cin>>t;
	return 0;
}
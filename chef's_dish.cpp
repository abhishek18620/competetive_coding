// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; cin>>t; while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;


//GLOBALS
ll a[M],sum[M];
int main()
{
	fio;
	test
	{
        ll n; cin>>n;
        ll sum1=0, sum2=0;
        ll ctr=0;
        ll te;
        f(i,0,n)
            cin>>a[i];
        sort(a,a+n);
        sum[0]=0;
        f(i,1,n+1)
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
            int ind=n-1-ctr; //index of first negative number
            ll sum_new=sum2;
            fr(i,ind,0)
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
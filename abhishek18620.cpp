#include <bits/stdc++.h>
#define M 100005
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
using namespace std;

ll a[M],b[M],c[M],sum_a[M],sum_c[M],mod=1e9+7;
ll mod_mult(ll a,ll b)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

int bsearch_a(ll s, int hi, int lo)
{
	int mid=-1,ind=-1;
	if(s > a[hi])
		return -1;
	while(hi>lo)
	{
		mid=(hi+lo)/2;
		if(a[mid]<=s)
			lo=mid+1;
		else
            hi=mid;
	}
    if(a[lo]<=s)
        return lo;
    else if(lo==0)
        return -2;
    else
        return lo-1;
}

int bsearch_c(ll s, int hi, int lo)
{
    int mid=-1,ind=-1;
	if(s > c[hi])
		return -1;
	while(hi>lo)
	{
		mid=(hi+lo)/2;
		if(c[mid]<=s)
			lo=mid+1;
		else
            hi=mid;
	}
	if(c[lo]<=s)
        return lo;
    else if(lo==0)
        return -2;
    else
        return lo-1;
}

main()
{
	fnf;
	int t; cin>>t;
    while(t--)
	{
        int p,q,r;
        cin>>p>>q>>r;
        fuck(i,0,p)
            cin>>a[i];
        fuck(i,0,q)
            cin>>b[i];
        fuck(i,0,r)
            cin>>c[i];
        sort(a,a+p); sort(b,b+q); sort(c,c+r);
        ll sum=0;
        fuck(i,0,r)
        {
            sum_c[i]=sum+c[i];
            sum=sum_c[i];
        }
        sum=0;
        fuck(i,0,p)
        {
            sum_a[i]=sum+a[i];
            sum=sum_a[i];
        }
        ll ans=0,sum1=0,sum2=0;
        fuck(i,0,q)
        {
            ll num=b[i];
            //bsearch num in both a & c.
            int ind1=bsearch_a(num,p-1,0);
            int ind2=bsearch_c(num,r-1,0);
            ll n1=0,n2=0;
            if(ind1==-2)
                n1=0;
            else if(ind1==-1)
            {
                ind1=p-1;
                n1=p;
            }
            else
                n1=ind1+1;
            if(ind2==-2)
                n2=0;
            else if(ind2==-1)
            {
                ind2=r-1;
                n2=r;
            }
            else
                n2=ind2+1;
            sum1=0; sum2=0;
            if(n1>0 and n2>0)
            {
                sum1=n2*num + sum_c[ind2];
                sum2=n1*num + sum_a[ind1];
            }
            ans+=mod_mult(sum1,sum2);
        }
        cout<<ans%mod<<endl;
    }
}
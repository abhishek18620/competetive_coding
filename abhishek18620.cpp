#include <bits/stdc++.h>
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;
     
ll fac,k1,k2;
void gcd(ll A, ll B)
{
    if(B == 0)
    {
        fac = A;
        k1 = 1;
        k2 = 0;
    }
    else 
    {
        gcd(B, A%B);
        ll temp = k1;
        k1 = k2;
        k2 = temp - (A/B)*k2;
    }
}

ll mult_mod(ll a,ll b,ll mod)
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

ll modInverse(ll a, ll m)
{
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
	return 0;
	while (a > 1)
	{
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	if (x1 < 0)
	x1 += m0;
	return x1;
}


int main()
{
    fnf;
	ll m1=1e9+7;
    ll m2=1e9+9;
    ll n,a,b,den,sol1,sol2,a1,a2,inv1,inv2;
	int t; cin>>t;
    while(t--)
    {
        cin>>n;
        --n;
        if(n==0)
            cout<<"0 0"<<endl;
        else if(n==1 or n==2)
            cout<<"1 1"<<endl;
        else
        {
            den=2*n-1;
            if(n%2==0)
            {
                a=n/2;
                b=n+1;
                gcd(b,den);
                if(fac>1)
                {
                    b=b/fac;
                    den=den/fac;
                }

                gcd(a,den);
                if(fac>1)
                {
                    a=a/fac;
                    den=den/fac;
                }
            }
            else
            {
                a=(n+1)/2;
                b=n;
                
                gcd(b,den);
                if(fac>1)
                {
                    b=b/fac;
                    den=den/fac;
                }

                gcd(a,den);
                if(fac>1)
                {
                    a=a/fac;
                    den=den/fac;
                }
            }
            a1 = mult_mod(a,b,m1);
            a2 = mult_mod(a,b,m2);
            inv1=modInverse(den,m1);
	        inv2=modInverse(den,m2);
            sol1=mult_mod(a1,inv1,m1);
            sol2=mult_mod(a2,inv2,m2);
            cout<<sol1<<" "<<sol2<<endl;
        }
    }
    cin>>t;
	return 0;
}
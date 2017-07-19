#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define rep(i, j, k) for (int i = j; i < k; i++)
#define rep_r(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
using namespace std;

ll fac,c1,c2;

void gcd(ll A, ll B)
{
    if(B == 0)
    {
        fac = A;
        c1 = 1;
        c2 = 0;
    }
    else 
    {
        gcd(B, A%B);
        ll temp = c1;
        c1 = c2;
        c2 = temp - (A/B)*c2;
    }
}

ll modmul(ll a,ll b,ll mod)
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
		// q is quotient
		q = a / m;

		t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;

		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}

	// Make x1 positive
	if (x1 < 0)
	x1 += m0;

	return x1;
}


void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(int &x){
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
    fast;
	ll m1=1e9+7;
    ll m2=1e9+9;
    ll n,a,b,den,sol1,sol2,a1,a2,inv1,inv2;
	ll t; scanl(t); 
    while(t--)
	{
        scanl(n);
        --n;
        if(n==0)
            cout<<"0 0"<<endl;
        else if(n==1 or n==2)
            cout<<"1 1"<<endl;
        else
        {
            den=2*n-1;
            //n is even
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
            else        // n is odd
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
            //sol1=modDivide(a,b,den,m1);
            a1 = modmul(a,b,m1);
            a2 = modmul(a,b,m2);
            inv1=modInverse(den,m1);
	        inv2=modInverse(den,m2);
            sol1=modmul(a1,inv1,m1);
            sol2=modmul(a2,inv2,m2);
            cout<<sol1<<" "<<sol2<<endl;
        }
    }
    cin>>t;
	return 0;
}
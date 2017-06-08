#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define gc() getchar_unlocked()
#define test ll t; scan(t); while(t--)
using namespace std;

ll gcd(ll x, ll y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

void write(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	//fio;
	test
	{
        ll a,b,c,d,ans;
        scan(a); scan(b); scan(c); scan(d);
		if(a > b)
		{
			if(c>d)
				ans=(a-b)%(gcd(c,d));
			else
				ans=(a-b)%(gcd(d,c));
		}
		else
		{
			if(c>d)
				ans=(b-a)%(gcd(c,d));
			else
				ans=(b-a)%(gcd(d,c));
		}
		write(ans);
    }
	cin>>t;
	return 0;
}
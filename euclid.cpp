// Iterative C++ program to find modular inverse using
// extended Euclid algorithm
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// Returns modulo inverse of a with respect to m using
// extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1
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

// Driver program to test above function
int main()
{
    ll m1=1e9+7;
    ll m2=1e9+9;
    ll a,b;
	cin>>a>>b;
    ll a1 = a%m1;
    ll a2 = a%m2;
    ll inv1=modInverse(3,m1);
    ll inv2=modInverse(3,m2);
    ll sol1=(a1*inv1)%m1;
    ll sol2=(a2*inv2)%m2;
    cout<<sol1<<" "<<sol2<<endl;
    cin>>a;
    return 0;
}

#include <bits/stdc++.h>
#define M 10000
#define INF 999999
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define f1(i, j, k) for (int i = j; i < k; i+=2)
#define f2(i, j, k) for (int i = j; i <= k; i++)
using namespace std;

void scan(ll &x){
    	register ll c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	vector<ll> prime;
	prime.push_back(2); prime.push_back(3);
	f1(i,5,32000)				// calculate all primes till 32000
	{
		int s=prime.size();
		bool flag=1;
		int lim = sqrt(i)+1; 
		f(j,0,s)
		{
			if(prime[j] >= lim)
				break;
			else if(i%prime[j] == 0)
			{
				flag=0;	
				break;
			}
		}
		if(flag)
			prime.push_back(i);
	}

	int t; cin>>t;
    while(t--)
	{
		ll m,n; scan(m); scan(n);
		set<ll> comp;				// composites
		if(m<2) 
			m=2;
		int s=prime.size();
		int lim=sqrt(n)+1;
		f(i,0,s)
		{
			int st;
			int te = prime[i];
			if(prime[i] >= lim)
				break;
			else if(prime[i] >= m)
				st=prime[i]*2;
			else
			{
				//result = ((number + multiple/2) / multiple) * multiple;
				st= ((m + prime[i]/2) / prime[i]) * prime[i];
				if(st < m)
					st+=prime[i];
			}
			for(int j=st;j<=n;j+=prime[i])
				comp.insert(j);
		}
		cout<<endl;
		f2(i,m,n)
			if(comp.count(i) == 0)
				cout<<i<<endl;
	}
	return 0;
}
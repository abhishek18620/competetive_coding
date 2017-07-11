#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

ll square(ll n)
{
    if (n==0) return 0;
 
    if (n < 0) n = -n;
 
    int x = n>>1;
 
    if (n&1)
        return ((square(x)<<2) + (x<<2) + 1);
    else
        return (square(x)<<2);
}

int main()
{
	fast;
    ll n,b,sol1,sol2,half,turns,pos1,pos2,left;
	double tu;
	int t; cin>>t; 
	while(t--)
	{
		cin>>n>>b;
		half=n/2;
		tu=double(half)/double(b);
		pos1=floor(tu);
		pos2=ceil(tu);
		//for first possibility (pos1)
		left=n-(pos1*b);
		sol1=pos1*left;
		//for 2md possibility (pos2)
		left=n-(pos2*b);
		sol2=pos2*left;
		cout<<max(sol1,sol2)<<endl;
	}
	cin>>t;
	return 0;
}
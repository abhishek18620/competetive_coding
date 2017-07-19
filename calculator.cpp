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
	fio;
	ll n,b,sol1,sol2,half,turns,pos1,pos2,left;
	double tu;
	test
	{
		cin>>n>>b;
		half=n/2;
		tu=double(half)/double(b);
		pos1=floor(tu);
		pos2=ceil(tu);
		left=n-(pos1*b);
		sol1=pos1*left;
		left=n-(pos2*b);
		sol2=pos2*left;
		cout<<max(sol1,sol2)<<endl;
	}
	return 0;
} 
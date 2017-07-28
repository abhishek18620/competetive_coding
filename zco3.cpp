// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 200009
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

ll a[M],sum[M];

void scan(int &x){
    	register int c = gc();
    	// bool neg=(c=='-')?1:0;
        x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        // x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        // bool neg=(c=='-')?1:0;
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        // x*=(neg)?-1:1;
    }

int main()
{
	//fio;
	int n; scan(n);
    ll tot=0,score=0;
    sum[0]=0;
    f(i,0,n)
        scanl(a[i]);
    
    sort(a,a+n);
    ll sum_p=0;
    f(i,1,n)
    {
        sum_p+=a[i]-a[i-1];
        sum[i]=sum[i-1]+sum_p;
    }

    score=sum[n-1];
    f(i,1,n)
        score+=(sum[n-1]-sum[i])-((a[i]-a[0])*(n-i-1));
    printf("%lld",score);
    cin>>n;
    return 0;
}
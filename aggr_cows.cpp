#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
using namespace std;

int n,c;		//n=barns , c= cows
ll dis[100001];

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
    	register int c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

// tells if n can possibly be min distance satisfying all cows
// TOPCODER TUTS ARE GREAT
bool predicate (int x)
{
	ll prev = dis[0];
	int cows=1;
	f(i,1,n)
	{
		if(dis[i] - prev >= x)
		{
			cows++;
			if(cows == c)
				return 1;
			prev = dis[i];
		}
	}
	return 0;
}

// binary search for a better max(again TOPCODER)
ll bin_search()
{
	ll l,r,mid;
    l=0;
    r=dis[n-1];
    while(l<r)
    {
    	mid=(l+r)/2;
    	if(predicate(mid)==1)
    		l=mid+1;
    	else
    		r=mid;
    }
	return l-1;
}

int main()
{
    int t; scan(t);
	while(t--)
	{
		scan(n); scan(c);
		f(i,0,n)
			scanl(dis[i]);
		sort(dis,dis+n);
		writel(bin_search());
	}
    return 0;
}
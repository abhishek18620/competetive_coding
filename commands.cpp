#include <bits/stdc++.h>
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
using namespace std;

void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]=' ';
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

int main()
{
	ll n,h; scanl(n); scanl(h);
    ll a[n];
    f(i,0,n)
        scanl(a[i]);
    int comm=1;
    int curr=0;
    bool car=0;
    while(comm)
    {
        scan(comm);
        if(comm == 1 and curr>0)
        {
            curr--;
        }
        else if(comm == 2 and curr!=n-1)
        {
            curr++;
        }
        else if(comm == 3 and a[curr] != 0 and !car)
        {
            a[curr]--;
            car=1;
        }
        else if(comm == 4 and a[curr] < h and car)
        {
            a[curr]++;
            car=0;
        }
        else if(comm==0)
            break;
    }
    f(i,0,n)
        writel(a[i]);
    cin>>n;
    return 0;
}
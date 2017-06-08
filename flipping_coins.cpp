#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
using namespace std;

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

int main()
{
	test
	{
        int g; scan(g);
        while(g--)
        {
            int i,q; ll n;
            scan(i); scanl(n); scan(q);
            ll o=n/2;                   // ones
            if(i==q)
                writel(o);
            else
                writel(n-o);
        }
	}
    cin>>t;
	return 0;
}
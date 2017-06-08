#include <bits/stdc++.h>
#define M 100009
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
int dp[M][2];
int b[M];

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
int main()
{
	fio;
	test
	{
        int n; scan(n);
        f(i,0,n)
            scan(b[i]);
        dp[0][0]=0; dp[0][1]=0;
        f(i,1,n)
        {
            int prv_lim=b[i-1];
            int lim=b[i];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(prv_lim-1));
            dp[i][1]=max(dp[i-1][0]+abs(lim-1) , dp[i-1][1]+abs(lim-prv_lim));
        }
        ll ans=max(dp[n-1][0],dp[n-1][1]);
        writel(ans);
    }
	return 0;
}
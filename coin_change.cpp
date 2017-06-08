#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define gc() getchar_unlocked()
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
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	//fio;
    int n,m;
    scan(n); scan(m);
    int a[m];
    f(i,0,m)
        scan(a[i]);
    sort(a,a+m);
    ll dp[m+1][n+1];
    f(i,0,m+1)
    {
        f(j,0,n+1)
            dp[i][j]=0;
    }

    f(i,1,m+1)
    {
        int coin=a[i-1];
        f(j,1,n+1)
        {
            //base condition
            if(j-coin==0)
                dp[i][j]=dp[i-1][j]+1;
            else if(j-coin<0)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i][j-coin]+dp[i-1][j];
            }
        }
    }
    ll ans=0;
    cout<<dp[m][n]<<endl;
	return 0;
}
/******************************************
*  Author : Author   
*  Created On : Sat Jul 29 2017
*  File : floyd_warshall(APSP).cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 232
#define INF 100000000
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

//GLOBALS
int dp[M][M],m,n,u,v,w;

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
    	bool neg=(c=='-')?1:0;
        x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=(c=='-')?1:0;
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

int main()
{
	fio;
	scan(m); scan(n);
	f(i,0,m+1)
		f(j,0,m+1)
			dp[i][j]=INF;
	
	f(i,0,m+1)
		dp[i][i]=0;
	f(i,0,n)
	{
		scan(u); scan(v); scan(w);
		--u; --v;
		dp[u][v]=dp[v][u]=w;
	}
	
	//floyd warshall
	f(k,0,m)
    {
        f(i,0,m)
        {
			 f(j,0,m)
            	if (dp[i][k] + dp[k][j] < dp[i][j])
                	dp[i][j] = dp[i][k] + dp[k][j];
        }
    }
	
	int sol=-1;
	//find max in dp
	f(i,0,m)
	{
		f(j,0,m)
			sol=max(sol,dp[i][j]);
	}
	cout<<sol<<endl;
	
	cin>>n;
	return 0;
}

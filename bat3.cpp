/******************************************
*  Author : abhishek18620   
*  Created On : Fri Aug 18 2017
*  File : bat3.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 1009
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

//GLOABALS
int n,k;
int a[M],dp[M];

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
    	bool neg=0;
		x=0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=0;
    	x = 0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }
int main()
{
	fio;
	test
	{
        scan(n); scan(k);
        f(i,0,n)
            scan(a[i]);
            
        //DP BEGINS
        //state = ending hill
        // LIS
        f(i,0,n)
        {
            dp[i]=1;
            f(j,0,i)
            {
                if(a[i]<a[j] or j==k)
                    dp[i]=max(dp[i] , dp[j]+1);
            }
        }
        int sol=*max_element(dp,dp+n);
        writel(sol);
    }
    cin>>t;
	return 0;
}

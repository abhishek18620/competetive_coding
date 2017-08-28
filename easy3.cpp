/******************************************
*  Author : abhishek18620   
*  Created On : Sun Aug 27 2017
*  File : easy3.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 20009
#define INF 1e9+9;
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
int n,k,a[M],sol;


bool comp(const int& lhs, const int& rhs)
{
  return lhs > rhs;
}

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
    //fio;
	test
	{
        scan(n); scan(k);
        f(i,0,n)
            scan(a[i]);
        if(k==1)
        {
            printf("0\n");
            continue;
        }
        sort(a,a+n,comp);
        sol=INF;
        f(i,0,n-k+1)
            sol=min(sol,a[i]-a[i+k-1]);
        printf("%d\n",sol);
    }
    cin>>t;
	return 0;
}

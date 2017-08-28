/******************************************
*  Author : abhishek18620   
*  Created On : Fri Aug 04 2017
*  File : rent.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10009
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

// CUSTOM COMPARATOR
bool comp(const pair<int , pair<int,int> >& lhs, const pair<int , pair<int,int> >& rhs)
{
  return (lhs.S.F) < (rhs.S.F);
}
//GLOBALS
int n,u,v,w,dp[M];
pair<int , pair<int,int> > order[M];

int bsearch(int x)
{
	int mid=-1,l=0,r=n-1;
	if(x > order[r].S.F)
		return -1;
	while(r>l)
	{
		mid=(r+l)/2;
		if(order[mid].S.F<x)
			l=mid+1;
		else if(order[mid].S.F>x)    //s is lesser than c[mid]
            r=mid;
		else
			return mid;
	}
	//lo is the index which has element
    //greater than or equal to s
	// if1(ind!=-1)	
	// 	return ind;
	// else
	// 	return lo;
    return l;
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
	fio;
	test
	{
		//memset(dp,0,sizeof(dp));
		scan(n);
		int te;
		f(i,0,n)
		{
			scan(order[i].S.F);
			scan(te);
			scan(order[i].F);
			order[i].S.S=order[i].S.F+te;
		}
		sort(order,order+n,comp);
		f(i,0,n)
			dp[i]=order[i].F;
		int st=0,ind=0;
		f(i,0,n)
		{
			st=order[i].S.S;
			ind=bsearch(st+1);
			if(ind!=-1)
			{
				f(j,ind,n)
				{
					dp[j]=max(dp[j],dp[i]+order[j].F);
				}
			}
		}
		int sol=*(max_element(dp,dp+n));
		printf("%d\n",sol);
	}
	cin>>t;
	return 0;
}

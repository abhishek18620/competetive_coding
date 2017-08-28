/******************************************
*  Author : abhishek18620  
*  Created On : Thu Aug 03 2017
*  File : frequent.cpp
*******************************************/
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

//GLOBALS
const int num=100000;
int n,q,a[15],fr[M],st[M];
int seg[M<<1];

void build(int size)
{
	for (int i = size - 1; i > 0; --i)
		seg[i] =max(seg[i<<1],seg[i<<1|1]);
}

int query(int l, int r,int size)
{
	//sum on interval [l,r) (VERY IMPORTANT TO NOTE THIS RANGE)
	//OPEN BRACKET at r.
	int res = 0;
  	for (l += size, r += size; l < r; l >>= 1, r >>= 1)
  	{
		//if L is odd that means it is the RIGHT child of its parent 
		//so it implies that parent does'nt include in range
		//similarly if
		//cout<<"at l = "<<seg[l]<<" at r = "<<seg[r]<<endl;
		if (l&1)		 
			res=max(res , seg[l++]);
		if (r&1)
			res=max(res,seg[--r]);
  	}
  	return res;
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
	int t=1;
	while(1)
	{
		scan(n); 
		if(n==0)
			break;
		memset(seg,0,sizeof(seg));
		memset(fr,0,sizeof(fr));
		memset(st,-1,sizeof(st));
		scan(q);
		f(i,0,n)
			scan(a[i]);
		int te;
		//COMPRESSION
		a[0]+=num;
		fr[a[0]]=1;
		st[a[0]]=0;
		f(i,1,n)
		{
			a[i]+=num;
			fr[a[i]]++;
			if(a[i]!=a[i-1])
				st[a[i]]=i;
		}
		int size=a[n-1]+1;
		f(i,0,n)
			seg[size+a[i]]=fr[a[i]];
		build(size);
		int l,r,sol_r,sol_l,sol_q,sol;
		f(i,0,q)
		{
			scan(l); scan(r);
			l--; r--;
			if(a[l]==a[r])
				sol=r-l+1;
			else
			{
				sol_l=fr[a[l]]-(l-st[a[l]]);
				sol_r=r-st[a[r]]+1;
				l=l+sol_l;
				r=r-sol_r;
				sol_q=query(a[l],a[r]+1,size);
				//cout<<fr[a[l]]<<" "<<fr[a[r]];
				sol=max(max(sol_l,sol_r),sol_q);
			}
			printf("%d\n",sol);
		}
	}
	cin>>n;
	return 0;
}
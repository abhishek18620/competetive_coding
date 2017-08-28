/******************************************
*  Author : abhishek18620   
*  Created On : Thu Aug 17 2017
*  File : histogram.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 100009
#define INF 1e15
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
int n;
ll a[M];

struct node
{
	int ele;
	void create_node(int x)
	{
		ele=x;
	}

	void merge(node &l , node &r)
	{
		//calculating mid max
		if(a[l.ele]<=a[r.ele])
			ele=l.ele;
		else
            ele=r.ele;
    }
}seg[2*M];

void build()
{
	int l,r;
	for(int i=n-1;i>0;--i)
	{
		l=i<<1;
		r=i<<1|1;
		seg[i].merge(seg[l],seg[r]);
		//seg[i].ele=(a[seg[l].ele]<=a[seg[r].ele])?seg[l].ele:seg[r].ele;
	}
}

int query(int l ,int r)
{
	//[l,r)
	int res=seg[l+n].ele;
	for(l+=n,r+=n ; l<r ; l>>=1,r>>=1)
	{
		if(l&1)
		{
            res=(a[res]<=a[seg[l].ele])?res:seg[l].ele;
            l++;
        }
        if(r&1)
        {
            r--;
            res=(a[res]<=a[seg[r].ele])?res:seg[r].ele;		// --r cause [l,r)
        }
    }
    return res;
}

ll rec(int l, int r)
{
	if(l>r)
		return (-1*INF);
	else if(l==r)
		return a[l];
	int mid=query(l,r+1);
	return(max((a[mid]*(r-l+1)) , max(rec(l,mid-1) , rec(mid+1,r))));
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
    ll sol=0;
    scan(n);
    while(n!=0)
	{
		f(i,0,n)
			scanl(a[i]);
		f(i,0,n)
			seg[n+i].create_node(i);
		build();
		sol=rec(0,n-1);
        printf("%lld\n",sol);
        //divide and conquer
		//calculate max areas on left and right on min
        scan(n);
    }
    cin>>n;
	return 0;
}

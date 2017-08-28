/******************************************
*  Author : abhishek18620   
*  Created On : Wed Aug 02 2017
*  File : orderset.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 20
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define pai pair<int,int>
#define F first
#define S second
#define pb push_back
using namespace std;

//GLOBALS
int N,ans;
pair<char,int> que[M];
int seg[2*M];

int bsearch(vector<int> &s , int x)
{
	int l=0,r=s.size()-1,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(s[mid] > x)
			r=mid-1;
		else if(s[mid] < x)
			l=mid+1;
		if(s[mid]==x)
		{
			ans=mid;
			break;
		}
	}
	//mid = element <= x
	return mid;	
}


void modify(int p, int value)
{
	// set value at position p
  	for (seg[p += N] = value; p > 1; p >>= 1) 
  		seg[p>>1] = seg[p] + seg[p^1];
}

int query(int l, int r)
{
	//sum on interval [l,r)
	int res = 0;
  	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
  	{
		//if L is odd that means it is the RIGHT child of its parent 
		//so it implies that parent does'nt include in range
		//similarly if
		if (l&1)		 
			res += seg[l++];
		if (r&1)
			res += seg[--r];
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
        bool neg=(c=='-')?1:0;
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

int main()
{
	//fio;
	int q=0;
	scan(q);
	memset(seg,0,sizeof(seg));
	vector<int> s1,s2;
	int te;
	f(i,0,q)
	{
		scanf("%c",&que[i].F);
		scan(que[i].S);
		//cin>>que[i].F>>que[i].S;
		if(que[i].F=='I')
			s1.pb(que[i].S);
	}
	//COORDINATE COMPRESSION
	sort(s1.begin(),s1.end());
	//formed a set
	s2.pb(s1[0]);
	te=s1.size();
	f(i,1,te)
	{
		if(s1[i]!=s1[i-1])	//if num is not repeating
			s2.pb(s1[i]);
	}
	N=s2.size();
	char ch;
	int x,pos;
	f(i,0,q)
	{
		ch=que[i].F;
		x=que[i].S;
		ans=-1;
		//insert
		if(ch=='I')
		{
			if(x==10)
				pos=0;
			pos=bsearch(s2,x);
			modify(pos,1);
		}
		else if(ch=='D')
		{
			pos=bsearch(s2,x);
			if(s2[pos]==x) //present	
				modify(pos,0);
		}
		else if(ch=='K')
		{
			int temp,l,r,m;
			temp=query(0, N);
            if(x>temp) printf("invalid\n");
            else
            {
                l = 0;
                r = N-1;
                while(x>0 && l<r)
                {
                    m = (l+r)/2;
                    temp=query(l, m+1);
                    if(x>temp){
                        x -= temp;
                        l=m+1;
                    }
                    else{
                        r=m;
                    }
                }
                printf("%d\n",s2[l]);
			}
		}
		else if(ch=='C')
		{
			pos=bsearch(s2,x);
			if(s2[pos]<x)
				pos++;
			ans=query(0,pos);
			printf("%d\n",ans);
		}
	}
	cin>>q;
	return 0;
}

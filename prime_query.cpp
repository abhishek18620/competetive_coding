//SOURCE : CODEFORCES (http://codeforces.com/blog/entry/18051)
//ITS JUST SIMPLY GRT....
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 1e6+2
#define sz 1e5+9
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
//don't know maybe...just hoping it solves it..
//outer seg tree(x,y) contains query(l,r) = sum(inner_seg_tree())
//----------------------------GLOBALS----------------------------------------
ll n,MAX,q;
int fac[1000009];
ll a[100007];
vector<ll> seg[200010];
//---------------------------------------------------------------------------
//----------------------------I/O UTILS--------------------------------------
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

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }
//-------------------------------------------------------------------------------
//-----------------------BUILDING TREES--------------------------------------
void build()
{  	// build the tree
	ll le,ri,s_l,s_r;
	for (int i = n - 1; i > 0; --i)
	{
		le=i<<1;
		ri=i<<1|1;
		s_l=seg[le].size();
		s_r=seg[ri].size();
		int ind_l=0,ind_r=0;
		//entering numbers in a sorted order
		while(ind_l<s_l and ind_r<s_r)
		{
			if(seg[le][ind_l] < seg[ri][ind_r])
			{
				seg[i].pb(seg[le][ind_l]);
				ind_l++;
			}
			else
			{
				seg[i].pb(seg[ri][ind_r]);
				ind_r++;
			}
		}
		//if any primes left
		f(j,ind_l,s_l)
			seg[i].pb(seg[le][j]);
		
		f(j,ind_r,s_r)
			seg[i].pb(seg[ri][j]);
	}
}

int query(int l, int r, int x, int y) 
{  	// sum on interval [l, r)
	int res = 0;
 	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
		{
			int l1=lower_bound(seg[l].begin(),seg[l].end(),x)-seg[l].begin();
			int r1=upper_bound(seg[l].begin(),seg[l].end(),y)-seg[l].begin()-1;
			res+=r1-l1+1;
			l++;
		}
		if (r&1)
		{
			r--;
			int l1=lower_bound(seg[r].begin(),seg[r].end(),x)-seg[r].begin();
			int r1=upper_bound(seg[r].begin(),seg[r].end(),y)-seg[r].begin()-1;
			res+=r1-l1+1;
		}
	}
	return res;
}


//---------------------------------------------------------------------------
void solve_for_each_lr()
{
	f(i,0,n)
	{
		int ele=a[i];
		while(ele!=1)
		{
			seg[n+i].pb(fac[ele]);
			ele/=fac[ele];
		}
	}
}

// void solve_for_each_lr(int pr)
// {
// 	ll num,res;
// 	f(i,0,n)
// 	{
// 		num=a[i];
// 		while(num%pr==0)
// 		{
// 			seg[n+i].pb(pr);
// 			num/=pr;
// 		}
// 	}
// }

// void solve_for_each_xy()
// {
//     f(i,2,MAX+1)
//     {
// 		//this will make leave's trees for xy seg tree
//         if(isprime[i])
// 		{
// 			ll curr=i;	//this is the prime
//         	solve_for_each_lr(i);
// 		}
// 	}
// }

//OPTIMISED SIEVE
//A GOOD IDEA OF PRIME FACTORISATION
//just put the first prime factor of ele at fac[ele]
//source: a senior from my college(https://www.codechef.com/viewsolution/14255020)
void seive()
{
	long long i, j;
	for(i=2; i<=M; i+=2)
		fac[i] = 2;
	for(i=3; i<=M; i+=2)
	{
		if(!fac[i])
		{
			fac[i] = i;
			for(j=2; i*j <= M; j++)
			{
				if(!fac[i*j])
					fac[i*j] = i;
			}
		}
	}
}

int main()
{
	fio;
	scanl(n);
	MAX=-1;
	f(i,0,n)
	{
		scanl(a[i]);
		if(a[i]>MAX)
			MAX=a[i];
	}
	scanl(q);
	seive();
	solve_for_each_lr();
	build();
	ll x,y,l,r;
	while(q--)
	{
		scanl(l); scanl(r); scanl(x); scanl(y);
		l--;
		cout<<query(l,r,x,y)<<endl;
	}
	int t;
	cin>>t;
	return 0;
}
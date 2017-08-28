/******************************************
*  Author : elliot   
*  Created On : Sat Aug 19 2017
*  File : chef_and_movers.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
//I FINALLY UNDERSTOOD THAT USING A SOLVER UTILITY FUN REALLY HELPS A LOT
#include <bits/stdc++.h>
#define M 100009
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
ll a[M],cp[M],n,k; 

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

ll solve(ll idx,ll req)
{
    ll ctr=0;
    ll ans=0;
    for(int i=idx;i<n;i+=k)
        cp[ctr++]=a[i];
    f(i,0,ctr-1)
    {
        if(cp[i]<req)
        {
            ans+=req-cp[i];
            cp[i+1]-=req-cp[i];
        }
        else
        {
            ans+=cp[i]-req;
            cp[i+1]+=cp[i]-req;
        }
    }
    if(cp[ctr-1]!=req)
        return -1;
    else
        return ans;
}

int main()
{
    //fio;
    ll sum=0;
    test
	{
        sum=0;
        scanl(n); scanl(k);
        f(i,0,n)
        {
            scanl(a[i]);
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            printf("-1\n");
            continue;
        }
        ll req=sum/n;
        ll te,sol=0;
        f(i,0,k)
        {
            te=solve(i,req);
            if(te==-1)
            {
                sol=-1;
                break;
            }
            else
                sol+=te;
        }
        cout<<sol<<endl;
    }
	return 0;
}

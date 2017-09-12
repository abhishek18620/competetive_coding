/******************************************
*  Author : elliot   
*  Created On : Sat Sep 09 2017
*  File : sum_cube.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
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
int m,n,k,u,v,diff;
int GR[500][500];
vector<int> subset;

unsigned long long add_modulo(unsigned long long &a,unsigned long long &b)
{
    unsigned long long ret=((a%MOD)+b)%MOD;
    return ret;
}

long long subsets()
{
    long long max_sz = 1<<n;
    int ctr;
    unsigned long long sol=0;
    //bitmasking
    f(i,0,max_sz)
    {
        f(j,0,n)
        {
            //if jth bit is set
            if(i&(1<<j))
                subset.pb(j);
        }
        ctr=0;
        int lim=subset.size();
        f(i,0,lim)
        {
            f(j,i,lim)
            {
                if(GR[subset[i]][subset[j]]==diff)
                    ctr++;
            }
        }
        unsigned long long te=pow(ctr,k);
        sol=add_modulo(sol,te);
        subset.clear();
    }
    return sol;
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
    diff=0;
	test
	{
        diff++;
        scanf("%d %d %d" ,&n,&m,&k);
        f(i,0,m)
        {
            scanf("%d %d",&u,&v);
            u--; v--;
            GR[u][v]=GR[v][u]=diff;
        }
        printf("%lld\n",subsets());
    }
    cin>>t;
	return 0;
}

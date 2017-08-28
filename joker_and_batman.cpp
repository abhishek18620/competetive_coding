/******************************************
*  Author : elliot   
*  Created On : Mon Aug 21 2017
*  File : joker_and_batman.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 100020
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
int n,q,u,v,c[M],diff=0,dp[M][19],done[M][19],level=0;

int get_level(int k)
{
    int c=0;
    while(k>0)
    {
        k>>=1;
        c++;
    }
    return --c;
}
int ones(int n)
{
    int count=0;
    while( n )
    {
    n = n&(n-1);
       count++;
    }
    return count;
}

//state (root , level to go down)
int rec(int r, int k)
{
    //base case
    if(r > n)
        return 0;
    if(k<=0)
        return (0|(1<<(c[r])));
    if(done[r][k]==diff)
        return dp[r][k];
    int mask=0|(1<<(c[r]));
    //int left=r<<1;
    //int right=r<<1|1;
    int res=0;
    dp[r][1]=0;
    mask|=rec(r<<1,k-1)|rec(r<<1|1,k-1);
    done[r][k]=diff;
    return dp[r][k]=mask;
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
        //cout<<"\n new test case : "<<endl;;
        scan(n);
        int te=n;
        level=get_level(n);
        f(i,1,n+1)
            scan(c[i]);
        diff++;
        int lev;
        f(i,1,n+1)
        {
            lev=get_level(i);
            fr(j,level-lev,0)
                dp[i][j]=rec(i,j);
        }
        scan(q);
        int sol;
        f(i,0,q)
        {
            scan(u); scan(v);
            sol=-1;
            f(i,0,level+1)
            {
                //int one = ones(dp[u][i]);
                if(ones(dp[u][i])>=v)
                {
                    sol=i;
                    break;
                }
            }
            printf("%d\n",sol);
        }
    }
    cin>>t;
	return 0;
}

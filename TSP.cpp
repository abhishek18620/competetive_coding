/******************************************
*  Author : abhishek   
*  Created On : Sat Jul 29 2017
*  File : TSP.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define INF 1000000000
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
int dp[(1<<12)+5][102],dist[102][102],u,v,w,b,m,n,p,orders[13][2];
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
    	bool neg=(c=='-')?1:0;
        x = 0;
    	for(;c<48 || c>57;c=gc());
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
	fio;
	test
	{
		scan(m); scan(n); scan(b);
		--b;
		//floyd warshall
		f(i,0,m+1)
			f(j,0,m+1)
				dist[i][j]=INF;
		
		f(i,0,m+1)
			dist[i][i]=0;
		f(i,0,n)
		{
			scan(u); scan(v); scan(w);
			--u; --v;
			dist[u][v]=dist[v][u]=w;
		}

		f(k,0,m)
		{
			f(i,0,m)
			{
				f(j,0,m)
					if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
		
		//treating every order as different cause 
		//can only transport single parcel at once  
		scan(p);
		int ord=0;
		f(i,0,p)
		{
			scan(u); scan(v); scan(w); //w=number of orders
			--u; --v;
			f(j,ord,ord+w)
			{
				orders[j][0]=u;
				orders[j][1]=v;
			}
			ord+=w;
		}
		bool set;
		int mask;
		//DP begins
		f(i,0,(1<<ord)+1)
			f(j,0,m)
				dp[i][j]=INF;
		f(i,0,m)
			dp[0][i]=dist[b][i];

		int src,des,dis;
		f(i,0,1<<ord)
		{
			f(j,0,ord)
			{
				set=i&(1<<(j));
				if(!set)	//jth order not delivered yet
				{
					f(k,0,m) //k= city i'm standing at
					{
						src=orders[j][0];
						des=orders[j][1];
						if(dp[i][k]!=INF)	//if ==INF means never reached this before
						{
							dis=dp[i][k]+dist[k][src]+dist[src][des];
							mask=i|(1<<j);
							//bitset<6> bs(mask);
							if(dp[mask][des]>dis)
							{
								dp[mask][des]=dis;
								//cout<<"moving from "<<k+1<<" ----> "<<src+1<<" ----> "<<des+1<<" cost = "<<dis<<" (mask) = "<<bs<<endl;
							}
						}
					}
				}
			}
		}
		int sol=INF;
		f(i,0,m)
			sol=min(sol,dp[(1<<ord)-1][i]+dist[b][i]);
		cout<<sol<<endl;
	}
	cin>>t;
	return 0;
}

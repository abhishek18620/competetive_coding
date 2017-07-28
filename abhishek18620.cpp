#include <bits/stdc++.h>
#define M 10000
#define INF 9999999
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define rep(i, j, k) for (int i = j; i < k; i++)
#define rep_r(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

int pf[12][12],pt[12][12],m,n;
pair<int , int> dp[12][12];

void bfs(int x,int y)
{
	rep(i,0,n+1)
		rep(j,0,m+1)
			dp[i][j].F=dp[i][j].S=INF;
	queue< pair<int,int> > q;
	q.push(mp(x,y));
	
	dp[x][y].F=pf[x][y];
	dp[x][y].S=pt[x][y];
	
	while(!q.empty())
	{
		int currx=q.front().F;
		int curry=q.front().S;
		q.pop();
		rep(i,currx-1,currx+2)
		{
			rep(j,curry-1,curry+2)
			{
				if(i<0 or j<0 or i>n-1 or j>m-1)
					continue;
				else
				{
					int dis=abs(currx-i)+abs(curry-j);
					//move allowed
					if(dis==1)
					{
						if(dp[i][j].F > dp[currx][curry].F+pf[i][j])
						{
							dp[i][j].F=dp[currx][curry].F+pf[i][j];
							dp[i][j].S=dp[currx][curry].S+pt[i][j];
							q.push(mp(i,j));
						}
						else if(dp[i][j].F == dp[currx][curry].F+pf[i][j])
						{
							if(dp[i][j].S > dp[currx][curry].S+pt[i][j])
							{
								dp[i][j].F=dp[currx][curry].F+pf[i][j];
								dp[i][j].S=dp[currx][curry].S+pt[i][j];
								q.push(mp(i,j));
							}
						}
					}
				}
			}
		}
	}
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
	fast;
	test
	{
		scan(n); scan(m);
		rep(i,0,n)
			rep(j,0,m)
				scan(pf[i][j]);
		
		rep(i,0,n)
			rep(j,0,m)
				scan(pt[i][j]);
		
		bfs(0,0);
		cout<<dp[n-1][m-1].F<<" "<<dp[n-1][m-1].S<<endl;
	}
	cin>>t;
	return 0;
}
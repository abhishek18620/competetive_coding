#include <bits/stdc++.h>
#define M 10000
#define INF 9999999
typedef long long ll;
#define rep(i, j, k) for (int i = j; i < k; i++)
#define rep_r(i, j, k) for (int i = j; i >= k; i--)
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


int main()
{
	int t; cin>>t;
	while(t--)
	{
		cin>>n>>m;
		rep(i,0,n)
			rep(j,0,m)
				cin>>pf[i][j];
		
		rep(i,0,n)
			rep(j,0,m)
				cin>>pt[i][j];
		
		bfs(0,0);
		cout<<dp[n-1][m-1].F<<" "<<dp[n-1][m-1].S<<endl;
	}
	cin>>t;
	return 0;
}
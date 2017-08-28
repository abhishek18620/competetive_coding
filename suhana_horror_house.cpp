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
#define M 10000
#define INF 9999999
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

int pf[12][12],pt[12][12],m,n;
pair<int , int> dp[12][12];

void bfs(int x,int y)
{
	f(i,0,n+1)
		f(j,0,m+1)
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
		f(i,currx-1,currx+2)
		{
			f(j,curry-1,curry+2)
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
		f(i,0,n)
			f(j,0,m)
				cin>>pf[i][j];
		
		f(i,0,n)
			f(j,0,m)
				cin>>pt[i][j];
		
		bfs(0,0);
		cout<<dp[n-1][m-1].F<<" "<<dp[n-1][m-1].S<<endl;
	}
	cin>>t;
	return 0;
}
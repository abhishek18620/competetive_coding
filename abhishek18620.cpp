#include <bits/stdc++.h>
#include<stdint.h>
#define M 10000
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

//GLOBALS
const ll MOD = 1e9+7;
ll dp[1<<10][102];
bool a[12][102];

int main()
{
	//fnf;
    int n,t,te,mask,num;
	scanf("%d",&t);
    while(t--)
	{
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));    
		memset(a,0,sizeof(a));
		//take input as string
		fuck(i,1,n+2)
		{
			string s,out;
			stringstream ss;
			getline(cin,s);
			ss<<s;
			while(ss>>out)
			{
				stringstream convert(out);
				convert>>te;
				a[i-1][te]=1;
			}
		}

		//DP begins
		//dp(i,j)=j tshirts been alredy alloted
		//bitmask of i (indexes having 1 are already alloted a tshirt as order doesn't matter)
		dp[0][0]=1;
		fuck(i,0,1<<n)
		{
			fuck(j,1,101)
			{
				dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
			}
			//now need to check which bits are set in bitset of i
			//which are still left to be alloted
			fuck(j,1,n+1)
			{
				//if(j th bit is set in i)
				bool set=i&(1<<(j-1));
				if(!set)
				{
					mask=i|(1<<(j-1));
					fuck(k,1,101)
					{
						if(a[j][k])	//checking if tshirt k is available for person j
							dp[mask][k]=(dp[mask][k]+dp[i][k-1])%MOD;
					}
				}
			}
		}
		printf("%lld\n",dp[(1<<n)-1][100]);
	}
cin>>t;
	return 0;
}
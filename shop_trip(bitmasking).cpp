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
#define test int t; cin>>t; while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

//GLOBALS   
int n,k,sol;
string str;
ll ingr[40];
double dp[(1<<12)+10][40];
int coor[40][2];

//i----->
double dist_origin(int i)
{
	return sqrt(coor[i][0]*coor[i][0] + coor[i][1]*coor[i][1]);
}

double dist(int i, int j)
{
	int x=coor[i][0]-coor[j][0];
	int y=coor[i][1]-coor[j][1];
	double res = sqrt(x*x + y*y);
	return res;
}

ll str_to_num()
{
	ll ret=0;
	f(i,0,k)
	{
		if(str[i]=='1')
			ret+=1<<(k-1-i);
	}
	return ret;
}

int main()
{
	fio;
    cout << fixed << setprecision(11);
  	cerr << fixed << setprecision(6);
	test
	{
		//state(i,j)-----(i=bitmask j=if i can go there)
        //shops and ingredients
        cin>>n>>k;
		f(i,0,(1<<k))
			f(j,0,40)
				dp[i][j]=double(-1);
		//INPUT
		f(i,0,n)
			cin>>coor[i][0]>>coor[i][1];
		f(i,0,n)
		{
			cin>>str;
			ingr[i]=str_to_num();
		}
		ll ret;
		//sets which are directly reachable from origin
		f(i,0,n)
			dp[ingr[i]][i]=dist_origin(i);
		
		f(i,0,1<<k)	
        {
            f(j,0,n)
            {
				// going from shop k
				if(dp[i][j] == -1)
					continue;
				f(k,0,n)
				{
					//going from set(i) to set(ret) after buying from shop k
					ret=i|ingr[k];
					//got nothing new from this shop
					if(ret==i)
						continue;
					bitset<12> te(ret);
					//cout<<"\nnew ingredient set :	"<<te<<endl;
					if(dp[ret][k]==-1)
						dp[ret][k]=dp[i][j]+dist(k,j);
					else
						dp[ret][k]=min(dp[ret][k], dp[i][j]+dist(k,j));
					//cout<<"going from shop 	"<<j+1<<" to "<<k+1<<" with total distance travelled yet = "<<dp[ret][k]<<endl;
				}
            }
        }

		//sol will the minimum of last row of memo table
		//from return journey just move back to origin directly
		double ans = -1;
		//last row
		// f(i,0,n)
		// 	cout<<"\n	"<<dp[(1<<k)-1][i]<<endl;
		f(i,0,n)
		{
			if(dp[(1<<k)-1][i] == -1)
				continue;
			else if(ans == -1)
				ans=dp[(1<<k)-1][i]+dist_origin(i);
			else
				ans=min(ans,dp[(1<<k)-1][i]+dist_origin(i)); 
		}
		if(ans==-1)
			cout<<"-1"<<endl;
		else
		{
			//cout<<fixed;
			cout<<ans<<endl;
		}
	}
	cin>>t;
	return 0;
}
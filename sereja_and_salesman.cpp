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
using namespace std;

//GREAT EDITORIAL..MUST GO THROUGH IT AND A GOOD DP(BITMASK) QUESTION TOO...
//DP STATE dp(mask , first_node , number_of_normal_nodes_already_fitted)
// mask is obvious
//IMPORTANT OBSERVATION WAS JUST THAT WE COULDN'T REALLY DO ANYTHING WITH AN ALMOST COMPLETE GRAPH
// SO SHOULD BE ABOUT THOSE 7 NON CONNECTED EDGES AND OBVIOUSLY ITS A BITMASK QUESTION SO MJUST BE A SMALL NUMBER ;)
//SMART ISN'T IT
//I DON'T KNOW BUT IT SEEMS TO BE ONE OF THE MOST TRICKIEST DP STATE OR MAYVE NOT USED TO BITMASKS THAT MUCH..
//GLOBALS
int n,m,a[7][2];
set<int> ver;
int dp[(1<<14)+5][17][17];
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
        scan(n); scan(m);
        f(i,0,m)
        {
            scan(a[i][0]); scan(a[i][1]);
            ver.insert(a[i][0]);
            ver.insert(a[i][1]);
        }
		
		int k = ver.size();
		//DP begins
		//DP STATE dp(mask , first_node , number_of_normal_nodes_already_fitted)
		// mask is obvious
		//	N&(1<<i)
		f(i,0,(1<<k))
		{
			f(j,0,k)
			{
				f(i,0,k)
				{
					
				}
			}
		}		
	}
    cin>>t;
	return 0;
}

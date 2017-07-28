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

int n,a[22][22];
ll dp[(1<<20)+10][22];

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
        //memset(dp,0,sizeof(dp));
        scan(n);
        f(i,0,n)
            f(j,0,n)
                scan(a[i][j]);
        
        f(i,0,(1<<n)+1)
            f(j,0,n+2)
                dp[i][j]=0;
        //DP BEGINS
        ll mask;
        bool set; 
        dp[0][0]=1;
        f(i,0,1<<n)
        {
            f(j,1,n+1)
            {
                //check if jth bit 1
                set=i&(1<<(j-1));
                if(!set)
                {
                    //check which topics can be assigned to this student
                    f(k,1,n+1)
                    {
                        if(a[j-1][k-1]==1)
                        {
                            mask=i|(1<<(j-1));
                            //cout<<"\nmoving from "<<i<<" to "<<mask<<" with "<<dp[i][k-1]<<endl;
                            dp[mask][k]+=dp[i][k-1];
                        }
                    }
                }
            }
        }
        //writel(dp[(1<<n)-1][n]);
        cout<<dp[(1<<n)-1][n]<<endl;
        }
    cin>>t;
	return 0;
}
// Author : elliot18620   
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORR(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795

const int MOD = 1000000007;

int scanstr(char *str)
{
    register char c = getchar();
    register int len = 0;
    if(!(~c)) return -1;
    while(c < 33 && ~c) c = getchar();
    while(c != 10 && c != 32 && ~c){
        str[len] = c;
        c = getchar();
        len++;
    }
    str[len] = '\0';
    return 1;
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
void scan(int &x)
{
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
}
//x^y
int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        y = y>>1; x = x*x;
    }
    return res;
}
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
int arr[109],n,budget;
int dp[109][1003];

bool solve(int sum)
{
    bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++)
      subset[i][0] = 1;
  
    for (int i = 1; i <= sum; i++)
      subset[0][i] = 0;
  
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
            if(j<arr[i-1])
            {
                subset[i][j] = subset[i-1][j];
                dp[i][j]=dp[i-1][j];
            }
            if (j >= arr[i-1])
            {
                    subset[i][j] = subset[i-1][j] || 
                                        subset[i - 1][j-arr[i-1]];
                    if(subset[i - 1][j-arr[i-1]])   //if true
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i-1]]+1);
                    }
                    if(subset[i-1][j])
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    }
            }
       }
   }
    return subset[n][sum];
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    scan(n);
    FOR(i,0,n)
        scan(arr[i]);
    scan(budget);
    if(budget==0)
    {
        printf("0\n");
        return 0;
    }
    memset(dp,0,sizeof(dp));
    if(solve(budget))
        printf("%d\n",dp[n][budget]);
    else
        printf("-1\n");
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}


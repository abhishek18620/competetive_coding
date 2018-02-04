/******************************************
*  Author : abhishek18620
*  Created On : 2018-02-04
*  File : PARTIT
*******************************************/
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
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
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define trace2(x, y)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it,s) for(auto it: s)
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define foreachr(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

#ifdef LOCAL_DEFINE
    #include<assert.h>
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const ll LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

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

// state = number , partitions , 1st_digit
ll dp[225][225][11];

ll pre(int m,int n, int k)
{
    memset(dp,0,sizeof(dp));
    //base case cnt=1
    f(num,1,m+1)
    {
        dp[num][1][num]=1;
    }

    f(num,1,m+1)
    {
        f(cnt,2,n+1)
        {
            if(cnt>num) continue;
            f(st,1,num)
            {
                if(cnt==2)
                {
                    if(st<=num-st)
                        dp[num][cnt][st]=1;
                    else
                        dp[num][cnt][st]=0;
                }
                else
                {
                    // till what value of i needs to be fixed
                    for(int i=st;i*(cnt-1)+st<=num-st;i++)
                        dp[num][cnt][st]+=dp[num-st][cnt-1][i];
                }
                trace4(num,cnt,st,dp[num][cnt][st]);
            }
        }
    }
    return dp[m][n][k];
}

/*
    log 1 : 3 hours of debugging and got nowhere and listening Him and I
            this G-Eazy is really a bad mouthed bloke
    log 2 : Fuckkkkk...... What a heck of a match that was
            2-2 still I'd say Spurs hammered this one ;)
    log 3 : Darn!!! Eminem's back. Apparently with Ed sheeran this time
            That " Fuck "'s just given me so much content.
    log 4  : Era Istrefi snow and bon bon.. Uffffffff!!!!!
*/

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        //freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    //pre();
	ll n,m,k,st,v;
    while(t--)
    {
        m=14,n=10,k=1;
        trace4(m,n,k,pre(m,n,k));
       /* scanl3(m,n,k);*/
        //cout<<"INPUT : ";
		//trace3(m,n,k);
        //st = 1;
		//do
		//{
            //trace4(m,n,st,v);
			//while(v=dp[m][n][st]<k)
			//{
				//st++;
				//k -= v;
				//trace4(m,n,st,v);
            //}
			//printf("%lld", st);
			//if(n > 1) printf(" ");
			//m -= st;
		//}
		//while(--n);
		/*printf("\n");*/
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        //cin>>t;
    #endif
    return 0;
}


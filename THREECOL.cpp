/******************************************
*  Author : abhishek18620
*  Created On : 2018-04-15
*  File : THREECOL.cpp
*******************************************/
#pragma comment (linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 10009
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
#define trace4(a, b, c, d)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
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

struct node
{
    node* l;
    node* r;
    int ind;

    void init(int x)
    {
        l=r=NULL;
        ind=x;
    }
};

int n,len;
pii dp[M][3];
char s[M];
int counter;

inline void CLC()
{
    f(i,0,len+1)
        f(j,0,3) dp[i][j]=mp(-1,-1);
}

int solveMax(node* root, int col)
{
     /*
       0:RED
       1:GREEN
       2:BLUE
     */
    if(root==NULL)
        return 0;
    if(dp[root->ind][col].F!=-1)
        return dp[root->ind][col].F;

    int sol=(col==1)?1:0;
    if(col==0)  //col=Red
    {
        sol+=max(solveMax(root->l , 1) + solveMax(root->r,2) , solveMax(root->l, 2) + solveMax(root->r,1));
    }
    else if(col==1) //col=Green
    {
        sol+=max(solveMax(root->l , 0) + solveMax(root->r,2) , solveMax(root->l, 2) + solveMax(root->r,0));
    }
    else //col=2=Blue
    {
        sol+=max(solveMax(root->l , 0) + solveMax(root->r,1) , solveMax(root->l, 1) + solveMax(root->r,0));
    }
    return dp[root->ind][col].F=sol;
}


int solveMin(node* root, int col)
{
     /*
       0:RED
       1:GREEN
       2:BLUE
     */
    if(root==NULL)
        return 0;
    if(dp[root->ind][col].S!=-1)
        return dp[root->ind][col].S;

    int sol=(col==1)?1:0;
    if(col==0)  //col=Red
    {
        sol+=min(solveMin(root->l , 1) + solveMin(root->r,2) , solveMin(root->l, 2) + solveMin(root->r,1));
    }
    else if(col==1) //col=Green
    {
        sol+=min(solveMin(root->l , 0) + solveMin(root->r,2) , solveMin(root->l, 2) + solveMin(root->r,0));
    }
    else //col=2=Blue
    {
        sol+=min(solveMin(root->l , 0) + solveMin(root->r,1) , solveMin(root->l, 1) + solveMin(root->r,0));
    }
    return dp[root->ind][col].S=sol;
}

node* parseInp()
{
    counter++;
    node *root=new node;
    root->init(counter-1);
    if(s[counter-1]=='0')
        return root;
    else if(s[counter-1]=='1')
        root->l=parseInp();
    else
    {
        root->l=parseInp();
        root->r=parseInp();
    }
    return root;
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    while(t--)
    {
        scanstr(s);
        len=strlen(s);
        n=1;
        f(i,0,len)
            n+=s[i]-'0';
        //trace3(t,n,len);
        counter=0;
        node* root = parseInp();
        CLC();
        pii sol=mp(0,INF);
        f(i,0,3)
        {
            sol.F=max(sol.F, solveMax(root,i));
            sol.S=min(sol.S, solveMin(root,i));
        }
        printf("%d %d\n",sol.F,sol.S);
        //trace2(len,lst);
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>t;
    #endif
    return 0;
}


/******************************************
*  Author : wshek
*  Created On : Fri Dec 29 2017
*  File : GOODBYE2017_B.cpp
*******************************************/
// It's my template. Don't you dare to select and copy it ;)
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
#define trace2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define viter(it,s) for (auto it: s)
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
//-------------------------------------------------------END OF TEMPLATE---------------------------------------------------------------------------
int n,m,xst,yst,xdes,ydes;
char maze[101][101];
vector<string > v;
vector<string> perm({"LRUD", "LRDU", "LURD", "LUDR", "LDUR", "LDRU", "RLUD", "RLDU", "RULD", "RUDL", "RDUL", "RDLU", "URLD", "URDL", "ULRD", "ULDR", "UDLR", "UDRL", "DRUL", "DRLU", "DURL", "DULR", "DLUR", "DLRU"});
string route;
bool check(int x,int y)
{
    if(x>=0 and y>=0 and x<n and y<m)
    {
        if(maze[x][y]!='#')        
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
bool solve()
{
    int sol=0;
    viter(p,perm)
    {
        bool ans=1;
        int xcurr=xst,ycurr=yst;
        viter(ch,route)
        {
            char dir=p[ch-48];
            if(dir=='L')
            {
                if(check(xcurr,ycurr-1))
                {
                    ycurr--;
                    if(xcurr==xdes and ycurr==ydes)
                        break;
                }
                else
                {
                    ans=0;
                    break;
                }
            }
            else if(dir=='R')
            {
                if(check(xcurr,ycurr+1))
                {
                    ycurr++;
                    if(xcurr==xdes and ycurr==ydes)
                        break;
                }
                else
                {
                    ans=0;
                    break;
                }
            }
            else if(dir=='U')
            {
                if(check(xcurr-1,ycurr))
                { 
                    xcurr--;
                    if(xcurr==xdes and ycurr==ydes)
                        break;
                }    
                else
                {
                    ans=0;
                    break;
                }
            }
            else if(dir=='D')
            {
                if(check(xcurr+1,ycurr))
                {    
                    xcurr++;
                    if(xcurr==xdes and ycurr==ydes)
                        break;
                }
                else
                {
                    ans=0;
                    break;
                }
            }
        }
        if(ans and xcurr==xdes and ycurr==ydes)
        {
            cout<<"perm is : "<<p<<endl;
            sol++;
        }
    }
    print(sol);
}

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    scan2(n,m);
    v.resize(n);
    f(i,0,n)
    {
        cin>>v[i];
        string str=v[i];
        f(j,0,m)
        {
            maze[i][j]=v[i][j];
            if(v[i][j]=='S')
            {
                xst=i;
                yst=j;
            }
            if(v[i][j]=='E')
            {
                xdes=i;
                ydes=j;
            }
        }
    }
    cin>>route;
    solve();
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

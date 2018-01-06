#include <bits/stdc++.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)    cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)  cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)  cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0); cin.tie(0);} stringstream ss;} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> inline string tostring(T x) {_.ss.clear(); _.ss.str(""); _.ss << x; return _.ss.str();}
template<class T> inline T convert(const string& s) {char *p; if(is_integral<T>()) return strtoll(s.c_str(), &p, 10); else return strtod(s.c_str(), &p);}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << setw(w) << *a++; cout << ((a != b && (!p || ++c % p)) ? s : "\n");} cout.flush();}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 100010;


VI g[N];
int n;

int father[N];
LL single[N][2];
LL nosingle[N][2];

void dfs(int u, int par) {
    father[u] = par;

    VI son;
    for(int v : g[u]) {
        if(v != par) {
            dfs(v, u);
            son.pb(v);
        }
    }

    single[u][0] = single[u][1] = 1;
    for(int v : son) {
        single[u][0] = single[u][0] * nosingle[v][1] % mod;
        single[u][1] = single[u][1] * nosingle[v][0] % mod;
    }

    nosingle[u][0] = nosingle[u][1] = 1;
    for(int v : son) {
        nosingle[u][0] = nosingle[u][0] * (single[v][0] + nosingle[v][0] + nosingle[v][1]) % mod;
        nosingle[u][1] = nosingle[u][1] * (single[v][1] + nosingle[v][1] + nosingle[v][0]) % mod;
    }

    nosingle[u][0] -= single[u][0];
    nosingle[u][1] -= single[u][1];
    if(nosingle[u][0] < 0) nosingle[u][0] += mod;
    if(nosingle[u][1] < 0) nosingle[u][1] += mod;
}

int main() {
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    memset(father,0,sizeof(father));
    dfs(0, -1);
    for(int i = 0; i < n; i++) assert(father[i] != inf);

    LL res = (nosingle[0][0] + nosingle[0][1]) % mod;
    cout << res << endl;
    return 0;
}
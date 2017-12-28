#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i,n) for (i = 0; i < n; ++i)
#define FORK(i,k,n) for (i = k; i <= n; ++i)
#define FORR(i,k,n) for (i = k; i >= n; --i)

#define re(a,b)   memset(a,b,sizeof(a))
#define sz(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define input(in)    freopen(in,"r",stdin)
#define output(out)  freopen(out,"w",stdout)
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define LEN(a)       (int)(a.length())

#define FIN(x)       freopen(x,"r",stdin)
#define FOUT(x)      freopen(x,"w",stdout)
#define FCLOSE       {fclose(stdin); fclose(stdout);}

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001
#define MOD          1000000007
int main()
{
    int n,i,j;
    cin >> n;
    char a[n];
    FOR(i,n)
    cin >>a[i];
    int k=0;
    vi lol;
    bool f=false;
    for(i=n-1;i>-1;i--)
    {

       if(a[i]=='s')
       k++;
       if(a[i]=='s' && a[i-1]=='f' && i!=0)
       {
           if(f==true)
               k++;
           f=true;
           lol.pb(k);
           k=0;
       }
    }
    ll ans=1;
    FOR(i,sz(lol))
    {
        ans=((ans%MOD)*(lol[i]%MOD))%MOD;
    }
    cout << ans;
   return 0;
}
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

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);
   #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("INP.txt","rt",stdin);
   freopen("output.txt","w",stdout);
    #endif
   int t;
   cin >> t;
   while(t--)
   {
       float n,s,i,j;
       cin >> n >> s;
       float x=3*s;
       float y=4;
       float l=4+x;
       float r=4-x;
       float lol=x/n;
       for(int i=1;i<n/2;i++)
       {
        printf("%.2f,", 4-lol*i);
        // cout << 4-lol*i << " ";
       }
       i=0;
       FORK(j,n/2,n)
       {
            printf("%.2f,", 4+lol*i);
           //cout << 4+lol*i << " ";
           i++;
       }
       cout << "\n";
   }
   return 0;
}
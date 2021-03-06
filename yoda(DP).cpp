///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 1000009
#define INF 1e17
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;

//GLOBALS
ll fac[22];
int n,frq[30];
char str[SZ];
int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("input.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    fac[0]=fac[1]=1;
    //this is the only dp which is used ;)
    f(i,2,22)
        fac[i]=i*fac[i-1];
        
    while(gets(str))
    {
        n=strlen(str);
        fill(frq,frq+27,0);
        int tot=0;
        f(i,0,n)
        {
            if(str[i]>='a' and str[i]<='z')
            {
                frq[str[i]-'a']++;
                tot++;
            }
            else if(str[i]>='A' and str[i]<='Z')
            {
                frq[str[i]-'A']++;
                tot++;
            }
        }
        ll ans=fac[tot>>1];
        int diff=0;
//        printf("\nstring is : %s and length is : %d ",str,n);
        f(i,0,26)
        {
            if(frq[i]&1)    //odd frequency
            {
                diff++;
                if(diff>1)
                {
                    ans=0;
                    break;
                }
            }
            ans/=fac[frq[i]>>1];
        }
        printl(ans);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}
/******************************************
*  Author : wshek
*  Created On : Thu Oct 05 2017
*  File : 438A.cpp
*******************************************/
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printff("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

char pass[2],str[109][2];

int main()
{
	fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    scanf("%s",pass);
    int n;
    scan(n);
    f(i,0,n)
        scanf("%s",&str[i]);
    char fir=pass[0],sec=pass[1];
    bool ans=0;
    f(i,0,n)
    {
        if((str[i][0]==fir and str[i][1]==sec) or str[i][0]==sec and str[i][1]==fir)
        {
            ans=1;
            break;
        }
        else if(str[i][1]==fir)
        {
            f(j,0,n)
            {
                if(j!=i and str[j][0]==sec)
                {
                    ans=1;
                    break;
                }
            }
        }
        if(ans)
            break;
    }
    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

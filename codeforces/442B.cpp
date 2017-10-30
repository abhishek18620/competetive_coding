/******************************************
*  Author : wshek
*  Created On : Mon Oct 23 2017
*  File : 442B.cpp
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

int main()
{
	//fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    string str;
    cin>>str;
    vector< pair<char,int> > frq;
    int len=str.length();
    int ctr=1;
    f(i,1,len)
    {
        if(str[i]!=str[i-1])
        {
            frq.eb(mp(str[i-1],ctr));
            ctr=1;
        }
        else
            ctr++;
    }
    frq.eb(mp(str[len-1],ctr));
    int lim=frq.size();
    int aba=0,ba=0,ab=0,a=0,b=0;
    fr(i,lim-1,0)
    {
        char ch=frq[i].F;
        int cnt=frq[i].S;
        if(ch=='a')
        {
            aba=max(aba+cnt,ba+cnt);
            ab=max(ab+cnt,b+cnt);
            a+=cnt;
        }
        else
        {
            ba=max(ba+cnt,a+cnt);
            b+=cnt;
        }
    }

    int ans=max(aba,max(ba,max(ab,max(a,b))));
    printf("%d\n",ans);
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

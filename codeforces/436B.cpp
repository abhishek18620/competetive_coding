/******************************************
*  Author : wshek   
*  Created On : Mon Sep 25 2017
*  File : 436B.cpp
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
#define write(t) printf("%d",t)
#define writel(t) printff("%lld",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

bool check(int l , int r)
{
    int a[27];
    f(i,l,r+1)
    {
        if(s[i]>=97 and s[i]<=122)
        {
            if(a[s[i]]>0)   //not distinct

            a[s[i]-97]++;
        }
    }
}

int main()
{
	fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    string s;
    cin>>s;
    int lim=s.length();
    vector<int> v;
    f(i,0,lim)
    {
        if((int(s[i]) >= int('A')) and (int(s[i])<= int('Z')))
            v.eb(i);
    }
    bool caps=0,dist=0;
    int a[27]={};
    f(i,0,lim)
    {
        a[s[i]]++;
        if(a[s[i]]>0)
        {
            
        }
    }
    f(i,0,v.size())
    {
        int l=v[i];
        int r=v[i+1];
        check();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>m;
    #endif
    return 0;
}

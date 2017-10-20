/******************************************
*  Author : wshek
*  Created On : Sun Oct 15 2017
*  File : 440B.cpp
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

int maxsubs(int s,int k)
{
    if(s<=k)
        return s-1; 
}

int main()
{
	fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    int n,k,te,ans;
    vector<int> a;
    scan(n); scan(k);
    f(i,0,n)
    {
        scan(te);
        a.eb(te);
    }

    if(n==1)
    {
        print(a[0]);
        return 0;
    }
    if(k==1)
    {
        vector<int>:: iterator sm=min_element(a.begin(),a.end());
        print(*sm);
        return 0;
    }
    if(n==k)
    {
        vector<int>:: iterator sm=max_element(a.begin(),a.end());
        print(*sm);
        return 0;
    }

    vector<int>:: iterator sm=max_element(a.begin(),a.end());
    int ind=sm-a.begin();
    int left= ind==0?0:ind-1;
    int right= n-ind-1;
    int subsreq=k-1;
    if(subsreq>0)
    {
        if(left!=0 and right!=0)
        {
            ans=a[ind];
        }
        else if(left==0 and right!=0)
        {
            ans=a[ind];
        }
        else if(left!=0 and right==0)
        {
            ans=a[ind];
        }
    }
    else
    {
        a[ind]=-1;
        sm=max_element(a.begin(),a.end());
        ans=*sm;
    }
    
    print(ans);

    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

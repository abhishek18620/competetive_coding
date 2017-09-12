/******************************************
*  Author : wshek   
*  Created On : Fri Sep 01 2017
*  File : 431B.cpp
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

pair<int,int> arr[M];

int main()
{
    fio;
    scan(n);
    f(i,1,n+1)
    {
        scan(arr[i].S);
        arr[i].F=i;
    }
    int slope,new_slope;
    f(i,1,n)
    {
        f(j,i+1,n+1)
            mem[i][j]=float(arr[i].S-arr[j].S)/float(arr[i].F-arr[j].F);
    }
	return 0;
}

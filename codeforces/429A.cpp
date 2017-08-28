/******************************************
*  Author : wshek   
*  Created On : Fri Aug 18 2017
*  File : 429A.cpp
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

//GLOBALS
int main()
{
    int n,k;
    string str;
    map<char,int> mp;    
	//fio;
    scan(n); scan(k);
    getline(cin,str);
    getline(cin,str);
    int lim=str.length();
    f(i,0,lim)
        mp[str[i]]++;
    bool possible =1;
    for (map<char,int> :: iterator it=mp.begin(); it!=mp.end(); ++it)
    {
        if(it->S>k)
        {
            possible=0;
            break;
        }
    }
    if(possible)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

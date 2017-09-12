/******************************************
*  Author : wshek   
*  Created On : Fri Sep 01 2017
*  File : 431C.cpp
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

int mem[500];
vector<int> ans;
void rec(int num)
{
    int save;
    f(i,1,447)
    {
        if(mem[i]<=num)
            save=i;
        else
            break;
    }
    int sol=save+1;
    ans.pb(sol);
    int left=num-mem[save];
    if(left>0)
        rec(left);
}


int main()
{
    //fio;
    int sol=0;
    f(i,1,448)
    {
        sol=i*i+i;
        sol=sol/2;
        //printf("for %d is %d\n",i,sol);
        mem[i]=sol;
    }
    int n;
    scan(n);
    if(n==0)
        printf("ab");
    else
    {
        rec(n);
        int s=ans.size();
        int k;
        char ch='a';
        f(i,0,s)
        {
            k=ans[i];
            f(j,0,k)
                printf("%c",ch);
            ch++;
        }
    }
    int t;
    cin>>t;
    return 0;
}


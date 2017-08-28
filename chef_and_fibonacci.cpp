k/******************************************
*  Author : elliot18620   
*  Created On : Tue Aug 15 2017
*  File : chef_and_fibonacci.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
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
using namespace std;

//GLOBALS
//according to my calculations a[i]<=113
const int mod=1e9+7;
int diff=0;
int n,a[200]; //memo[100][100][100]; ( for debugging)
pair<int,int> dp[200][200][200];


//solve for last 3
//Debugging utility
// int fun(int i, int j, int k)
// {
//     // if(i<0 or j<0 or k<0)
//     //     cout<<"invalid"<<endl;
// 	if(i==0)
// 	{
// 		if(k==0)
// 			return 1;
//         else if(j==0)
//             return memo[i][j][k];
// 		memo[i][j][k]=fun(j-1,k-1,1)+1;
// 	}
// 	else if(memo[i][j][k]!=-1)
// 		return memo[i][j][k];
// 	else
// 	{
//         memo[i][j][k]=fun(i-1,j-1,k+1)+1;
//         if(k>0)
//             memo[i][j][k]+=fun(j-1,k-1,1);
// 		return memo[i][j][k];
// 	}
// 	return memo[i][j][k];
// }


//state (current_pos, x,y)
//top down
ll rec(int idx , int x, int y)
{
    //base case
    ll sol=0;
    if(x==0 and y==0)
        return 1;
    
    if(dp[idx][x][y].S==diff)
        return dp[idx][x][y].F;
    
    f(i,0,min(x,y)+1)
    {
        sol+=rec(idx+1,y-i,a[idx+1]+i);
    }
    dp[idx][x][y].S=diff;
    dp[idx][x][y].F=sol%mod;
    return dp[idx][x][y].F;
}



void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(int &x){
    	register int c = gc();
    	bool neg=0;
		x=0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=0;
    	x = 0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }
int main()
{
	fio;
	// memset(memo,-1,sizeof(memo));
	// f(i,0,101)
	// 	f(j,0,101)
	// 		memo[i][0][j]=1;
	// f(i,0,101)
	// 	f(j,0,101)
	// 		f(k,0,101)
	// 			memo[i][j][k]=fun(i,j,k);
    // f(i,0,101)
    //     f(j,0,101)
    //         f(k,0,101)
    //             if(memo[i][j][k]>=mod)
    //             {
    //                 cout<<"yes i'm present"<<endl;
    //                 break;
    //            }
    test
	{
		scan(n);
		f(i,0,n)
			scan(a[i]);
        diff++;
        ll sol = rec(1,a[0],a[1]);
        writel(sol);
        memset(a,0,sizeof(a));
	}
	cin>>n;
	return 0;
}

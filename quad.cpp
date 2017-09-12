/******************************************
*  Author : abhishek18620   
*  Created On : Fri Sep 01 2017
*  File : quad.cpp
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
    int t;
    cin>>t;
    return 0;
}

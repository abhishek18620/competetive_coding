/******************************************
*  Author : elliot   
*  Created On : Mon Sep 04 2017
*  File : sereja_and_commands.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 20
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
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
stack<int> type1[M],type2[M],clear;
int b1[M],b2[M],ctr;
int a[M][3],n,m;
int val1[M];
int sol[M];

void solve()
{
    //reverse traverse for calculating values
    //of type1 commands
    int fac=0,save=0,counter=0,curr=0;
    fr(i,m,1)
    {
        //val1[i]=1;
        if(type2[i].empty())
        {
            val1[i]+=fac;
            continue;
        }
        while(!type2[i].empty())
        {
            curr=type2[i].top();
            type2[i].pop();
            if(b2[curr]!=ctr)
            {
                fac+=val1[curr];
                b2[curr]=ctr;
                //val1[i]+=fac;
                continue;
            }
            else
            {
                val1[i]+=val1[curr];
                fac-=val1[curr];
            }
        }
        val1[i]+=fac;
        // //no new elememnts
        // if(counter==0)
        //     val1[i]=save+1;
    }
    //now turn to traverse val1 to calculate final vals
    int add=0;
    f(i,1,n+1)
    {
        counter=0;
        if(type1[i].empty())
        {
            sol[i]+=add;
            continue;
        }
        while(!type1[i].empty())
        {
            curr=type1[i].top();
            type1[i].pop();
            if(b1[curr]!=ctr)
            {
                add+=val1[curr];
                b1[curr]=ctr;
                //counter++;
                continue;
            }
            else
            {
                sol[i]+=val1[curr]%MOD;
                add-=val1[curr];
            }
        }
        sol[i]+=add%MOD;
    }
    return;
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
    ctr=0;
	test
	{
        ctr++;
        scanf("%d %d",&n,&m);
        f(i,0,n+2)
            sol[i]=0;
        fill(val1,val1+M,1);
            // f(i,1,max(n,m)+1)
        // {
        //     type1[i].swap(clear);
        //     type2[i].swap(clear);
        // }
        f(i,1,m+1)
        {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
            // if type 1
            if(a[i][0]==1)
            {
                    type1[a[i][1]].push(i);
                    type1[a[i][2]].push(i);
            }
            else
            {
                if(a[i][1]!=a[i][2])
                {
                    type2[a[i][1]].push(i);
                    type2[a[i][2]].push(i);
                }
                else
                {    //val1[a[i][1]]++;    
                    type2[a[i][1]].push(i);
                    type2[a[i][2]].push(i);
                }
            }
        }
        solve();
        f(i,1,n+1)
            printf("%d ",sol[i]);
        printf("\n");    
    }
    cin>>t;
	return 0;
}

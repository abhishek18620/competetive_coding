/******************************************
*  Author : elliot   
*  Created On : Sun Oct 08 2017
*  File : dishes.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10
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

vector<int> a[M];
int n,m,mem[M];
//int minmax[M][2];
//int sz[M];

inline int OtherIndex(int i, int j)
{
    int size=a[i].size();
    return j-1>0?j-1:size-1;
}

int solve()
{
    int curr,opt,prv,other,sz1,sz2;
    fill(mem,mem+M,0);
    f(i,0,n-1)
    {
        sz1=a[i].size();
        sz2=a[i+1].size();
        f(j,0,sz2)
        {
            curr=a[i+1][j];
            opt=0;
            f(k,0,sz1)
            {
                prv=a[i][k];
                other=mem[OtherIndex(i,k)];
                opt=max(opt,other+abs(curr-prv)*(i+1));
            }
            mem[j]=opt;
        }
    }
    return mem[sz2-1];
}


// int solve(int choice)
// {
//     ll diff1=0,diff2=0,sol1=0,sol2=0;
//     int curr1=-1,curr2=-1,prv=-1;
//     vector<int>:: iterator small1,large2,small2;
//     small1=(choice==1)?min_element(a[0].begin(),a[0].end()) : max_element(a[0].begin(),a[0].end());
//     prv=small1-a[0].begin();

//     f(i,1,n)
//     {
//         large2=max_element(a[i].begin(),a[i].end());
//         small2=min_element(a[i].begin(),a[i].end());
//         curr1=large2-a[i].begin();
//         curr2=small2-a[i].begin();
//         //sol1
//         diff1=abs(a[i-1][prv]-a[i][curr2]);
//         diff2=abs(a[i-1][prv]-a[i][curr1]);
//         if(diff1>diff2)
//         {
//             sol1+=diff1*i;
//             prv=OtherIndex(i,curr2);                    
//         }
//         else
//         {
//             sol1+=diff2*i;
//             prv=OtherIndex(i,curr1);
//         };
//     }
//     return max(sol1,sol2);
// }

// int solve_rev(int choice)
// {
//     ll diff1=0,diff2=0,sol1=0,sol2=0;
//     int curr1=-1,curr2=-1,prv=-1;
//     vector<int>:: iterator small1,large2,small2;
//     small1=(choice==1)?min_element(a[n-1].begin(),a[n-1].end()) : max_element(a[n-1].begin(),a[n-1].end());
//     prv=small1-a[n-1].begin();

//     fr(i,n-2,0)
//     {
//         large2=max_element(a[i].begin(),a[i].end());
//         small2=min_element(a[i].begin(),a[i].end());
//         curr1=large2-a[i].begin();
//         curr2=small2-a[i].begin();
//         //sol1
//         diff1=abs(a[i+1][prv]-a[i][curr2]);
//         diff2=abs(a[i+1][prv]-a[i][curr1]);
//         if(diff1>diff2)
//         {
//             sol1+=diff1*i;
//             prv=OtherIndex(i,curr2);                    
//         }
//         else
//         {
//             sol1+=diff2*i;
//             prv=OtherIndex(i,curr1);
//         };
//     }
//     return max(sol1,sol2);
// }

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
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    test
	{
        scan(n);
        int te;
        //input
        f(i,0,n+1)
            a[i].clear();
        f(i,0,n)
        {
            scan(m);
            f(j,0,m)
            {
                scan(te);
                a[i].eb(te);
            }
        }
        // ll sol1=max(solve(1),solve_rev(1));
        // ll sol2=max(solve(2),solve_rev(2));
        // ll ans=max(sol1,sol2);
        // writel(ans);
        ll ans= solve();
        writel(ans);
	}
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

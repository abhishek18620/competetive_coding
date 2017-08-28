/******************************************
*  Author : elliot   
*  Created On : Sun Aug 20 2017
*  File : greedy_candidates.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 1009
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
struct comp
{
    int sal;
    int idx;
    int off;
    bool choosen;
}a[M];
bool comparator(const comp& lhs, const comp& rhs)
{
  return lhs.sal > rhs.sal;
}
int n,m,b[M];

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
	test
	{
        scan(n); scan(m);
        f(i,0,n)
            scan(b[i]);
        f(i,0,m)
        {
            a[i].idx=i;
            scan(a[i].sal);
            scan(a[i].off);
            a[i].choosen=0;
        }
        sort(a,a+m,comparator);
        string str;
        int cand=0,solcomp=m;
        ll solsal=0;
        f(i,0,n)
        {
            getline(cin,str);
            f(j,0,m)
            {
                if(str[a[j].idx]=='1' and a[j].sal >= b[i] and a[j].off>0)
                {
                    a[j].off--;
                    cand++;
                    solsal+=a[j].sal;
                    if(!a[j].choosen)
                    {
                        solcomp--;
                        a[j].choosen=1;
                    }
                    break;    
                }
            }
        }
        printf("%d %lld %d\n",cand,solsal,solcomp);
    }
    cin>>t;
	return 0;
}

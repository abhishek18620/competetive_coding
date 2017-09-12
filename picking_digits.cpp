/******************************************
*  Author : elliot   
*  Created On : Sat Sep 09 2017
*  File : picking_digits.cpp
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

int b[26],a[10],ctr;

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
    string str;
    int x,y,asc1,asc2;
    ctr=0;
    int t; scanf("%d",&t); getline(cin,str);
    while(t--)
	{
        ctr++;
        getline(cin,str);
        int lim=str.length();
        fill(a,a+10,0);
        f(i,0,lim)
        {
            x=str[i]-'0';
            a[x]++;
        }
        int st=0;
        f(i,0,10)
        {
            if(a[i]==0)
                continue;
            if(a[i]>1)
                st=i;
            else
                st=i+1;
            f(j,st,10)
            {
                if(a[j]>0)
                {
                    asc1=i*10+j;
                    asc2=i+j*10;
                    if(asc1>=65 and asc1<=90)
                        b[asc1-65]=ctr;
                    if(asc2>=65 and asc2<=90)
                        b[asc2-65]=ctr;
                }
            }    
        }
        f(i,0,26)
        {
            if(b[i]==ctr)
                printf("%c",char(i+65));
        }
        printf("\n");
    }
    int n;
    cin>>n;
	return 0;
}

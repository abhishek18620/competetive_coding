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
int n,k,sol,mask;
string str;
ll ingr[40];
bitset<12> orres;
int dp[(1<<12)+4][40];
int coor[40][2];

ll str_to_num()
{
	ll ret=0;
	f(i,0,k)
	{
		if(str[i]=='1')
			ret+=1<<(k-1-i);
	}
	return ret;
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
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	fio;
    test
	{
		//state(i,j)-----(i=bitmask j=if i can go there)
        //shops and ingredients
        scan(n); scan(k);
		//INPUT
		f(i,0,n)
			cin>>coor[i][0]>>coor[i][1];
		f(i,0,n)
		{
			getline(cin,str);
			ingr[i]=str_to_num();
		}
		ll ret;
        f(i,0,1<<k)	
        {
            f(j,0,n)
            {
				ret=i|ingr[j];
				 		
            }
        }
	}
	return 0;
}
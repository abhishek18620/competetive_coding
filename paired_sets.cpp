// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 2509
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
#define itr set<int>:: iterator
#define ftr(myset) for(itr it=myset.begin(); it!=myset.end();it++)
using namespace std;

//GLOBALS
int n,k;
vector<ll> sum;
set<int> a[M];

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
        scan(n); scan(k);
        ll req=(k*(k+1))/2;
        int len=0,ele,ctr=0;
        f(i,0,n)
        {
            scan(len);
            f(j,0,len)
            {
                scan(ele);
                a[i].insert(ele);
            }
            ll s=0;
            ftr(a[i])
                s+=*it;
            sum.pb(s);
        }
        //naive one
        f(i,0,n)
        {
            f(j,0,n)
            {
                if(sum[i]+sum[j]>=req)
                
            }
        }
	}
	return 0;
}
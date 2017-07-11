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
vector< pair<int,int> > v;

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
	string s;
	test
	{
        cin>>s;
        int lim=s.length();
        int ctr=0;
        f(i,0,lim)
        {
            if(s[i]=='<')
            {
                ctr++;
            }
            else if(s[i]=='>')
            {
                v.pb(mp(1,ctr+1));
                ctr=0;
            }
        }
        v.pb(mp(1,ctr+1));
        ll sol=v[v.size()-1].S;
        fr(i,v.size()-1,1)
        {
            // v[i-1].S > v[i].F
            if(v[i-1].S <= v[i].F)
            {
                int diff=(v[i].F+1) - v[i-1].S;
                if(v[i-1].F == v[i-1].S)
                {
                    v[i-1].F+=diff;
                    v[i-1].S+=diff;
                }
                else
                    v[i-1].S+=diff;
            }

            if(v[i-1].S > sol)
                sol=v[i-1].S;
        }
        writel(sol);
        v.clear();
    }
    cin>>t;
	return 0;
}
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define sz 1e9+6
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
#define pai pair<ll,ll>
#define pb push_back
using namespace std;

map<ll,vector< pair<ll,ll> > > mymap;

//COMPARATOR

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
	ll n,m,k,a1,a2,a3;
    scanl(n); scanl(m); scanl(k);
	f(i,0,k)
    {
        scanl(a1);  scanl(a2);  scanl(a3);
        mymap[a1].pb(mp(a2,a3));
    }
    ll res=n*m;
    map<ll,vector< pair<ll,ll> > >::iterator it=mymap.begin();
    for(;it!=mymap.end();it++)
    {
        sort(it->S.begin(),it->S.end());
        vector< pair<ll,ll> >::iterator it2=it->S.begin();
        ll a=it2->F;
        ll b=it2->S;
        for(;it2!=it->S.end();it2++)
        {
            if(it2->F<=b)
            {
                b=max(it2->S,b);
            }
            else
            {
                res-=b-a+1;
                a=it2->F;
                b=it2->S;
            }
        }
        res-=b-a+1;
    }
        writel(res);
    int t;
    cin>>t;
    return 0;
}
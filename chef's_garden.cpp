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
vector< pair<ll,ll> > v;
vector< pair<pair<ll,ll> ,pair<ll,ll> > > req;
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
	//fio;
	test
	{
        int n; scan(n);
        ll te1,te2;
        f(i,0,n)
        {
            scanl(te1); scanl(te2);
            v.pb(mp(te1,te2));
        }

        ll d=0; 
        f(i,0,n-1)
        {
            //there must be some time during which 1st > 2nd
            if(v[i].F >= v[i+1].F)
            {
                if(v[i+1].S == v[i].S)
                {
                    if(v[i].F > v[i+1].F)
                        req.pb(mp(mp(0,INF) , mp(0,0)));    
                    else
                        req.pb(mp(mp(0,0) , mp(0,0)));
                }
                else
                {
                    d=(v[i].F - v[i+1].F)/(v[i+1].S - v[i].S);
                    
                    if(d<0) //eternal case for (1st > 2nd)
                        req.pb(mp(mp(0,INF) , mp(0,0)));
                    else if(d>0)
                        req.pb(mp(mp(0,d-1) , mp(d+1,INF)));
                    else
                    {
                        if(v[i].S > v[i+1].S)
                            req.pb(mp(mp(0,INF) , mp(0,0)));
                        else
                            req.pb(mp(mp(0,0) , mp(0,INF)));
                    }
                }
            }
            else
            {
                if(v[i+1].S == v[i].S)
                {
                    req.pb(mp(mp(0,0) , mp(0,INF)));
                }
                else
                {
                    d=(v[i].F - v[i+1].F)/(v[i+1].S - v[i].S);
                    
                    if(d<0) //eternal case for (1st < 2nd)
                        req.pb(mp(mp(0,0) , mp(0,INF)));
                    else if(d>0)
                        req.pb(mp(mp(d+1,INF) , mp(0,d-1)));
                }
            }
        }
        //finding zig-zag
        bool first=1;
        pair<ll , ll> sol1,sol2;
        sol1.F=sol2.F=-1;
        sol1.S=sol2.S=M;
        f(i,0,n-1)
        {
            if(first)
            {
                //sol1
                if(req[i].F.F > sol1.F)
                    sol1.F=req[i].F.F;
                if(req[i].F.S < sol1.S)
                    sol1.S=req[i].F.S;
                    
                //sol2
                if(req[i].S.F > sol2.F)
                    sol2.F=req[i].S.F;
                if(req[i].S.S < sol2.S)
                    sol2.S=req[i].S.S;
                
                first=0;
            }
            else
            {
                //sol1
                if(req[i].S.F > sol1.F)
                    sol1.F=req[i].S.F;
                if(req[i].S.S < sol1.S)
                    sol1.S=req[i].S.S;
                    
                //sol2
                if(req[i].F.F > sol2.F)
                    sol2.F=req[i].F.F;
                if(req[i].F.S < sol2.S)
                    sol2.S=req[i].F.S;
            }
        }
        bool f1=0,f2=0;
        int c=0; 
        if(sol1.F <= sol1.S)
        {
            f1=1;
            c++;
        }
        //cout<<"\nsol 1 ="<<sol1.F<<"    "<<sol1.S;
        if(sol2.F <= sol2.S)
        {
            f2=1;
            c++;
        }
        //cout<<"\nsol 2 ="<<sol2.F<<"    "<<sol2.S;
        cout<<endl;
        cout<<c<<endl;
        if(f1)
            cout<<sol1.F<<" "<<sol1.S;
        if(f2)
            cout<<sol2.F<<" "<<sol2.S;
        req.clear();
        v.clear();
    }
    cin>>t;
	return 0;
}
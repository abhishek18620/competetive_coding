// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#include<stdint.h>
#define M 10000
//#define INF 1e15+38
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test ll t; scanl(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

//GLOBALS
const ll INF = INT64_MAX;
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
	fio;
	test
	{
        int n; scan(n);
        ll te1,te2;
        f(i,0,n)
        {
            scanl(te1); scanl(te2);
            v.pb(mp(te1,te2));
        }

        double d=0.0; 
        f(i,0,n-1)
        {
            //there must be some time during which 1st > 2nd
            if(v[i].F >= v[i+1].F)
            {
                //special case of equal rate
                if(v[i+1].S == v[i].S)
                {
                    if(v[i].F > v[i+1].F)
                        req.pb(mp(mp(0,INF) , mp(-1,-1)));    
                    else    //either greater or equal
                    {
                        req.pb(mp(mp(-1,-1) , mp(-1,-1)));
                    }
                }
                //1st > 2nd initially
                //so ,ust be intervals
                else
                {
                    d=double((v[i].F - v[i+1].F))/double((v[i+1].S - v[i].S));
                    
                    if(d<0) //eternal case for (1st > 2nd)
                        req.pb(mp(mp(0,INF) , mp(-1,-1)));
                    else if(d>0)
                        req.pb(mp(mp(0,ll(ceil(d))-1) , mp(ll(floor(d))+1,INF)));
                    else    //d=0(equal initial height)
                    {
                        if(v[i].S > v[i+1].S)
                            req.pb(mp(mp(1,INF) , mp(-1,-1)));
                        else
                            req.pb(mp(mp(-1,-1) , mp(1,INF)));
                    }
                }
            }
            else    //(2nd's height is strictly greater than 1st right from start)
            {
                if(v[i+1].S == v[i].S)
                {
                    req.pb(mp(mp(-1,-1) , mp(0,INF)));
                }
                else
                {
                    d=double((v[i].F - v[i+1].F))/double((v[i+1].S - v[i].S));
                    
                    if(d<0) //eternal case for (1st < 2nd)
                        req.pb(mp(mp(-1,-1) , mp(0,INF)));
                    else if(d>0)
                        req.pb(mp(mp(ll(floor(d))+1,INF) , mp(0,ll(ceil(d))-1)));
                }
            }
        }
        //finding zig-zag
        bool first=1;
        if(n==1)
        {
            printf("1\n0 Inf\n");
        }
        else
        {
            pair<ll , ll> sol1,sol2;
            sol1.F=req[0].F.F;  sol1.S=req[0].F.S;
            sol2.F=req[0].S.F;  sol2.S=req[0].S.S;
            //for first seq(h1>h2<h3...)
            f(i,1,n-1)
            {
                if(first)
                {
                    //sol1
                    sol1.F=max(sol1.F , req[i].S.F);
                    sol1.S=min(sol1.S , req[i].S.S);                
                    //sol2
                    sol2.F=max(sol2.F , req[i].F.F);
                    sol2.S=min(sol2.S , req[i].F.S);                
                    first=0;
                }
                else
                {
                    //sol1
                    sol1.F=max(sol1.F , req[i].F.F);
                    sol1.S=min(sol1.S , req[i].F.S);                
                    //sol2
                    sol2.F=max(sol2.F , req[i].S.F);
                    sol2.S=min(sol2.S , req[i].S.S);                
                    first=1;
                }
            }

            //cout<<"\nsol1 : "<<sol1.F<<"  "<<sol1.S;
            //cout<<"\nsol2 : "<<sol2.F<<"  "<<sol2.S;

            bool f1=0,f2=0;
            int c=0; 
            if((sol1.F!=-1 and sol1.S!=-1) and sol1.F<=sol1.S)
            {
                f1=1;
                c++;
            }
            //cout<<"\nsol 1 ="<<sol1.F<<"    "<<sol1.S;
            if((sol2.F!=-1 and sol2.S!=-1) and sol2.F<=sol2.S)
            {
                f2=1;
                c++;
            }
            //cout<<"\nsol 2 ="<<sol2.F<<"    "<<sol2.S;
            //cout<<endl;
            if(f1 and f2)
            {
                if(sol1.F > sol2.F)
                    swap(sol1,sol2);

                if(sol1.S+1 == sol2.F)
                {
                    printf("1\n");
                    printf("%lld ",sol1.F);
                    //cout<<"1\n"<<sol1.F<<" ";
                    if(sol2.S == INF)
                        puts("Inf");
                        //cout<<"Inf"<<endl;
                    else
                        printf("%lld\n",sol2.S);
                        //cout<<sol2.S<<endl;
                }
                else
                {
                    printf("2\n");
                    printf("%lld ",sol1.F);
                    // cout<<"2"<<endl;
                    // cout<<sol1.F<<" ";
                    if(sol1.S == INF)
                        puts("Inf")
                        printf("Inf\n");
                        //cout<<"Inf"<<endl;
                    else
                        printf("%lld\n",sol1.S);
                        //cout<<sol1.S<<endl;

                    printf("%lld ",sol2.F);
                    cout<<sol2.F<<" ";
                    if(sol2.S == INF)
                        printf("Inf\n");
                        //cout<<"Inf"<<endl;
                    else
                        printf("%lld\n",sol2.S);
                        //cout<<sol2.S<<endl;
                }
            }
            else if(f1)
            {
                printf("1\n%lld ",sol1.F);
                //cout<<"1"<<endl;
                if(sol1.S == INF)
                    printf("Inf\n");
                //cout<<"Inf"<<endl;
                else
                    printf("%lld\n",sol1.S);
                        //cout<<sol1.S<<endl;
                // cout<<sol1.F<<" ";
                // if(sol1.S == INF)
                //     cout<<"Inf"<<endl;
                // else
                //     cout<<sol1.S<<endl;
            }
            else if(f2)
            {
                printf("1\n%lld ",sol2.F);
                //cout<<"1"<<endl;
                if(sol2.S == INF)
                    printf("Inf\n");
                //cout<<"Inf"<<endl;
                else
                    printf("%lld\n",sol2.S);
                // cout<<"1"<<endl;
                // cout<<sol2.F<<" ";
                // if(sol2.S == INF)
                //     cout<<"Inf"<<endl;
                // else
                //     cout<<sol2.S<<endl;
            }
            else
                printf("0\n");
        }
        req.clear();
        v.clear();
    }
     cin>>t;
 return 0;
}
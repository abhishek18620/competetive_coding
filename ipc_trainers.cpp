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
using namespace std;
#define pb push_back

    
vector< pair<ll,ll> > a[100006];
priority_queue< pair<ll,ll> > pq,cl;
    
void writel(ll n)
{
    if(n<0){n=-n;putchar('-');}
    ll i=10;
    char output_buffer[11];output_buffer[10]='\n';
    do{output_buffer[--i]=(n%10)+'0';n/=10;}
    while(n);
    do{putchar(output_buffer[i]);}while(++i<11);
}
    
void scan(ll &x){
        register ll c = gc();
        x = 0;
        for(;c<48 || c>57;c=gc());
        for(;c>47 && c<58;c=gc())
            x=(x<<1)+(x<<3)+c-48;
    }
    
    
int main()
{
    //fio;
    ll n,d,di,ti,si;
    ll tot;
    pair<ll ,ll> temp;
    ll t; scan(t);
    while(t--)
    {
        tot=0;
        scan(n); scan(d);
        f(i,0,n)
        {
            scan(di); scan(ti); scan(si);
            a[di-1].pb(mp(si,ti));
            tot+=si*ti;
        }
        f(i,0,d)
        {
            f(j,0,a[i].size())
            {
                pq.push(mp(a[i][j].F,a[i][j].S));
            }
            if(pq.empty())
            {
                temp.F=temp.S=0;
                continue;
            }
            else
            {    
                temp=pq.top();
                tot-=temp.F;
                pq.pop();
            }
            if(temp.S<=1)
                continue;
            else
            {
                temp.S--;
                pq.push(temp);
            }
        }
        printf("%lld\n",tot);
        f(i,0,d+1)
            a[i].clear();
        pq=cl;
    }
    return 0;
} 
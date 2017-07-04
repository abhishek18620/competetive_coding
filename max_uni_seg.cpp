// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 1000006
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
int a[M],pre[M],n;
ll sum[M+1];
    
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
    int te,l=0;
    ll sol=0,sol_te=0;
    test
    {
        scan(n);
        sol=0,sol_te=0;
        l=0;
        
        //Ci<=n
        memset(pre,-1,((n+1)*sizeof(ll))/2);
        sum[0]=0;
        f(i,0,n)
            scan(a[i]);
        // f(i,0,n)
        //     scanl(sum[i]);
        f(i,0,n)
        {
            scan(te);
            sum[i+1]=sum[i]+te;
        }
        f(i,0,n)
        {
            //already encountered this number some indices back
            if(pre[a[i]]!=-1)
            {
                if(l<pre[a[i]]+1)
                    l=pre[a[i]]+1;
            }
            sol_te=sum[i+1]-sum[l];
            if(sol<sol_te)
                sol=sol_te;
            pre[a[i]]=i;
        }
        writel(sol);
    }
    cin>>t;
    return 0;
} 
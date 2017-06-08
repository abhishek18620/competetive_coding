#include <bits/stdc++.h>
#define M 100010
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (ll i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;
    
//GLOBALS
ll a[M],sum[M];
    
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
    
ll bsearch(ll s, ll hi, ll lo)
{
    ll mid=-1,ind=-1;
    if(s > a[hi])
        return -1;
    while(hi>lo)
    {
        mid=lo+(hi-lo)/2;
        if(a[mid]<s)
            lo=mid+1;
        else if(a[mid]>=s)
            hi=mid;
        
    }
    return lo;
}
    
    
int main()
{
    //fio;
    // For getting input from input.txt file
    // freopen("/home/abhi/Desktop/input.txt", "r", stdin);
    
    // // Printing the Output to output.txt file
    // freopen("/home/abhi/Desktop/output.txt", "w", stdout);
    test
    {
        ll n,q;
        scanl(n); scanl(q);
        ll su=0;
        f(i,0,n)
            scanl(a[i]);
        sort(a,a+n);
        
        sum[0]=a[0];
        f(i,1,n)
            sum[i]=sum[i-1]+a[i];
        while(q--)
        {
            ll ans=-1,sure=0;
            ll que; scanl(que);
            ll ind=bsearch(que,n-1,0);
            ll maybe=ind;
            // all numbers are smaller than que
            if(ind == -1)
            {
                maybe=n;
                ind = n-1;
            }
            else
            {
                sure=n-ind;
                ind--;
            }
            ll lo=0,hi=ind;
            while(lo<=hi)
            {
                ll mid=(hi+lo)/2;
                //snakes required to convert snakes from (mid to hi)
                // cause they are more likely to get converted
                ll req=que*(ind-mid+1);
                ll available=sum[ind]-sum[mid-1];
                if(req-available <= mid)
                {
                    ans=mid;
                    hi=mid-1;
                }
                else
                    lo=mid+1;
            }
            if(ans==-1)
                ans=maybe;
            writel(n-ans);
            //cout<<n-ans<<endl;
            //cout<<"for query "<<que<<"--->  "<<n-ans<<endl;
        }
    }
    return 0;
} 
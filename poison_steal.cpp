#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
ll a[M],sum[M],n;

ll built(ll save1,ll save2)
{
    ll tot=save2-save1+1;
    ll series=((tot/2+1)*(tot/2+2))/2;
    series+=series-a[tot/2+1];
    ll req=(sum[save2]-sum[save1-1])-series;
    req+=sum[save1-1]-sum[0] + sum[n+1]-sum[save2];
    return req;
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
	//fio;
	test
	{
        scanl(n);
        vector<int> pos;
        ll save1=-1,save2=-1,min1=INF,min2=INF;
        f(i,0,n)
        {
            scanl(a[i]);
            if(a[i]<min1)
            {
                save1=i;
                min1=a[i];
            }
        }
        sum[0]=0;
        f(i,1,n)
            sum[i+1]=sum[i]+a[i];
        f(i,save1,n)
        {
            if(a[i]<min2)
            {
                save2=i;
                min2=a[i];
            }
        }
        if((save1-save2)%2==0)
            cout<<built(save1,save2)<<endl;
        else
        {
            cout<<built(save1,save2-1)
            // if(save1 > save2)
            //     cout<<built(save1-1,save2)<<endl;
            // else
            //     cout<<built(save1,save2-1)<<endl;
        }
    }
    cin>>t;
	return 0;
}
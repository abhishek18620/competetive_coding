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
using namespace std;

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

bitset<M> bs[M],bs_temp;
int main()
{
	fio;
	test
	{
		int n,k,len,ele,ctr=0,ptr=0; cin>>n>>k;
		ll ans=0;
		f(i,0,n)
			bs[i].reset();
		f(i,0,n)
        {
			scan(len);
            if(len==k)
			{
				ans+=n-1-ptr;
				f(j,0,len)
					scan(ele);
				ptr++;
			}
			else
			{
				f(j,0,len)
				{
					scan(ele);
					bs[ctr][M-ele]=1;
				}
				ctr++;
			}
		}
		//processing
		f(i,0,ctr)
		{
			f(j,i+1,ctr)
			{
				bs_temp=bs[i]|bs[j];
				if(bs_temp.count()==k)
					ans++;
			}
		}
		cout<<ans<<endl;	
	}
	cin>>t;
	return 0;
}
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f1(i, j, k) for (ll i = j; i < k; i++)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
ll n,k,lst,ans=0,tot=0;
ll a[M],z[M];

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
		// else
		// {
		// 	ind=mid;
		// 	break;
		// }
	}
	//lo is the index which has element
	//greater than or equal to s
	// if1(ind!=-1)	
	// 	return ind;
	// else
	// 	return lo;
	return lo;
}

void count_zeroes()
{
	ll first=1;
	ll ct=0;
	f1(i,1,n+1)
	{
		ct=z[i-1];
		ll num=a[i]/first;
		while(num>=10)
		{
			ct++;
			num=num/10;
		}
		first=a[i];
		z[i]=ct;
	}
}

inline void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

inline void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	scanl(n); scanl(k);
	bool flag=1;
	lst=n+1;
	f1(i,1,n+1)
		scanl(a[i]);

	sort(a+1,a+n+1);
	count_zeroes();
	//decides lst
	f1(i,1,n+1)
	{
		if(a[i]>=k)
		{
			lst=i;
			break;
		}
	}
	//search the array divider
	ll ind=-1;
	f1(i,1,n+1)
	{
		ll pro=z[i]+z[i+1];
		if(pro < 19)
		{
			if(a[i]*a[i+1] >= k)
			{
				ind=i;
				break;
			}
		}
		else
		{
			ind=i;
			break;
		}
	}
	//left half and right half
	ll lh=ind,rh=n-ind;

	if(lst==1)
		ans=0;
	else if(ind == 1)
		ans=lst-1;
	else if(ind==-1)
		ans=(1 << (lst-1))-1;
	else
	{
		//we need to binary search for first part
		//elements only in second part
		ll res_ind=-1, lo=ind+1,hi=n,num=0;
		
		ans=(1<<lh)-1;	//sets of left part only
		
		f1(i,1,ind)
		{
			if(k%a[i] == 0)
				res_ind=bsearch((k/a[i]),hi,lo);
			else
				res_ind=bsearch((k/a[i])+1,hi,lo);
			if(res_ind == -1)	// all products are smaller than k
			{
				num=n-ind;
				ll sets=(1<<(i-1));
				ans+=sets*num;
			}
			else
			{
				num=res_ind-ind-1;
				if(num!=0)
				{
					//sets on lhs
					ll sets=(1<<(i-1));
					ans+=sets*num;
					// tot=(i-1)+num;
					// ans+=(1<<tot)-1-(i-1);
					hi=res_ind;
				}
			}
			// ll tot=(i-1)+num;
			// ans+=(1<<tot)-1;
		}
		ans+=lst-(ind)-1;
	}
	//cout<<"\n total number of sets :	"<<ans<<endl;
	cout<<ans<<endl;
	cin>>n;
	return 0;
}
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 100
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
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
ll a[M],b[M],c[M],sum_a[M],sum_c[M],mod=1e9+7;

ll mod_calc(ll a,ll b)
{
    ll res = 0;  // Initialize result
    // Update a if it is more than
    // or equal to mod
    a %= mod;
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
        b >>= 1;  // b = b / 2
    }
    return res;
}

int bsearch_a(ll s, int hi, int lo)
{
	int mid=-1,ind=-1;
	if(s > a[hi])
		return -1;
	while(hi>lo)
	{
		mid=(hi+lo)/2;
		if(a[mid]<=s)
			lo=mid+1;
		else    //s is lesser than c[mid]
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
    if(a[lo]<=s)
        return lo;
    else if(lo==0) //all numbers in c are strictly greater than s
        return -2;
    else //a[lo]>s and lo=some index
        return lo-1;
}

int bsearch_c(ll s, int hi, int lo)
{
    int mid=-1,ind=-1;
	if(s > c[hi])
		return -1;
	while(hi>lo)
	{
		mid=(hi+lo)/2;
		if(c[mid]<=s)
			lo=mid+1;
		else    //s is lesser than c[mid]
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
    if(c[lo]<=s)
        return lo;
    else if(lo==0) //all numbers in c are strictly greater than s
        return -2;
    else //a[lo]>s and lo=some index
        return lo-1;
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
	fio;
	test
	{
        int p,q,r;
        scan(p); scan(q); scan(r);
        f(i,0,p)
            scanl(a[i]);
        f(i,0,q)
            scanl(b[i]);
        f(i,0,r)
            scanl(c[i]);
        sort(a,a+p);
        sort(b,b+q);
        sort(c,c+r);
        ll sum=0;
        f(i,0,r)
        {
            sum_c[i]=sum+c[i];
            sum=sum_c[i];
        }
        sum=0;
        f(i,0,p)
        {
            sum_a[i]=sum+a[i];
            sum=sum_a[i];
        }
        ll lo_a=0,hi_a=p-1,lo_c=0,hi_c=r-1;
        ll ans=0,s1=0,s2=0;
        f(i,0,q)
        {
            ll num=b[i];
            //bsearch num in both a & c.
            int ind1=bsearch_a(num,p-1,0);
            int ind2=bsearch_c(num,r-1,0);
            ll n1=0,n2=0;
            //a processing
            if(ind1==-2)
                n1=0;
            else if(ind1==-1)
            {
                ind1=p-1;
                n1=p;
            }
            else
                n1=ind1+1;
            //c processing
            if(ind2==-2)
                n2=0;
            else if(ind2==-1)
            {
                ind2=r-1;
                n2=r;
            }
            else
                n2=ind2+1;
            s1=0; s2=0;
            if(n1>0 and n2>0)
            {
                s1=n2*num + sum_c[ind2];
                s2=n1*num + sum_a[ind1];
            }
            ans+=mod_calc(s1,s2);
        }
        writel(ans%mod);
    }
    cin>>t;
	return 0;
}

//SOMETIMES A FUCKING 0 CAN KILL YOU..
//MORAL : DONT UNDERESTIMATE ANYONE..HE MAYBE ACTING LIKE THIS FUCKING ZERO
//        AND SOMEDAY OUTOF NOWHERE HE'LL STAB YOU HARDER THAN ANYONE..
//        ITS JUST FOR FUN..IM NOT A WRITER JUST AN OBSERVER I HAD A 
//        ROUGH CHILDHOOD THAT ANYONE CAN IMAGINE.. THESE RUBBISH THINGS
//        JUST KEEPING ME ALIVE. REJECTION EVERYWHERE HAS BEEN BY DESTINY
//        BUT THEN AS "GEETA" SAYS ITS JUST A TASK THAT I NEED TO DO. MY DESTINY
//        LIES IN FUTURE'S WOMB.
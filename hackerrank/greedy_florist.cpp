// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;


//COMPARATOR
bool comp(const int &lhs, const int &rhs)
{
  return lhs > rhs;
}

//GLOBALS
int a[104];
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
    int n,k;
    scanf("%d%d",&n,&k);
    f(i,0,n)
        scanf("%d",&a[i]);
    sort(a,a+n,comp);
    int x=1;
    ll sol=0,sum=0,left=0;
    for(int i=0; i<n;i+=k)
    {
        sum=0;
        left=n-i;
        for(int j=0;j<k and j<left;j++)
            sum+=a[i+j];
        sum*=x;
        sol+=sum;
        x++;
    }
    printf("%lld\n",sol);
    cin>>n;
	return 0;
}

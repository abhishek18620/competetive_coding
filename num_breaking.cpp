#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
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
    	register int c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
    fio;
    int a[811];
    f(i,0,812)
        a[i]=-1;
    a[10]=1; a[13]=2; a[31]=2; a[68]=2; a[86]=2; a[100]=1; a[130]=2; a[310]=2; a[680]=2;
    set<int> sum;
    f(i,2,812)
    {
        int s=0;
        sum.clear();
        int num=i;
        int steps=0;
        while(1)
        {
            steps++;
            s=0;
            while(num > 0)
            {
                int d=num%10;
                s+=d*d;
                num=num/10;            
            }
            num=s;
            int prv=sum.size();
            sum.insert(s);
            if(s==1)
            {
                a[i]=steps;
                break;
            }
            else if(a[s] > 0)
            {
                a[i]=steps+a[s];
                break;
            }
            else if(sum.size() == prv or a[s]==0)   // numbers got repeated or already calculated
            {
                a[i]=0;
                break;
            }
        }
    }
    ll n; scanl(n);
    int s=0;
    while(n > 0)
    {
        int d=n%10;
        s+=d*d;
        n=n/10;            
    }
    //cout<<"\n sum is : "<<s<<endl;
    if(a[s] > 0)
        cout<<a[s]+1<<endl;
    else
        cout<<"-1"<<endl;
    cin>>n;
    return 0;
}
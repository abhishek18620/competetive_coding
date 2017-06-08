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
    string s;
    cin>>s;
    int lim=s.length();;
    int ans=0;
    while(1)
    {
        int pos=-1;
        f(i,0,lim)
        {
            if(s[i]=='1')
                pos=i;
        }
        if(pos==-1)
            break;
        //flipping
        f(i,0,pos)
        {
            if(s[i]=='1')
                s[i]='0';
            else
                s[i]='1';
        }
        ans++;
        lim=pos;
    }
    cout<<ans<<endl;
    int t;
    cin>>t;
    return 0;
}
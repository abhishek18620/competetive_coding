#include <bits/stdc++.h>
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
	test
	{
        ll n,k;
        scanl(n); scanl(k);
        bool a[k];
        // i dont even know y im doing this but these onlin ides intialise the whole arr with true val
        // fuck them
        f(i,0,k)
            a[i]=0;
        bool some =0,all=0,sad=0,out=0;
        ll count=0;
        f(i,0,n)
        {
            ll te; scanl(te);
            f(j,0,te)
            {
                ll te1; scanl(te1);
                // check if ingre. is unique or not
                if(!out)
                {
                    if(!a[te1-1])
                    {
                        a[te1-1]=1;
                        count++;
                    }
                    // got all ingredients
                    if(count == k)
                    {
                        if(i<n-1)
                            some=1;
                        else
                            all=1;
                        // signifies needs trenched but still gotta take input
                        out=1;
                    }
                }
            }
        }
        if(some)
            cout<<"some"<<endl;
        else if(all)
            cout<<"all"<<endl;
        else
            cout<<"sad"<<endl;
	}
    cin>>t;
	return 0;
}
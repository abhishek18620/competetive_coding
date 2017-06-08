#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define test ll t; scanl(t); while(t--)
using namespace std;


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
        ll n,q,prv;
        scanl(n); scanl(q);
        ll mar[n],count[n];
        scanl(mar[0]);
        prv=mar[0];
        count[0]=1;
        f(i,1,n)
        {
            scanl(mar[i]);
            if(mar[i] == prv)
                count[i]=count[i-1]+1;
            else
            {
                count[i]=1;
                prv=mar[i];
            }
        }
        f(i,0,q)
        {
            ll u,w,fr,ans=0;;
            scanl(u); scanl(w); scanl(fr);
            fr--;
            f(j,u-1,w)
            {
                if(count[j+fr]-count[j]==fr and j+fr<w)
                {
                    ans++;
                    j+=fr;
                }
                f(k,j+1,w)
                {
                    if(count[k]==1)
                    {
                        j=k-1;
                        break;
                    }
                    j=k;
                }
            }
            cout<<ans<<endl;
        }
	}
    cin>>t;
	return 0;
}
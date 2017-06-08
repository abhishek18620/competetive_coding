#include <bits/stdc++.h>
#define M 100005
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define test int t; scanl(t); while(t--)
using namespace std;

//GLOBALS
int a[M];

void scanl(int &x){
    	register int c = getchar_unlocked();
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
        ll m,n,score=0,o=0,z=0;;
        scanl(m); scanl(n);
        bool flag=1;
        f(i,0,n)
        {
            scanl(a[i]);
            if(a[i]==0)     //misshit
            {
                m--;
                if(m==0 and i<n-1)
                    flag=0;
            }
            else            // right on target
            {
                if(flag)
                    m+=2;
                else
                    o++;
            }
        }
        if(flag)    // win
            cout<<"Yes "<<m<<endl;
        else        // loss
            cout<<"No "<<o<<endl;
	}
    cin>>t;
	return 0;
}
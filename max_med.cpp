#include <bits/stdc++.h>
#define M 100008
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
int a[M];

void scan(int &x){
    	register int c = gc();
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
        int n;
        scan(n);
        f(i,1,2*n+1)
            scan(a[i]);
        //sort
		sort(a+1,a+2*n+1);
        
		if(n>1)
        {
            int ind1=1,ind2=n+1, ind3=ind2+n/2;
            bool flag=1;
            f(i,0,n)
            {
                if(flag)
                {
                    swap(a[ind1],a[ind2]);
                    swap(a[ind2],a[ind3]);
                    ind1+=2;
                    ind2++;ind3++;
                    flag=0;
                }
                else
                {
                    flag=1;
                    swap(a[ind1],a[ind2]);
                    ind1+=2;
                    ind2++;
                }
            }
        }
        cout<<a[n+1]<<endl;
		f(i,1,2*n+1)
			cout<<a[i]<<" ";
		cout<<endl;
	}
    cin>>t;
    return 0;
}
#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i, j, k) for (int i = j; i < k; i++)
#define test int t; scan(t); while(t--)
using namespace std;

void scan(int &x){
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
        int n,m; scan(n),scan(m);
        int a[n][1001];
        int xf=-1,yf=-1;
        // int px,py;
        f(i,0,n)
        {
            f(j,0,m)
                scan(a[i][j]);
        }
        // x=a[0][0];y=a[0][0];
        f(i,0,n)
        {
            int cxf=0;
            int px=a[i][0];
            f(j,0,m)
            {
                if(a[i][j] == px)
                    cxf++;
                else
                    cxf=0;
                if(cxf > xf)
                    xf=cxf;
                
                px=a[i][j];
            }
        }

        f(i,0,m)
        {
            int cyf=0;
            int py=a[0][i];
            f(j,0,n)
            {
                if(a[j][i] == py)
                    cyf++;
                else
                    cyf=0;
                if(cyf > yf)
                    yf=cyf;
                py=a[j][i];
            }
        }
        if(xf==0)
            xf=1;
        if(yf==0)
            yf=1;
        cout<<xf*yf<<endl;
	}
    cin>>t;
	return 0;
}
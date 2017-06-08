    #include <bits/stdc++.h>
    #define f(i, j, k) for (int i = j; i < k; i++)
    #define f1(i, j, k) for (int i = j; i < k; i+=2)
    using namespace std;
    typedef long long li;
     
    void scan(int &x){
        	register int c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
        }
     
    int main()
    {
        int t; scan(t);
        while(t--)
        {
            int n;scan(n);
            int xe[n+1],ya[n+1];
            f(i,0,n)
                scan(xe[i]);
            f(i,0,n)
                scan(ya[i]);
            xe[n]=0;ya[n]=0;
            li sum1 =0,sum2 = 0;
            f1(i,0,n)
            {
                sum1+=xe[i] + ya[i+1];
                sum2+=ya[i] + xe[i+1];
            }
            cout<<min(sum1,sum2)<<endl;
        }
        return 0;
    } 
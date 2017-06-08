    #include <bits/stdc++.h>
    #define f(i, j, k) for (int i = j; i < k; i++)
    using namespace std;
     
    inline void scan(int &x){
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
            int n,m;
            scan(n); scan(m);
            bool a[n];
                f(i,0,n) a[i]=0;
            vector<int> ch,ass;
            f(i,0,m)
            {
                int te; scan(te);
                a[te-1]=1;
            }
            int job=1;
            f(i,0,n)
            {
                if(a[i])
                    continue;
                else if(job % 2 ==0)
                {ass.push_back(i+1); job++;}
                else 
                { ch.push_back(i+1); job++;}
            }
            f(i,0,ch.size())
                printf("%d ",ch[i]);
            printf("\n");
            f(i,0,ass.size())
                printf("%d ",ass[i]);
            printf("\n");
        }
        return 0;
    }
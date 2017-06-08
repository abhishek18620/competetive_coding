        #include <bits/stdc++.h>
        #define f(o, j, k) for (int o = j; o < k; o++)
        using namespace std;
        const int M=10000;
        int n,m,s;
        vector<int> tr[M];
        bool special[M]; 
        inline void scan(int &x){
            	register int c = getchar_unlocked();
            	x = 0;
            	for(;c<48 || c>57;c=getchar_unlocked());
            	for(;c>47 && c<58;c=getchar_unlocked())
            		x=(x<<1)+(x<<3)+c-48;
            }
        // recursion to check if tree rooted at v can be saved or not 
        bool fun(int v)
        {
            if(special[v]==1)
                return 0;
            else if(tr[v].size()<2)
                return 1;
            else
                return( (fun(tr[v][0]) ) or (fun(tr[v][1])));
        }
         
        int main()
        {
            int t,temp;
            scan(t);
            while(t--)
            {
                scan(n);scan(m);scan(s);
                f(i,0,n)
                {
                    scan(temp);
                    f(j,0,temp)
                    {
                        int t;
                        scan(t);
                        if(--t>i)
                            tr[i].push_back(t);
                        else
                            continue;
                    }
                }
                f(i,0,n)
                    special[i]=0;
                f(i,0,s)
                {
                    scan(temp);
                    special[--temp]=1;
                }
                bool res = fun(--m);
                if(res == 1)
                    cout<<"yes"<<endl;
                else
                    cout<<"no"<<endl;
            f(i,0,n)
                tr[i].clear();
            }
            return 0;
        }  


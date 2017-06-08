    #include <bits/stdc++.h>
    #include <map>
    #define f(i, j, k) for (int i = j; i < k; i++)
    typedef long long uli;
    using namespace std;
     
    map<int , uli> mem;
    uli fun(uli n)
    {
        uli sol=0;
        if(n<12)
            return n;
        else if(mem.find(n) != mem.end())
            return mem[n];
        else
            sol = fun(n/2) + fun(n/3) + fun(n/4);
        mem[n]=sol;
        return sol; 
    }
     
     
    int main()
    {
        ios::sync_with_stdio(false);
        uli n;
        while(cin>>n)
        {
            uli ans = fun(n);
            cout<<ans<<endl;
        }
        return 0;
    } 
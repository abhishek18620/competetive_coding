    #include <bits/stdc++.h>
    typedef long long LLi;
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int m,n;
            LLi charge=0;
            cin>>m>>n;
            while(m--)
            {
                int sp,ti;
                cin>>ti>>sp;
                //charge+=sp*ti;
                if(n-ti >= 0)
                {
                    n-=ti;
                }
                else
                {
                    charge+=sp*(ti-n);
                    n=0;
                }
            }
            cout<<charge<<endl;
        }
        return 0;
    } 
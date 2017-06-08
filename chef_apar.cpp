        #include <bits/stdc++.h>
        #define f1(q, j, k) for (int q = j; q < k; q++)
        using namespace std;
        vector<bool> a;
        main()
        {
            int t;
            cin>>t;
            while(t--)
            {
                int k,late=0;
                long unsigned int due=0; 
                bool temp;
                cin>>k;
                f1(i,0,k)
                {
                    cin>>temp;
                    a.push_back(temp);
                }
                f1(i,0,k)
                {
                    if(a[i]==0)          
                    {   
                        due+=1100; 
                        late++;
                    }
                    else if(late > 0)   
                    {
                        due+=100;
                    }
                    
                }
                a.clear();
                cout<<"\n"<<due;
            }
        }  
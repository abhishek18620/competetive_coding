    #include <bits/stdc++.h>
    #define f(i, j, k) for (int i = j; i < k; i++)
    using namespace std;
    typedef long long li;
     
    int main()
    {
        ios::sync_with_stdio(false);
        int t; cin>>t;
        while(t--)
        {
            int n; cin>>n;
            vector<li> v;
            f(i,0,n)
            {
                li ok; cin>>ok;
                v.push_back(ok);
            }
            
            sort(v.begin() , v.end());
            
            f(i,0,n-1)
            {
                // if 2nd last element reached then the last one must be the culprit
                if(i==n-2)
                {
                    cout<<v[i+1]<<endl;
                    break;
                }
                if(v[i+1] - v[i] != 1)
                {
                    if(v[i+2] - v[i] ==1)
                        cout<<v[i+1]<<endl;
                    else
                        cout<<v[i]<<endl;
                    break;
                }
            }
        }
        return 0;
    } 
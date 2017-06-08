#include <bits/stdc++.h>
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuckrev(i, j, k) for (int i = j; i >= k; i--)
using namespace std;
    
main()
{
    fnf;
    ll t; cin>>t; while(t--)
    {
        ll x11,y11,x12,y12,x21,y21,x22,y22;
        cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;
        bool check =0;
        if(y11==y12)
        {
            if(x11 > x12)
                swap(x11,x12);
            if(y21==y22 and y11==y21)
            {
                if(x21 > x22)
                    swap(x21,x22);
                if((x21<=x12 and x22 >= x12) or (x22>=x11 and x21<=x11) or (x21>=x11 and x22<=x12))
                    check=1;
            }
            else if(x21==x22)
            {
                if(y21 > y22)
                    swap(y21,y22);
                if((x11==x21 and (y11==y21 or y11==y22)) or (x12==x22 and(y11==y21 or y11==y22)))
                    check=1;
                else if(x11==x12 and y11==y12)
                {
                    if(y11>=y21 and y11 <= y22 and x11==x21)
                        check=1;    
                }
            }
        }
        else if(x11==x12)
        {
            if(y11 > y12)
                swap(y11,y12);
            if(x21==x22 and x11==x21)
            {
                if(y21 > y22)
                    swap(y21,y22);
                if((y21<=y12 and y22 >= y12) or (y22>=y11 and y21<=y11) or (y21>=y11 and y22<=y12))
                    check=1;
            }
            else if(y21==y22)
            {
                if(x21 > x22)
                    swap(x21,x22);
                if((y11==y21 and(x11==x21 or x11==x22)) or (y12==y22 and (x11==x21 or x11==x22)))
                    check=1;
            }
        }
        if(!check)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
} 
    #include <bits/stdc++.h>
    typedef long int ll;
    using namespace std;
     
    int main()
    {
    //    ios::sync_with_stdio(false); cin.tie(NULL);
    	ll t; cin>>t;
        while(t--)
    	{
            ll x11,y11,x12,y12,x21,y21,x22,y22;
            cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;
            bool res =0;
            // first snake horizontol
            if(y11==y12)
            {
                if(x11 > x12)
                    swap(x11,x12);
                //second snake horizontol
                if(y21==y22 and y11==y21)
                {
                    if(x21 > x22)
                        swap(x21,x22);
                    if((x21<=x12 and x22 >= x12) or (x22>=x11 and x21<=x11) or (x21>=x11 and x22<=x12))
                        res=1;
                }
                //second snake vertical
                else if(x21==x22)
                {
                    if(y21 > y22)
                        swap(y21,y22);
                    // left corner                                  right corner
                    if((x11==x21 and (y11==y21 or y11==y22)) or (x12==x22 and(y11==y21 or y11==y22)))
                        res=1;
                }
            }
            // first snake vertical
            else if(x11==x12)
            {
                if(y11 > y12)
                    swap(y11,y12);
                //second snake also vertical
                if(x21==x22 and x11==x21)
                {
                    if(y21 > y22)
                        swap(y21,y22);
                    if((y21<=y12 and y22 >= y12) or (y22>=y11 and y21<=y11) or (y21>=y11 and y22<=y12))
                        res=1;
                }
                //second snake horizontol
                else if(y21==y22)
                {
                    if(x21 > x22)
                        swap(x21,x22);
                //    left corner                               right corner
                    if((y11==y21 and(x11==x21 or x11==x22)) or (y12==y22 and (x11==x21 or x11==x22)))
                        res=1;
                }
            }
            if(res)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    	return 0;
    } 


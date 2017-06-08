#include <bits/stdc++.h>
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;
typedef long long li;
string s;
li fun()
{
    int n = s.size();
    li a[n+1];
    a[0]=1;a[1]=1;
    // string temp = s.substr(0,2);
    // if(atoi(temp.c_str()) <= 26)
    //     a[]
    f(i,1,n)
    {
        if(s[i] == '0')
        {
            string t = s.substr(i-1,2);
            int v = atoi(t.c_str());
            if(v <= 26 and v>0)
            {
                a[i+1]=a[i-1];
                if(s[i+1]!='0')
                {
                    i++;a[i+1]=a[i];
                }
                else
                    return 0;
            }
            else
                return 0;

        }
        else
        {
            string t = s.substr(i-1,2);
            int v = atoi(t.c_str());
            if(v <= 26)
                a[i+1]=a[i]+a[i-1];
            else
                a[i+1]=a[i];
        }
    }
    return a[n];
}
int main()
{
    ios::sync_with_stdio(false);
    while( 1 )
    {
        cin>>s;
        if(s[0]!='0')
        {
            li ans = fun();
            cout<<ans<<endl;
        }
        else
            break;
    }
    return 0;
}
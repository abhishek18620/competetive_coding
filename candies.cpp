#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i+=2)
using namespace std;


int main()
{
    //fio;
	int t; cin>>t;
    while(t--)
	{
        int a,b;
        cin>>a>>b;
        int d1=0; int d2=0;
        int lim=0; int bob=0;
        bool l_win=1,b_win=1;
        while(1)
        {
            if(lim > a)
            {
                l_win=0;
                break;
            }
            else
            {
                d1=d2+1;
                lim+=d1;
                if(bob > b)
                {
                    b_win=0;
                    break;
                }
                d2=d1+1;
                bob+=d2;
            }
        }
        if(l_win)
            cout<<"Limak\n";
        else
            cout<<"Bob\n";
    }
    cin>>t;
	return 0;
}
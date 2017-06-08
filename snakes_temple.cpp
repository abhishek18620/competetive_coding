#include <bits/stdc++.h>
#define SIZE 105
#define INF 999999
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
#define fuck(i, j, k) for (int i = j; i < k; i++)
using namespace std;


int main()
{
	fnf;
	int t; cin>>t; 
    while(t--)
	{
        int n; cin>>n;
        int coil[n];
        fuck(i,0,n)
            cin>>coil[i];
        bool sol=1;
        if(n%2==0)
            sol=0;
        else
        {
            int mid=n/2;
            if(coil[mid]!=mid+1)
            {
                sol=0;
            }
            else
            {
                fuck(i,1,mid+1)
                {   
                    if(coil[mid]-coil[mid-i]==i and coil[mid]-coil[mid+i]==i)
                        continue;
                    else
                    {
                        sol=0;
                        break;
                    }
                }
            }
        }
        if(sol)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
	}
    cin>>t;
	return 0;
}
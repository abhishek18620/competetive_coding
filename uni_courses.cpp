#include <bits/stdc++.h>
#define N 100003
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
#define fuck(i, j, k) for (int i = j; i < k; i++)
using namespace std;

int fr[N];
bool bo[N];


int main()
{
	fnf;
    int t; cin>>t;
    while(t--)
	{
        int n; cin>>n;
        fuck(i,0,n)
            bo[i]=1;
        fuck(i,0,n)
            cin>>fr[i];
        fuck(i,1,n)
            bo[fr[i]-1]=0;
        int sol=0,te=0; 
        fuck(i,0,n)
        {
            if(bo[i])
                sol++;
            else if(sol > 0)
                sol=0;
        }
        cout<<sol<<endl;
    }
    cin>>t;
	return 0;
}

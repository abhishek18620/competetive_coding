#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;

int main()
{
    fio;
	int n,m,c;
    cin>>n; cin>>m; cin>>c;
    int hou[n];
    f(i,0,n)
        cin>>hou[i];
    int l=m-2,r=m,st=m-1;
    ll ans =0;
    while(1)
    {
        if(hou[l] <= c and hou[l]!=0 and l>=0)
        {
            ans=10*(st-l);
            break;
        }
        else if(hou[r] <=c and hou[r]!=0 and r<=n-1)
        {
            ans=10*(r-st);
            break;
        }
        l--; r++;
    }
    cout<<ans<<endl;
    // cin>>n;
	return 0;
}
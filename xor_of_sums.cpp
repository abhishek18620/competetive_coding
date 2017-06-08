#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
using namespace std;


int main()
{
    fio;
	int n; cin>>n;
    int a[n];
    ll ans = 0;
    fuck(i,0,n)
    {
        cin>>a[i];
        ans^=a[i];
    }
    fuck(i,0,n)
    {
        int s=a[i];
        fuck(j,i+1,n)
        {
            s+=a[j];
            ans^=s;
        }
    }
    cout<<ans<<endl;
    cin>>n;
	return 0;
}
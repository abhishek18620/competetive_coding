#include <bits/stdc++.h>
#define f(i, j, k) for (int i = j; i < k; i++)
#define ll long long
using namespace std;

int lis(int n,ll a[]){
    int dp[n],lis_value = -1;
    f(i,0,n)
        dp[i] = 1;
    f(i,1,n)
    {
        f(j,0,i)
        {
            if(abs(a[i]) > abs(a[j]) and dp[i] < dp[j]+1)
            {
                if( (a[i]<0 and a[j]>0) or (a[i]>0 and a[j]<0) )
                    dp[i] = dp[j] + 1;
            }
        }
    }
    f(i,0,n)
        if(lis_value < dp[i])
            lis_value = dp[i];
    return lis_value;
}

int main()
{
    ios::sync_with_stdio(false);
    int n; cin>>n;
    ll a[n];
    f(i,0,n)
        cin>>a[i];
    cout<<lis(n,a)<<endl;
    return 0;
}
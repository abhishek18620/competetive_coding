#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false);
typedef unsigned long long ull;
#define fuck(i, j, k) for (ull i = j; i < k; i++)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ull n; cin>>n;
    ull bud[n];
    fuck(i,0,n)
        cin>>bud[i];
    // just sort it
    sort(bud,bud+n);
    ull max_rev=0;
    fuck(i,0,n)
        max_rev=max(max_rev,bud[i]*(n-i));
    cout<<max_rev<<endl;
    cin>>n;
    return 0;
}
#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define test int t; cin>>t; while(t--)
using namespace std;

int main()
{
    ll n;cin>>n;
    if(n==1)
        cout<<"a"<<endl;
    else if(n==2)
        cout<<"aa"<<endl;
    else if(n==3)
    {
        cout<<"abb";
        cout<<endl;
    }
    else
    {
        ll l =n/4;
        f(i,0,l)
            cout<<"abba";
        char a[4]={'a','b','b','a'};
        f(i,0,n-(4*l))
            cout<<a[i];
        cout<<endl;
    }
    cin>>n;
	return 0;
}
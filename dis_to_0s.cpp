#include <bits/stdc++.h>
#define M 200009
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;
//GLOBALS
ll a[M];
vector<ll> zeroes,sol;

int main()
{
    fio;
    ll n;
    cin>>n;
    zeroes.clear();
    sol.clear();
    f(i,0,n)
    {
        cin>>a[i];
        if(a[i] == 0)
            zeroes.push_back(i);
    }
    ll ini=zeroes[0]+1;
    f(i,0,ini)
        sol.push_back(zeroes[0]-i);
    f(i,1,zeroes.size())
    {
        //influence of zeroes[i-1]
        int infl = (zeroes[i]-zeroes[i-1])/2;
        f(j,ini,ini+infl)
        {
            sol.push_back(j-zeroes[i-1]);
        }
        f(j,ini+infl,zeroes[i]+1)
            sol.push_back(zeroes[i]-j);
        ini=zeroes[i]+1;
    }
    ll lst=zeroes[zeroes.size()-1];
    f(i,ini,n)
        sol.push_back(i-lst);
    f(i,0,sol.size())
        cout<<sol[i]<<" ";
    cout<<endl;
	return 0;
}
//SOURCE : gkcs(gaurav sen tutorial)
//prime factorisation(sieve of eratosthenes)(spoj primegenerator :  http://www.spoj.com/problems/PRIME1/)
//total number factors of a number
//greedy choice to find max score
#include <bits/stdc++.h>
#define M 1000005
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i > k; i--)
#define test int t; scan(t); while(t--)
using namespace std;
#define pb push_back

//GLOBALS
ll a,b;
vector<int> prime;
//ll score[sz];
vector<int>pf[M];
bool vis[M];

ll score_calc(ll n)
{
    priority_queue<ll> freq;
    ll te=n,sol=1;
    //prime factorisation
    f(i,0,pf[n-a].size())   //ith factor
    {
        int ctr=0,fact=pf[n-a][i];
        while(te%fact==0)
        {
            te/=fact;
            ctr++;
        }
        freq.push(ctr+1);
        sol*=ctr+1;
    }
    //missed factor
    if(te != 1)
    {
        freq.push(2);
        sol*=2;
    }
    ll curr=sol;
    sol=0;
    while(!freq.empty())
    {
        sol+=curr;
        ll max_freq=freq.top();
        freq.pop();
        if(max_freq >=3)
            freq.push(max_freq-1);
        curr*=(max_freq-1); curr/=max_freq; //number of factors of child(THNX gaurav sen again)
    }
    return sol;
}
int main()
{
    fio;
    cin>>a>>b;
    f(i,0,M)
        vis[i]=0;

    //primes.pb(2); prime.pb(3);
    //sieve of eratosthenes
    f(i,2,M)
    {
		if(!vis[i])
        {
            if(i<3200)
                prime.pb(i);
            vis[i]=1;
            ll first=0;
            if(a%i==0)
                first=a;
            else
                first=i*(a/i)+i;
            for(int j=2*i;j<=M;j+=i)
            {
                if(j-a >=0)
                    pf[j-a].pb(i);
                vis[j]=1;        //mark it visited
            }
        }
    }
    ll final_sol=0;
    f(i,a,b+1)
        final_sol+=score_calc(i);
    cout<<final_sol<<endl;
    cin>>a;
	return 0;
}
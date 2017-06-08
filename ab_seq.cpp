//fucked up my ratings by 100+
//i dont even know what i changed .just added assnd..its n man.. fuck 
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
#define fuck(i,j,k) for(ll i=j;i<=k;++i)
#define fuck_rev(i,j,k) for(ll i=j;i>=k;--i)
using namespace std;
#define test ll t; cin>>t; while(t--)

int main()
{
    fio;
    test
    {
        ll n,m,k;
    	cin>>n>>k;
    	string str;
    	cin>>str;
    	ll ass=str.size()-1;
        ll ctr_a=0;
    	ll ctr_b=0;
    	fuck(i,0,ass)
    	{
    		if(str[i]=='a')
                ++ctr_a;
    		if(str[i]=='b')
                ++ctr_b;
    	}
    	if(ctr_a==0||ctr_b==0)
    	{
            cout<<"0"<<endl;
            continue;
        }
    	ll b[ass+2];
    	fuck(i,0,ass+1)
            b[i]=0;
    	
        ll cnt_b=0;
    	fuck_rev(i,ass,0)
    	{
    		if(str[i]=='b')
                ++cnt_b;
    		if(str[i]=='a')
    		    b[i]=cnt_b;
    	}
    	ll s=0;
    	fuck(i,0,ass)
    	{
            if(str[i]=='a')             // new a encountered
    		{
                ll te=k*b[i]+((k-1)*ctr_b*k)/2;
    			s+=te;
            }
        }
    	cout<<s<<endl;
    }
    cin>>t;
    return 0;
}
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 100009
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(int &x){
		register int c = gc();
		x = 0;
		for(;c<48 || c>57;c=gc());
		for(;c>47 && c<58;c=gc())
			x=(x<<1)+(x<<3)+c-48;
	}

void scanl(ll &x){
		register ll c = gc();
		x = 0;
		for(;c<48 || c>57;c=gc());
		for(;c>47 && c<58;c=gc())
			x=(x<<1)+(x<<3)+c-48;
	}

int main()
{
	fio;
    int n;
	test
	{
        scan(n);
        f(i,1,n+1)
            cin>>a[i];
        bool possible=1,e=1;
        int imp=0,one_imp=0,res=0;
        ll sum=0,ideal=0;
        if(n%2==0)
            ideal=(3*n)/2;
        else
            ideal=(3*n+1)/2;

        f(i,1,n+1)
        {
            sum+=a[i];
            if(e)
            {
                if(a[i]%2!=0)
                {
                    if(a[i]!=1)
                        imp++;
                    else
                        one_imp++;
                }
                e=0;
            }
            else
            {
                e=1;
                if(a[i]%2==0)
                {
                    imp++;
                }
            }
        }
        if(one_imp<imp)
        {
            //if(imp>0 and one_imp>0)
            res+=one_imp;
            imp-=one_imp;
            if(imp%2!=0)
                possible=0;
            else
            {
                res+=imp/2;
            }
        }
        else    //donating case
        {
            //if(imp>0 and one_imp>0)
            res+=imp;
            one_imp-=imp;
            if(one_imp%2!=0)
                possible=0;
            else
            {
                int req=one_imp;
                if(sum>=ideal)
                    res+=req;
                else
                    possible=0;    
            }
        }
        if(possible)
            cout<<res<<endl;
        else
            cout<<"-1"<<endl;
    }
        
    cin>>t;
	return 0;   
}
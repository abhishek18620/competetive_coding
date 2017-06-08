#include <bits/stdc++.h>
#define M 100010
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
char a[2][M];
bool hor[2][M];

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
	//fio;
	test
	{
        ll m; scanl(m);
        string str1,str2;
        cin>>str1>>str2;
        bool ver=0;
        f(i,0,m)
        {
            a[0][i]=str1[i];
            a[1][i]=str2[i];
        }
        //RESTING
        f(i,0,m)
        {
            hor[0][i]=0;
            hor[1][i]=0;
        }
        //PROCESSING
        ll ans=0,st=-1,st_x=-1,st_y=-1,prv=-1;
        bool shi_x=0,shi_y=1,mid=0;
        
        f(i,0,m)
        {
            if(a[0][i]=='*' or a[1][i]=='*')
            {
                st=i;
                if(a[0][i]=='*' and a[1][i]=='*')
                    mid=1;
                break;
            }
        }
        ll save_st=-1;
        f(i,st+1,m)
        {
            save_st=st;
            if(a[0][i]=='*' and a[1][i]=='*')
                mid=1;
            //snake encountered
            if(a[0][i]=='*')
            {
                //last x snak ei s not shielded yet
                if(a[0][st]=='*' and !hor[0][st])
                {
                    hor[0][st]=1;
                    hor[1][st]=1;
                    hor[0][prv]=1;
                    hor[1][prv]=1;
                    ans++;
                }
                else if(a[0][prv]=='*' and !hor[0][prv])
                {
                    hor[0][prv]=1;
                    hor[1][prv]=1;
                    hor[0][st]=1;
                    hor[1][st]=1;
                    prv=st;
                    ans++;
                }
                else if(a[1][st]=='*' and !mid)
                {
                    mid=1;
                    prv=st;
                }
                prv=st;
                st=i;
            }
            if(a[1][i]=='*')
            {
                if(a[0][save_st]=='*' and !mid)
                {
                    mid=1;
                    prv=save_st;
                }
                else if(a[1][save_st]=='*' and !hor[1][save_st])
                {
                    hor[1][save_st]=1;
                    hor[0][save_st]=1;
                    hor[0][prv]=1;
                    hor[1][prv]=1;
                    ans++;
                }
                else if(a[1][prv]=='*' and !hor[0][prv])
                {
                    hor[0][prv]=1;
                    hor[1][prv]=1;
                    hor[0][st]=1;
                    hor[1][st]=1;
                    prv=st;
                    ans++;
                }
                prv=st;
                st=i;
            }
        }
        if(mid)
            ans++;
        cout<<ans<<endl;
    }
    cin>>t;
	return 0;
}
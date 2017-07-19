// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 10000
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
	//fio;
    int len,spaces,i_sp1,i_sp2;
    string s,s1;
	test
	{
        getline(cin,s);
        len=s.length();
        spaces=0;
        i_sp1=i_sp2=-1;
        f(i,0,len)
        {
            if(s[i]==' ')
            {
                spaces++;
                if(i_sp1==-1)
                    i_sp1=i;
                else
                    i_sp2=i;
            }
        }

        if(spaces==0)
        {
            s1.pb(toupper(s[0]));
            f(i,1,len)
            {
                s1.pb(tolower(s[i]));
            }
        }
        else if(spaces==1)
        {
            s1.pb(toupper(s[0]));
            s1.append(". ");
            s1.pb(toupper(s[i_sp1+1]));
            f(i,i_sp1+2,len)
            {
                s1.pb(tolower(s[i]));
            }
        }
        else
        {
            s1.pb(toupper(s[0]));
            s1.append(". ");
            s1.pb(toupper(s[i_sp1+1]));
            s1.append(". ");
            s1.pb(toupper(s[i_sp2+1]));
            f(i,i_sp2+2,len)
            {
                s1.pb(tolower(s[i]));
            }
        }
        cout<<s1<<endl;
        s1.clear();
    }
    cin>>t;
	return 0;
}
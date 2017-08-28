/******************************************
*  Author : elliot   
*  Created On : Sun Aug 20 2017
*  File : palindromic.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 30
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s) 
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

//GLOBALS
struct frequency
{
    char ch;
    int A;
    int B;
}fr[M];

bool duplicateA()
{
    bool possible=0;
    f(i,0,30)
    {
        if(fr[i].A>1 and fr[i].B==0)
        {
            fr[i].A--;
            possible=1;
            break;
        }
    }
    if(possible)
        return 1;
    return 0;
}

bool duplicateB()
{
    bool possible=0;
    f(i,0,30)
    {
        if(fr[i].B>=1 and fr[i].A==0)
        {
            fr[i].B--;
            possible=1;
            break;
        }
    }
    if(possible)
        return 1;
    return 0;
}

bool hold()
{
    bool possible=0;
    f(i,0,30)
    {
        if(fr[i].A>=1 and fr[i].B==0)
        {
            fr[i].A--;
            possible=1;
            break;
        }
    }
    if(possible)
        return 1;
    return 0;
}


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
    	bool neg=0;
		x=0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=0;
    	x = 0;
    	for(;c<48 || c>57;c=gc())
			if(c=='-')
			{
				neg=1;
				c=gc();
				break;
			}
		for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }
int main()
{
    //fio;    
    string strA,strB,str;
    f(i,97,123)
    {
        fr[i-97].ch=char(i);
    }
    test
	{
        f(i,0,M)
        {
            fr[i].A=fr[i].B=0;
        }
        getline(cin,strA);
        getline(cin,strB);
        int lim=strA.length();
        f(i,0,lim)
        {
            fr[int(strA[i])-97].A++;
            fr[int(strB[i])-97].B++;
        }
        
        bool dup=duplicateA();
        if(dup)
            printf("A\n");
        else
        {
            //a holded the game with introducing a char with single freq itself
            // but 0 with b
            if(!hold())
            {
                printf("B\n");
            }
            else
            {
                //A can't hold the game
                if(!duplicateB())
                {
                    printf("A\n");
                }
                else
                {
                    printf("B\n");
                }
            }
        }
    }
    cin>>t;
	return 0;
}

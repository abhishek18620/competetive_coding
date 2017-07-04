// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
//finally
#include <bits/stdc++.h>
#include<stdio.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test ll t; scanl(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

//GLOBALS
string s,s1;

void get_palin(int n)
{
	s1=s;
	int l,r,mid;
	bool nine=1;
	//just checking if its a 9 string
	//otherwise just making a palindrome by l--->r 
	f(i,0,n)
	{
		if(s[i]!='9' and nine)
			nine=0;
	}

	if(nine)
	{
		f(i,0,n)
			s[i]='0';
		s[0]='1';
		s.pb('1');
	}
	else
	{
		f(i,0,n/2)
			s[n-1-i]=s[i];
		//can be equal in case of a palindrome
		if(s<=s1)
		{
			if(n%2==0)
			{
				l=n/2-1;
				r=n/2;
			}
			else
				l=r=n/2;
			f(i,0,n/2+1)
			{
				if(s[l]!='9')
				{
					if(l!=r)
					{
						s[l]++;
						s[r]++;
					}
					else
						s[l]++;
					break;
				}
				else
				{
					s[l]='0';
					s[r]='0';
				}
				l--; r++;
			}
		}
	}
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
		getline(cin,s);
		int n = s.length();
		//CASE 1
		//(already a palindrome)
		//1 9 9 1
		get_palin(n);
		//cout<<"\n"<<s1<<" ----> "<<s<<endl;
		cout<<s<<endl;
	}
	cin>>t;
	return 0;
}
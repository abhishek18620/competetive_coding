#include <bits/stdc++.h>
#define M 1000009
#define INF 999999
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define fuck_rev(i, j, k) for (int i = j; i >= k; i--)
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
	fuck(i,0,n)
	{
		if(s[i]!='9' and nine)
			nine=0;
	}

	if(nine)
	{
		fuck(i,0,n)
			s[i]='0';
		s[0]='1';
		s.pb('1');
	}
	else
	{
		fuck(i,0,n/2)
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
			fuck(i,0,n/2+1)
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

int main()
{
	//fnf;
	ll t; cin>>t;
    while(t--)
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
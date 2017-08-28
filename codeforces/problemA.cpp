/******************************************
*  Author : wshek   
*  Created On : Thu Aug 03 2017
*  File : problemA.cpp
*******************************************/
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

int main()
{
	//fio;
	int n,res=0,caps=0;
	string str1;
	cin>>n;
	getline(cin,str1);
	getline(cin,str1);
	f(i,0,n)
	{
		if(isupper(str1[i]))
		{
			caps++;
		}
		if(str1[i]==' ')
		{
			res=max(caps,res);
			caps=0;
		}
	}
	res=max(caps,res);
	cout<<res<<endl;
	cin>>n;
	return 0;
}

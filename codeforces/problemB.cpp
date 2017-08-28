/******************************************
*  Author : wshek   
*  Created On : Thu Aug 03 2017
*  File : problemB.cpp
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
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;


int main()
{
	fio;
	int n,m;
	string arr[101];
	cin>>n>>m;
	getline(cin,arr[0]);
	f(i,0,n)
		getline(cin,arr[i]);
	bool row=1,column=1;
	char ch=arr[0][0];
	//row
	f(i,1,n)
		if(arr[i][0]!=ch)
		{
			row=0;
			break;
		}
	//row
	f(i,1,m)
		if(arr[0][i]!=ch)
		{
			column=0;
			break;
		}
	
	if(!(row or column))
		cout<<"NO"<<endl;
	else
	{
		map<char,bool> col;
		col['R']=0;
		col['G']=0;
		col['B']=0;
		bool sol=1;
		if(row and !column)
		{
			if(m%3!=0)
			{
				sol=0;
			}
			else
			{
				int nxt=0;
				for(int i=0; i<m;i++)//=m/3)
				{
					if(i==nxt)
					{
						ch=arr[0][i];
						nxt+=m/3;
						if(col[ch])
						{
							sol=0;
							break;
						}
						else
							col[ch]=1;
					}
					f(j,0,n)
					{
						if(arr[j][i]!=ch)
						{
							sol=0;
							break;
						}
					}
					if(!sol)
						break;
				}
			}
		}
		else if(column and !row)
		{
			if(n%3!=0)
			{
				sol=0;
			}
			else
			{
				int nxt=0;
				for(int i=0; i<n;i++)//=n/3)
				{
					if(i==nxt)
					{
						ch=arr[i][0];
						nxt+=n/3;
						if(col[ch])
						{
							sol=0;
							break;
						}
						else
							col[ch]=1;
					}
					
					f(j,0,m)
					{
						if(arr[i][j]!=ch)
						{
							sol=0;
							break;
						}
					}
					if(!sol)
						break;
				}
			}
		}
		else if(row and column)
			sol=0;
		if(sol)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	cin>>n;
	return 0;
}

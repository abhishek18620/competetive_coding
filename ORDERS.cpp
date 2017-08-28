/******************************************
*  Author : abhishek18620   
*  Created On : Sat Aug 12 2017
*  File : ORDERS.cpp
*******************************************/
// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;

int p[200010],arr[200010],soln[200010];

struct node{
   int cnt,value;
   void Merge(node &A,node &B)
   {
	   cnt = A.cnt + B.cnt;
   }
   void CreateLeaf(int c,int v)
   {
	   cnt = c;
	   value = v;
   }
}ST[600010];

void init(int l,int r,int idx)
{
   if(l==r)
   {
	   ST[idx].CreateLeaf(1,p[l]);
	   return;
   }
   int m=(l+r)/2;
   init(l,m,2*idx);
   init(m+1,r,2*idx+1);
   ST[idx].Merge(ST[2*idx],ST[2*idx+1]);
}

int Query(int l,int r,int idx,int x)
{
   if(l==r && ST[idx].cnt==1)
   {
	   return ST[idx].value;
   }
   else
   {
	   int m = (l+r)/2;
	   if(x<=ST[2*idx].cnt)
	   {
		   return Query(l,m,2*idx,x);
	   }
	   else
	   {
		   x-=ST[2*idx].cnt;
		   return Query(m+1,r,2*idx+1,x);
	   }
   }
}


void Update(int l,int r,int idx,int x)
{
   if(l==r)
   {
	   ST[idx].CreateLeaf(0,0);
	   return;
   }
   else
   {
	   int m = (l+r)/2;
	   if(x<=m)
	   {
		   Update(l,m,2*idx,x);
	   }
	   else
	   {
		   Update(m+1,r,2*idx+1,x);
	   }
	   ST[idx].Merge(ST[2*idx],ST[2*idx+1]);
   }
}

int main()
{
   fnf;
	int t,n,i;
   for(i=0;i<200010;i++) p[i]=i;
   cin>>t;
   while(t--){
	   cin>>n;
	   for(i=0;i<n;i++){
		   cin>>arr[i];
	   }
	   init(0,n-1,1);
	   for(i=n-1;i>=0;i--)
	   {
		   soln[i] = Query(0,n-1,1,i+1-arr[i]);
		   Update(0,n-1,1,soln[i]);
	   }
	   for(i=0;i<n;i++)
	   {
		   cout<<soln[i]+1<<" ";
	   }
	   cout<<"\n";
	   
   }
   return 0;
}
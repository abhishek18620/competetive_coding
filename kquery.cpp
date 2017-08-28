/******************************************
*  Author : abhishek18620   
*  Created On : Fri Aug 04 2017
*  File : kquery.cpp
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

//GLOBALS
const int N = 30010;
const int Q = 200010;
int T[N],a[Q];
pair<int,int> p1[N];
 
struct Query
{
    int idx,i,j,k;
}p2[Q];
 
bool sort_cond1(const pair<int,int> &q1,const pair<int,int> &q2)
{
    return q1.F>q2.F;
}
 
bool sort_cond2(const Query &q1,const Query &q2)
{
    return q1.k>q2.k;
}


void write(int n)
{
	if(n<0){n=-n;putchar('-');}
	int i=10;
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
 
 
 
void update(int idx)
{
    while(idx<=N)
    {
        T[idx]+=1;
        idx += (idx & -idx);
    }
}
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum += T[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int query(int l,int r)
{
    return read(r)-read(l-1);
}
 
int main()
{
    fio;
    int n,q,i,j,k;
    scan(n);
    f(i,0,n)
    {
        scan(p1[i].F);
        p1[i].S=i+1;
    }
    scan(q);
    sort(p1,p1+n,sort_cond1);
    f(i,0,q)
    {
        scan(p2[i].i);
        scan(p2[i].j);
        scan(p2[i].k);
        p2[i].idx=i;
        
    }
    sort(p2, p2+q, sort_cond2);
    i=0,j=0;
    while(i<q)
    {
        k=p2[i].k;
        while(j<n && p1[j].F>k)
        {
            update(p1[j].S);
            j++;
        }
        while(i<q && p2[i].k==k)
        {
            a[p2[i].idx]=query(p2[i].i,p2[i].j);
            i++;
        }
    }
    f(i,0,q)
		write(a[i]);
    cin>>n;
	return 0;
}
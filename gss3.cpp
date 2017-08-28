/******************************************
*  Author : abhishek18620   
*  Created On : Mon Aug 28 2017
*  File : gss3.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 70000
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
struct node
{
    int leftsum,rightsum,maxsum,sum;
    void create_node(int x)
    {
        leftsum=rightsum=maxsum=sum=x;
    }
    void merge(node &l , node &r)
    {
        sum=l.sum+r.sum;
        leftsum=max(l.leftsum,l.sum+r.leftsum);
        rightsum=max(r.rightsum,r.sum+l.rightsum);
        maxsum=max(max(l.maxsum,r.maxsum),l.rightsum+r.leftsum);
    }
}seg[M+M+9];

int a[M],n;

void build(int ind,int l,int r)
{
    if(l==r) //leaf node
    {
        seg[ind].create_node(a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(ind<<1,l,mid);
    build(ind<<1|1,mid+1,r);
    seg[ind].merge(seg[ind<<1],seg[ind<<1|1]);
}

void update(int ind,int l,int r,int pos,int val)
{
    if(l==r and l==pos)
    {
        seg[ind].create_node(val);
        return;
    }
    else
    {
        int mid=(l+r)>>1;
        if(pos<=mid)
            update(ind<<1,l,mid,pos,val);
        else
            update(ind<<1|1,mid+1,r,pos,val);
        seg[ind].merge(seg[ind<<1],seg[ind<<1|1]);
    }
}

void query(int ind,node &ans,int l,int r, int u, int v)
{
    if(l==u and r==v)
    {
        ans=seg[ind];
        return;
    }
    int mid=(l+r)>>1;
    if(v<=mid)
        query(ind<<1,ans,l,mid,u,v);
    else if(u>mid)
        query(ind<<1|1,ans,mid+1,r,u,v);
    else
    {
        node left,right;
        query(ind<<1,left,l,mid,u,mid);
        query(ind<<1|1,right,mid+1,r,mid+1,v);
        ans.merge(left,right);
    }
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
    fio;
    scan(n);
    f(i,0,n)
        scan(a[i]);
    build(1,0,n-1);
    int q,c,x,y;
    scan(q);
    f(i,0,q)
    {
        scan(c); scan(x); scan(y);
        if(c==0)
            update(1,0,n-1,x-1,y);
        else
        {
            node ans;
            query(1,ans,0,n-1,x-1,y-1);
            printf("%d\n",ans.maxsum);
        }
    }
    cin>>n;
	return 0;
}

/******************************************
*  Author : abhishek18620   
*  Created On : Tue Aug 29 2017
*  File : lite(lazy_propagation).cpp
*******************************************/
//lazy propagation
#include <bits/stdc++.h>
#define M 300000
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
    int ele;
    void create_node(int x)
    {
        ele=x;
    }
    void merge(node &l , node &r)
    {
        ele=l.ele+r.ele;
    }
}seg[M+M];
bool lazy[M+M];
void build(int ind,int l,int r)
{
    if(l==r)
    {
        seg[ind].create_node(0);
        return ;
    }
    int mid=(l+r)>>1;
    build(ind<<1,l,mid);
    build(ind<<1|1,mid+1,r);
    seg[ind].merge(seg[ind<<1],seg[ind<<1|1]);
}

void update(int ind,int l,int r,int u,int v)
{
    //changes needs to be propagated from this node
    if(lazy[ind])
    {
        //total-already on
        seg[ind].ele=(r-l+1)-seg[ind].ele;
        if(l!=r)
        {
            lazy[ind<<1]=!lazy[ind<<1];
            lazy[ind<<1|1]=!lazy[ind<<1|1];
        }
        lazy[ind]=0;
    }
    if(v<l or u>r)
        return;
    if(l>=u and r<=v)
    {
        seg[ind].ele=(r-l+1)-seg[ind].ele;
        if(l!=r)
        {
            lazy[ind<<1]=!lazy[ind<<1];
            lazy[ind<<1|1]=!lazy[ind<<1|1];
        }
        lazy[ind]=0;
        return;
    }
    int mid=(l+r)>>1;
    update(ind<<1,l,mid,u,v);
    update(ind<<1|1,mid+1,r,u,v);
    seg[ind].merge(seg[ind<<1],seg[ind<<1|1]);
}

void query(node &ans,int ind,int l,int r,int u,int v)
{
    if(lazy[ind])
    {
        //total-already on
        seg[ind].ele=(r-l+1)-seg[ind].ele;
        if(l!=r)
        {
            lazy[ind<<1]=!lazy[ind<<1];
            lazy[ind<<1|1]=!lazy[ind<<1|1];
        }
        lazy[ind]=0;
    }
    if(l==u and r==v)
    {
        ans=seg[ind];
        return;
    }
    int mid=(l+r)>>1;
    if(v<=mid)
        query(ans,ind<<1,l,mid,u,v);
    else if(u>mid)
        query(ans,ind<<1|1,mid+1,r,u,v);
    else
    {
        node left,right;
        query(left,ind<<1,l,mid,u,mid);
        query(right,ind<<1|1,mid+1,r,mid+1,v);
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
    int n,m,u,v,c;
    scan(n); scan(m);
    build(1,0,n-1);
    memset(lazy,0,sizeof(lazy));
    node ans;
    f(i,0,m)
    {
        scan(c); scan(u); scan(v);
        if(c==0)
            update(1,0,n-1,u-1,v-1);
        else
        {
            query(ans,1,0,n-1,u-1,v-1);
            printf("%d\n",ans.ele);
        }
    }
    cin>>n;
    return 0;
}

/******************************************
*  Author : abhishek18620   
*  Created On : Wed Aug 23 2017
*  File : gss1.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 40
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
#define MID(x,y) (x+((y-x)/2))
using namespace std;

//GLOBALS
int n,q,u,v,a[M];

struct node
{
    ll leftsum,rightsum,sum,maxsum;
    void create_node(int x)
    {
        leftsum=rightsum=sum=maxsum=x;
    }
    void merge(node &l , node &r)
    {
        leftsum=max(l.leftsum,l.sum+r.leftsum);
        rightsum=max(r.rightsum,r.sum+l.rightsum);
        sum=l.sum+r.sum;
        maxsum=max(max(l.maxsum,r.maxsum),l.rightsum+r.leftsum);
    }
    void _merge(node &l , node &r)
    {
        leftsum=max(l.leftsum,l.sum+r.leftsum);
        rightsum=max(r.rightsum,r.sum+l.rightsum);
        sum=l.sum+r.sum;
        maxsum=max(max(l.maxsum,r.maxsum),max(max(leftsum,rightsum),l.rightsum+r.leftsum));
        //maxsum=max(max(leftsum,rightsum),l.rightsum+r.leftsum);
    } 
}seg[M+M];

void build()
{
    node de;
    for(int i=n-1;i>0;--i)
    {
        int l=i<<1;
        int r=i<<1|1;
        seg[i].merge(seg[i<<1],seg[i<<1|1]);
        de=seg[i];
    }
}
//[l,r)
// node query(int l,int r)
// {
//     node ok,te;
//     ok.create_node(0);
//     for(l+=n,r+=n; l<r; l>>=1,r>>=1)
//     {
//         if(l&1)
//         {
//             te=seg[l++];
//             ok._merge(te,query(l,r));
//         }
//         if(r&1)
//         {
//             te=seg[--r];
//             ok._merge(query(l,r),te);
//         }
//     }
//     return ok;
// }

// node query(int l ,int r)
// {
//     node res,resl,resr,te;
//     resl.create_node(-99999999);
//     resr.create_node(-99999999);
//     if(l==r)
//     {
//         //resl.create_node(-999);
//         return resl;
//     }
//     if(l&1)
//     {
//         te=query(l+1,r);
//         //l++;
//         resl._merge(seg[l],te);
//     }
//     if(r&1)
//     {
//         //--r;
//         te=query(l,r-1);
//         resr._merge(te,seg[r-1]);
//     }
//     if(!(l&1 or r&1))
//     {    
//         l>>=1;
//         r>>=1;
//         return query(l,r);
//     }
//     return resl.maxsum>=resr.maxsum?resl:resr;
// }

//index = node which covers [l,r]
//u and v = our querying range
// l,r = our editable range
void query(node& result,int l,int r,int u,int v,int index)
{
    if(u==l && v==r)
        {
            result=seg[index];
            return;
        }
    else
    {
        int mid=MID(l,r);
        //our query range lies in left of mid
        if(mid>=v)
            query(result,l,mid,u,v,2*index);
        //pur query range lies in right of mid
        else if(mid<u)
            query(result,mid+1,r,u,v,2*index+1);
        //partial overlap
        else
        {
            node left,right;
            query(left,l,mid,u,mid,2*index);
            query(right,mid+1,r,mid+1,v,2*index+1);
            result.merge(left,right);
        } 
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
    //fio;
    scan(n);
    f(i,0,n)
        scan(a[i]);
    
    f(i,0,n+n+1)
        seg[i].create_node(-1*INF );
    f(i,0,n)
        seg[i+n].create_node(a[i]);
    build();    
    scan(q);    
    node ans;
    while(q--)
    {
        scan(u); scan(v);
        u--; v--;
        query(ans,0,n-1,u-1,v-1,1);
        printf("%lld\n",ans.maxsum);
    }
    cin>>n;
    //sum(i,j)=sum[j]-sum[i-1]
    return 0;
}

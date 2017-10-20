//BINARY INDEXED TREE (BIT)
/******************************************
*  Author : abhishek18620   
*  Created On : Thu Oct 19 2017
*  File : coders_rating.cpp
*******************************************/
#include <bits/stdc++.h>
#define M 300009
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

int n,sol[M],bit[100009];

struct coder
{
    int a,b,ind;
}a[M];

// template <typename K>
bool comp(const coder &lhs, const coder &rhs)
{
    if(lhs.a==rhs.a)
        return lhs.b < rhs.b;
    return lhs.a<rhs.a;
}

void update(int y)
{
    while (y<=100000 )
    {
        bit[y]+=1;
        y+=(y&-y);
    }
}

int read(int y) 
{
    int res=0;
    while (y>0) 
    {
        res+=bit[ y ];
        y-=(y&-y);
    }
    return res;
}

void writel(int n)
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
int main()
{
    //fio;
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
    #endif
    scan(n);
    f(i,0,n)
    {
        scan(a[i].a);
        scan(a[i].b);
        a[i].ind=i;
    }
    sort(a,a+n,comp);
    sol[a[0].ind]=0;
    update(a[0].b);
    int idx,prvidx;
    f(i,1,n)
    {
        idx=a[i].ind;
        prvidx=a[i-1].ind;
        if(a[i].b != a[i-1].b or a[i].a!=a[i-1].a)   //ith coder ith is better than i-1th
            sol[idx]=read(a[i].b);
        else
            sol[idx]=read(a[i].b)-1;
        update(a[i].b);
    }
    f(i,0,n)
        writel(sol[i]);

    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

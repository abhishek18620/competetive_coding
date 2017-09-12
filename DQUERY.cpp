/******************************************
*  Author : abhishek18620   
*  Created On : Thu Aug 31 2017
*  File : DQUERY.cpp
*******************************************/
//THANKS TO ANUDEEP'S BLOG AND HIS GITUB CODE HELPS IN INPUT LIMITS TOO
#include <bits/stdc++.h>
#define M 300099
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
const int block=sqrt(M);
int a[M],frq[1000009],sol[M],n,q,ans=0;

struct query
{
    int l,r,i;
}que[M];

bool comparator(const query& lhs, const query& rhs)
{
    if(lhs.l/block != rhs.l/block)
        //lies in differnt blocks
        return lhs.l/block < rhs.l/block;
    //same blocks
    return lhs.r < rhs.r;
}

void add(int idx)
{
    frq[a[idx]]++;
    if(frq[a[idx]]==1)
        ans++;
}

void remove(int idx)
{

    if(frq[a[idx]]==1)
        ans--;
    frq[a[idx]]--;
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
    scanf("%d",&n);
    f(i,0,n)
        scanf("%d",a+i);
    scanf("%d",&q);
    f(i,0,q)
    {
        scanf("%d%d",&que[i].l,&que[i].r);
        //scan(que[i].r);
        que[i].i=i;
    }
    sort(que,que+q,comparator);
    int cur_l=0,cur_r=0,l,r;
    f(i,0,q)
    {
        l=que[i].l-1;
        r=que[i].r-1;
        //need to increment cur_l
        while(cur_l<l)
        {
            remove(cur_l);
            cur_l++;
        }
        //need to decrement cur_l
        while(cur_l>l)
        {
            cur_l--;
            add(cur_l);
        }
        //need to increment cur_r
        //should be run till both rs gets to the rightmost of our query
        // a cur_r is a step ahead of our already calculted range
        while(cur_r<=r)
        {
            add(cur_r);
            cur_r++;
        }
        //need to decrement cur_r 
        while(cur_r>r+1)
        {
            cur_r--;
            remove(cur_r);
        }
        sol[que[i].i]=ans;
    }
    f(i,0,q)
        printf("%d\n",sol[i]);
    cin>>n;    
	return 0;
}

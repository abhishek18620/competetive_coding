#include <bits/stdc++.h>
#define M 100009
#define INF 1e12
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
using namespace std;

ll a[M],sum[M],n;

ll cost_calc(ll right , ll left)
{
    if(left==12 and right==4)
    {
        bool flag=1;
        int def=1;
    }
    ll mid=right+(left-right)/2;
    ll x=mid-right;
    ll te=(x+1)*(x+1);
    ll cost=sum[n]-te;
    return cost;
}

ll fun(ll right,ll left,ll ptr)
{
    ll tot=left-right+1;
    if(tot%2==0)//even number of hs
    {
        ll con1=right+tot/2 -1;
        ll con2=con1+1;
        if(a[con1]>a[con2])
            left--;
        else if(a[con1]<a[con2])
            right++;
        else
        {
            if(a[right]>a[left])
                left--;
            else if(a[right]<=a[left])
                right++;
        }
        tot--;
    }
    ll peak=tot/2+1;
    ptr=right;
    ll mid=right+(left-right)/2;
    // if(right!=0)
    //     mid++;
    ll cost=INF,prv_cost=INF;
    while(ptr<=left)
    {
        ll ideal=(peak)-abs(ptr-mid);
        if(a[ptr]>=ideal)
        {
            ptr++;
            continue;
        }
        else //need to increase
        {
            ll diff=ideal-a[ptr];
            cost=min(cost,cost_calc(right,ptr-1));
            // if(cost < prv_cost)
            //     prv_cost=cost;
            // else
            //     cost=prv_cost;
            right=ptr;
            // tot=left-right+1;
            // peak=tot/2;
            // update(tot,left,right,ptr,mid);
            cost=min(cost,fun(ptr,left,ptr));//right shift
            cost=min(cost,fun(right,left-diff,ptr));//left shift
        }
        ptr++;
    }
    ll te=cost_calc(right,left);
    if(te<cost)
    {
        cost=te;
        prv_cost=te;
    }
    return cost;
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
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	fast;
	int t; scan(t);
    while(t--)
	{
        scanl(n);
        f(i,0,n)
            scanl(a[i]);
        sum[0]=0;
        f(i,1,n+1)
            sum[i]=sum[i-1]+a[i-1];
        ll right=0,left=n-1;
        ll ptr=0;
        ll cost=fun(right,left,ptr);
        writel(cost);
    }
    //     ll tot=left-right+1;
    //     ll peak=tot/2;
    //     if(tot%2==0)//even number of hs
    //     {
    //         if(a[right]>a[left])
    //             left--;
    //         else
    //             right++;
    //         tot--;
    //     }
    //     ll ptr=right;
    //     ll mid=right+(left-right)/2;
    //     ll cost=INF,prv_cost=INF;
    //     while(ptr<=left)
    //     {
    //         ll ideal=(peak)-abs(ptr-mid);
    //         if(a[ptr]>=ideal)
    //         {
    //             ptr++;
    //             continue;
    //         }
    //         else //need to increase
    //         {
    //             ll diff=ideal-a[ptr];
    //             if(ptr<=mid)//shift right by diff
    //             {
    //                 //cost+=0;
    //                 cost=cost_calc(right,ptr-1);
    //                 if(cost < prv_cost)
    //                     prv_cost=cost;
    //                 else
    //                     cost=prv_cost;
    //                 right=ptr;
    //                 tot=left-right+1;
    //                 peak=tot/2;
    //                 update(tot,left,right,ptr,mid);
    //             }
    //             else if(ptr>mid)//shift left by diff
    //             {
    //                 cost=cost_calc(right,ptr-1);
    //                 if(cost < prv_cost)
    //                     prv_cost=cost;
    //                 else
    //                     cost=prv_cost;
    //                 left-=diff;
    //                 tot=left-right+1;
    //                 peak=tot/2;
    //                 update(tot,left,right,ptr,mid);
    //                 break;
    //             }
    //         }
    //         ptr++;
    //     }
    //     cost=cost_calc(left,right);
    //     if(cost < prv_cost)
    //         prv_cost=cost;
    //     else
    //         cost=prv_cost;
    //     cout<<cost<<endl;
	// }
    cin>>t;
	return 0;
}
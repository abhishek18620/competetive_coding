///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Sat Sep 16 2017               //
///////////////////////////////////////////
#include <bits/stdc++.h>
#define SZ 100
#define INF 1e17
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef unsigned long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
using namespace std;

//GLOBALS
int n;
vector<int> a;
// bool rec(int l, int r,int sz)
// {
//     if(sz==1)
//         return 1;
//     int check=*(max_element(a+l,a+r)); 
//     int mid=floor((sz-1)/2);
//     if(check==a[mid])
//     {
//         a[mid]=-1;
//         ans&=rec(l,mid-1,)&&(rec(mid+1));
//     }
//     else
//         return 0;
// }

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("./kickstart/A-large.in","r",stdin);
	freopen("./kickstart/output.txt","w",stdout);
    #endif
    int t; scan(t);
    int tt=1;
    while(t--)
    {
        scan(n);
        int te;
        f(i,0,n)
        {
            scan(te);
            a.eb(te);
        }
        bool ans=1;
        int sz=n;
        while(sz>1)
        {
            int mid=floor((sz-1)/2);
            int check1=*(max_element(a.begin(),a.end()));
            int check2=*(min_element(a.begin(),a.end()));
            if(check1==a[mid] or check2==a[mid])
            {
                a.erase(a.begin()+mid);
                sz--;
            }
            else
            {
                ans=0;
                break;
            }
        }
        if(ans)
            printf("Case #%d: YES\n",tt++);
        else
           printf("Case #%d: NO\n",tt++);
        a.clear();
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
    #endif
    return 0;
}

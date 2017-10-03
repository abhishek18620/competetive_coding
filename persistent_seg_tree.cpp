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
#define printl(x) printf("%lld\n",x)ne
using namespace std;

struct node
{
    int ele;
    node  *left,*right;
    node(int cnt, node * left,node * right)
    {
        ele=cnt;
        left=left;
        right=right;
    }
};

node *null=new node(0,NULL,NULL); 

int main()
{
    #ifdef LOCAL_DEFINE
    clock_t tStart = clock();
    freopen("input.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    // int t; scan(t);
    // while(t--)
    // {
        
    // }
    int n,q,u,v,val,a[n+1];
    scan(n); scan(q);
    f(i,0,n)
        scan(a[i]);
    
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int m;
        cin>>m;
    #endif
    return 0;
}

//HEAPSORT

///////////////////////////////////////////
//  Author : abhishek18620               //
//  Date : Thu Nov 16 2017                       //
///////////////////////////////////////////
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
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
#define viter(s) for (auto it: s)
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
#define eb emplace_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using namespace std;

void heapify(int a[], int i, int n) //heapify till i to n
{
    int l=i*2;  //left child
    int r=i*2+1; //right child
    int largest=i;
    if(l<=n and a[l]>a[i])
        largest=l;
    if(r<=n and a[r]>a[largest])
        largest=r;
    
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,largest,n);
    }
}

void build_heap(int a[], int n)
{
    for(int i=n/2;i>=1;i--)
        heapify(a,i,n);
}

void heapsort(int a[] , int n)
{
    build_heap(a,n);    //initial heap means max element must be on root
    for(int i=n;i>=2;i--)
    {
        swap(a[i],a[1]);
        heapify(a,1,i-1);
    }

}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int n; scan(n);
    int a[n+1];
    f(i,1,n+1)
        scan(a[i]);
    
    heapsort(a,n);
    f(i,1,n+1)
        cout<<a[i]<<" ";
    cout<<endl;
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

    #include <bits/stdc++.h>
    using namespace std;
     
    #define all(v) v.begin(), v.end()
    #define mp                    make_pair
    #define pb                    push_back
    #define clr(ara)              memset(ara, 0, sizeof(ara))
    #define dp(ara)            memset(ara, -1, sizeof(ara))
    #define White                 0
    #define Grey                  1
    #define Black                 2
     
    #define sf                    scanf
    #define pf                    printf
     
    #define Test_Case(a)             for(int cs = 1; cs <= t; cs++)
    #define REP(i, a, b)      for(int i=a;i<=b;i++)
    #define loop(i,n)       for(int i=0;i<n;i++)
     
    #define READ                  freopen("input.txt", "r", stdin);
    #define WRITE                 freopen("output.txt", "w", stdout);
     
    int fx[] = { -1, 1, 0, 0 };
    int fy[] = { 0, 0, -1, 1 };
     
    int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
     
    int kx[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; // Knight Moves.
    int ky[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
     
    typedef  long long            ll;
     
    typedef  map <int,int>	           mii;
    typedef  map <int,string>	       mis;
    typedef  map <ll, ll>              mll;
    typedef  map <char,int>            mci;
    typedef  map <string,int>          msi;
    typedef  map <string, string>      mss;
     
    typedef  pair <int,int> 	       pii;
    typedef  pair <ll, ll>             pll;
    typedef  pair <char,int>           pci;
    typedef  pair <string,int>         psi;
    typedef  pair <string, string>     pss;
     
    typedef  vector<int> 	           vi;
    typedef  vector<string> 	       vs;
    typedef  vector<char>	           vc;
    typedef  vector<bool>              vb;
    typedef  vector < pii>             vii;
     
    bool cmp(const pii &a, const pii &b)
    {
        return a.first < b.first;
    }
     
    #define SizeN 1010
    int status[SizeN/2], prime[1000];
    int num[100010];
     
    vector <int> tree[100010*4];
     
    void seive()
    {
        int rt = (int)sqrt((double)SizeN)+1;
        for(int i = 3; i <= rt; i += 2)
        {
            if(status[i>>1] == 0)
            {
                for(int j = i*i; j <= SizeN; j += i+i)
                {
                    status[j>>1] = 1;
                }
            }
        }
     
        int indx = 0;
        prime[indx++] = 2;
        for(int i = 3; i <= SizeN; i += 2)
        {
            if(status[i>>1] == 0)
            {
                prime[indx++] = i;
            }
        }
    }
     
    int x, y;
     
    void build(int node, int b, int e)
    {
        if(b == e)
        {
            int n = num[b];
            int rt = int( sqrt((double) n)) + 1;
            int c = n;
     
            for(int i = 0; prime[i] <= rt; i++)
            {
                if(n % prime[i] == 0)
                {
     
                    while(n % prime[i] == 0)
                    {
                        tree[node].pb(prime[i]);
                        n /= prime[i];
                    }
     
                    rt = sqrt((double)n)+1;
                }
            }
     
            if(n > 1)
            {
                tree[node].pb(n);
            }
     
            return;
        }
     
        int mid = (b+e) >> 1;
        int left = node << 1;
        int right = left | 1;
     
        build(left, b, mid);
        build(right, mid+1, e);
     
        merge(all(tree[left]), all(tree[right]), back_inserter(tree[node]));
        return;
     
    }
     
    int query(int node, int b, int e, int i, int j)
    {
        if(b > j || i > e)
            return 0;
     
        if(b >= i && e <= j)
        {
            int up = upper_bound(all(tree[node]), y) - tree[node].begin();
            int low = lower_bound(all(tree[node]), x) - tree[node].begin();
     
            up -= low;
     
            return up;
        }
     
        int mid = (b+e) >> 1;
        int left = node << 1;
        int right = left | 1;
     
        return query(left, b, mid, i, j) + query(right, mid+1, e, i, j);
    }
     
    int main()
    {
        seive();
     
        int n;
        sf("%d", &n);
     
        loop(i, n)
        {
            sf("%d", &num[i+1]);
        }
     
        build(1, 1, n);
     
        int q;
        sf("%d", &q);
     
        while(q--)
        {
            int l, r;
            sf("%d %d %d %d", &l, &r, &x, &y);
     
            int ans = query(1, 1, n, l, r);
     
            pf("%d\n", ans);
        }
     
        return 0;
    }
     
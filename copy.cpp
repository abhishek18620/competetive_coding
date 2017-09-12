#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i < k; i++)
using namespace std;

const long long MOD=1e9+7;
int m,n,k,u,v,diff;
int GR[500][500];
vector<int> subset;

unsigned long long add_modulo(unsigned long long &a,unsigned long long &b)
{
    unsigned long long ret=((a%MOD)+b)%MOD;
    return ret;
}

long long subsets()
{
    long long max_sz = 1<<n;
    int ctr;
    unsigned long long sol=0;
    rep(i,0,max_sz)
    {
        rep(j,0,n)
        {
            if(i&(1<<j))
                subset.emplace_back(j);
        }
        ctr=0;
        int lim=subset.size();
        rep(i,0,lim)
        {
            rep(j,i,lim)
            {
                if(GR[subset[i]][subset[j]]==diff)
                    ctr++;
            }
        }
        unsigned long long te=pow(ctr,k);
        sol=add_modulo(sol,te);
        subset.clear();
    }
    return sol;
}

int main()
{
    diff=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        diff++;
        scanf("%d %d %d" ,&n,&m,&k);
        rep(i,0,m)
        {
            scanf("%d %d",&u,&v);
            u--; v--;
            GR[u][v]=GR[v][u]=diff;
        }
        printf("%lld\n",subsets());
    }
    cin>>t;
	return 0;
}

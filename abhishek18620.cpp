#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define scan(d) scanf("%d", &d)

const int M = 10;

int n,a[M],b[M],frq[M+2][2];
vector<int> loners;

bool find(int ind)
{
    int ele=a[ind];
    bool find=0;
    FOR(i,0,n)
    {
        if(a[i]!=ele)
        {
            swap(a[i],a[ind]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scan(t);
    // FOR(i,0,M+2)
    //     frq[i][0]=frq[i][1]=-1;
    while(t--)
    {
        memset(frq,-1,sizeof(frq));
        scan(n);
        int dist=0,pairs=0;
        int lim=0;
        FOR(i,0,n)
        {
            scan(a[i]);
            if(frq[a[i]][0]==-1)
                frq[a[i]][0]=i;
            else
                frq[a[i]][1]=i;
            lim=max(a[i],lim);
        }
        pair<int,int> lst=mp(-1,-1);
        FOR(i,1,lim+1)
        {
            if(frq[i][0]!=-1)
            {
                if(frq[i][1]!=-1)   //pairs
                {
                    if(lst.F!=-1)   //ready to swap
                    {
                        swap(a[lst.F],a[frq[i][0]]);
                        swap(a[lst.S],a[frq[i][1]]);
                        lst=mp(-1,-1);
                    }
                    else
                    {
                        lst=mp(frq[i][0],frq[i][1]);
                    }
                }
                else    //singletons
                    loners.emplace_back(frq[i][0]);
            }
        }
        int sz=loners.size();
        int score=n;
        if(sz>=2)
        {
            int ini=0,end=sz-1;
            if(lst.F!=-1)
            {
                swap(a[loners[0]],a[lst.F]);
                swap(a[loners[1]],a[lst.S]);
                ini=2;
            }
            if(sz%2!=0)
                end=sz-2;
            FOR(i,ini,end)
            {
                swap(a[loners[i]],a[loners[i+1]]);
                i++;   
            }
            if(sz%2!=0) //odd loners
            {
                if(!find(loners[sz-1]))
                    score--;
            }
        }
        else if(sz==1)
        {
            if(lst.F!=-1)
            {
                swap(a[loners[0]],a[lst.F]);
                if(!find(lst.S))
                    score--;
            }
            else if(!find(loners[0]))
                score--;
            if(n==3)
                score--;
        }
        else
        {
            if(lst.F!=-1 and !find(lst.F))
                    score--;
            if(lst.S!=-1 and !find(lst.S))
                    score--;
        }
        printf("%d\n",score);
        FOR(i,0,n)
            printf("%d ",a[i]);
        printf("\n");
        loners.clear();
    }
    assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<3.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>n;
    #endif
    return 0;
}

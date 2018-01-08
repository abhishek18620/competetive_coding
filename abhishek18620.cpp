#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sol[1000009];

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; scanf("%d",&t);
    while(t--)
    {
        int x,n; scanf("%d %d",&x,&n);
        memset(sol,0,sizeof(int)*(n+2));
        sol[x]=2;
        ll sum=(1ll*n*(n+1))>>1;
        sum-=x;
        if(sum&1)
        {
            printf("impossible\n");
            continue;
        }
        sum>>=1;
        ll currsum=0;
        bool poss=1;
        for(int i=n;i>=1;i--)
        {
            if(currsum+i<=sum)
            {
                if(i==x) continue;
                sol[i]=1;
                currsum+=i;
            }
            else
            {
                if(i>sum-currsum)
                {
                    if(sum-currsum==x)
                    {
                        if(x==1)
                        {
                            if(i<=2)
                                poss=0;
                            sol[i+1]=0;
                            sol[i]=sol[2]=1;
                            break;
                        }
                        else if(x==2)
                        {
                            if(i<=3)
                                poss=0;
                            sol[i+1]=0;
                            sol[i]=sol[3]=1;
                            break;
                        }
                        else
                            continue;
                    }
                    sol[sum-currsum]=1;
                    break;
                }
            }
        }
        if(!poss)
        {
            printf("impossible\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d",sol[i]);
        }
        printf("\n");
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>t;
    #endif
    return 0;
}

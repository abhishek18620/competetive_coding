#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void ordering(int &f, int &g, int &h)   //f < g < h
{
    int temp=min(f,min(g,h));
    if(temp==g)
        swap(f,g);
    else if(temp==h)
        swap(f,h);
    
    if(g>h)
        swap(g,h);
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int x,y,z,a,b,c;
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);
        ll sol=0;
        char AB,AC,ABC;
        if(2*a <= b)
            AB='A';
        else
            AB='B';
        if(3*a <= c)
            AC='A';
        else
            AC='C';
        if(b+a >= c)
            ABC='C';
        else
            ABC='O';
        ordering(x,y,z);
        ll sol1=0;
        if(AB=='A')
        {
            // prefer a over b but can i use c ?
            if(AC=='A')
            {
                sol1=(x+y+z)*1ll*a;
            }
            else    //can use c over a
            {
                //ordering(x,y,z);    // x < y < z
                sol1=x*1ll*c;    // y=y-x < z=z-x
                sol1+=(y-x+z-x)*1ll*a;
            }
        }
        else
        {
            // prefer b over a but can i use c over b ?
            ll te1=0,te2=0;
            //ordering(x,y,z);
            te1=x*1ll*c;
            te1+=(y-x)*1ll*b+(z-y)*1ll*a;
            
            // prefer a and b over c
            //ordering(x,y,z);
            int sum=x+y+z;
            te2=(sum/2)*1ll*b+(sum%2)*1ll*a;
            sol1=min(te1,te2);
        }


        ll sol2=0;
        if(AC=='A')
        {
            //prefer a over c but can i use b ?
            if(AB=='A')// no you can't
            {
                sol2=(x+y+z)*1ll*a;
            }
            else    // yes you can use B
            {
                int sum=x+y+z;
                sol2=(((sum/2)*1ll*b)+((sum%2)*1ll*a));
            }
        }
        else
        {
            // prefer c over a but can i use b ?
            if(ABC=='C')    // GOD's order : use c ;)
            {
                ll te1=0,te2=0;
                te1=x*1ll*c;   // y=y-x < z=z-x
                if(AB=='A')
                {
                    te1+=(y-x+z-x)*1ll*a;
                }
                else
                {
                    te1+=(y-x)*1ll*b + (z-y)*1ll*a;
                }
                int sum=x+y+z;
                te2=(sum/2)*1ll*b+(sum%2)*1ll*a;
                sol2=min(te1,te2);
            }
            else
            {
                // prefer a and b over c
                if(AB=='A')
                {
                    sol2=(x+y+z)*1ll*a;
                }
                else
                {
                    int sum=x+y+z;
                    sol2=(sum/2)*1ll*b+(sum%2)*1ll*a;
                }
            }
        }
        sol=min(sol1,sol2);
        printf("%lld\n",sol);
    }
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        int n;
        cin>>n;
    #endif
    return 0;
}

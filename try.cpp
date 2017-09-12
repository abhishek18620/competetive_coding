#include <bits/stdc++.h>
#define M 1000009
using namespace std;

struct move
{
    int l,r,val;
}moves[M];

int A[M],b[M],n,q,u,v,val,ctr;

bool rec(int idx)
{
    if(idx==q)
        return 1;
    int prv1=-1,prv2=-1;
    int u=moves[idx].l;
    int v=moves[idx].r;
    int diff=moves[idx].val;
    bool sol1=0,sol2=0;
    if(diff==1)
    {
        //(0,1) or (1,0)
        prv1=A[u]; prv2=A[v];
        //both are unset
        if(b[u]!=ctr and b[v]!=ctr)
        {
            A[u]=0; A[v]=1;
            b[u]=ctr; b[v]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                //b[u]=b[v]=-1*ctr;
                //A[u]=prv1; A[v]=prv2;
                A[u]=1; A[v]=0;
                sol2=rec(idx+1);
                if(!sol2)
                {
                    //revert changes
                    b[u]=b[v]=-1*ctr;
                    A[u]=prv1; A[v]=prv2;
                    return 0;
                }
            }
        }
        // if one of em is set
        else if(b[u]==ctr and b[v]!=ctr)
        {
            if(A[u]==1)
                A[v]=0;
            else
                A[v]=1;
            b[v]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                A[v]=prv2;
                b[v]=-1*ctr;
                return 0;
            }
        }
        // if one of em is set
        else if(b[u]!=ctr and b[v]==ctr)
        {
            if(A[v]==1)
                A[u]=0;
            else
                A[u]=1;
            b[u]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                A[u]=prv2;
                b[u]=-1*ctr;
                return 0;
            }
        }
        //if both are set
        else
        {
            if(A[u]!=A[v])
                return rec(idx+1);
            return 0;
        }
    }
    else
    {
        //(0,0) or (1,1)
        prv1=A[u]; prv2=A[v];
        //both are unset
        if(b[u]!=ctr and b[v]!=ctr)
        {
            A[u]=1; A[v]=1;
            b[u]=ctr; b[v]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                //b[u]=b[v]=-1*ctr;
                //A[u]=prv1; A[v]=prv2;
                A[u]=0; A[v]=0;
                sol2=rec(idx+1);
                if(!sol2)
                {
                    //revert changes
                    b[u]=b[v]=-1*ctr;
                    A[u]=prv1; A[v]=prv2;
                    return 0;
                }
            }
        }
        // if one of em is set
        else if(b[u]==ctr and b[v]!=ctr)
        {
            if(A[u]==1)
                A[v]=1;
            else
                A[v]=0;
            b[v]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                A[v]=prv2;
                b[v]=-1*ctr;
                return 0;
            }
        }
        // if one of em is set
        else if(b[u]!=ctr and b[v]==ctr)
        {
            if(A[v]==1)
                A[u]=1;
            else
                A[u]=0;
            b[u]=ctr;
            sol1=rec(idx+1);
            if(!sol1)
            {
                //revert changes
                A[u]=prv2;
                b[u]=-1*ctr;
                return 0;
            }
        }
        //if both are set
        else
        {
            if(A[u]==A[v])
                return rec(idx+1);
            return 0;
        }
    }
    return (sol1||sol2);
}

int main()
{
    ctr=0;
    freopen("INP.txt","w",stdout);
        long long n=152623;
        long long re=0;
        cout<<200000<<" "<<5<<endl;
        for(int i=0;i<199999;i++)
        {
            cout<<i<<" "<<i+1;
            cout<<endl;
        }
        srand(1);
        for(int i=0;i<200000;i++)
        {
            cout<<rand()<<" ";
        }
    cout<<"\n0\n1\n2\n3\n50000\n";
    int t;
    cin>>t;
	return 0;
}

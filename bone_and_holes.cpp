#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;


int main()
{
    fio;
	int n,m,k; // cups,holes,swaps
    cin>>n>>m>>k;
    bool hol[n];
    f(i,0,n)
        hol[i]=0;
    f(i,0,m)
    {
        int te; cin>>te;
        hol[te-1]=1;
    }
    int bone=0;
    if(hol[0])
        cout<<"1"<<endl;
    else
    {
        f(i,0,k)
        {
            int u,v; // swap u and v
            cin>>u>>v;
            u--; v--;
            if(bone==u)
            {
                if(hol[u])
                {
                    bone=u;
                    break;
                }
                bone=v;
            }
            else if(bone==v)
            {
                if(hol[v])
                {
                    bone=v;
                    break;
                }
                bone=u;
            }
        }
        cout<<bone+1<<endl;
    }
	return 0;
}
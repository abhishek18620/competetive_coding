#include <bits/stdc++.h>
using namespace std;

void readint(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;c<48 || c>57;c=getchar_unlocked());
    for(;c>47 && c<58;c=getchar_unlocked())
        x=(x<<1)+(x<<3)+c-48;
}

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    vector<string> v;
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++) 
        for(int j=1;j<=len-i;j++)
            v.push_back(s.substr(i, j));
    sort(v.begin(),v.end());
    string sol="";
    for(string str:v)
        sol+=str;
    int G=0,P,M,q;
    readint(q);
    for(int i=0;i<q;i++)
    {
        readint(P);
        readint(M);
        int K=((P%M)*(G%M))%M;
        K++;
        G+=int(sol[K-1]);
        cout<<sol[K-1]<<endl;
    }
    //assert((1.0*(clock()-tStart)/CLOCKS_PER_SEC)<1.0);     // time limit to avoid infinite loops
    #ifdef LOCAL_DEFINE
        cerr<<"Time elapsed: "<<1.0*(clock()-tStart)/CLOCKS_PER_SEC<<" s.\n";
        cin>>len;
    #endif
    return 0;
}

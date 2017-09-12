#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i < k; i++)
using namespace std;

int n;
vector<string> a;
vector< pair<int,int> >sol;
int main()
{
    string str;
    int t; scanf("%d",&t);
    while(t--)
	{
        scanf("%d",&n);
        rep(i,0,n)
        {
            cin>>str;
            a.push_back(str);
        }
        rep(i,0,n)
        {
            rep(j,0,n)
            if(a[i][j]=='1')
            {
                sol.push_back(make_pair(i+1,j+1));
            }
        }
        int sz=sol.size();
        printf("%d\n",sz);
        rep(i,0,sz)
        {
            //a1 a2 b1 b2 c1 c2 d l r
            printf("0 1 0 1 0 1 %d %d %d\n",sol[i].second,sol[i].first,sol[i].first);
        }
        sol.clear();
        a.clear();
    }
    cin>>t;
	return 0;
}

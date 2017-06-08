#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define gc() getchar_unlocked()
#define test int t; cin>>t; while(t--)
using namespace std;

bool solve(char prv, char nxt)
{
    if(prv == 'C' and (nxt=='E' or nxt=='S'))
        return 1;
    else if(prv=='E' and nxt=='S')
        return 1;
    else
        return 0;
}

int main()
{
    fio;
	test
	{
        string s;
        cin>>s;
        int len=s.length();
        bool flag=1;
        char prv=s[0];
        f(i,1,len)
        {
            if(s[i] != prv) //different char encou.
            {
                if(solve(prv,s[i]))
                    prv=s[i];
                else
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
	}
	return 0;
}
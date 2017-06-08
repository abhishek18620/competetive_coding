#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i, j, k) for (int i = j; i < k; i++)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

bool check(vector<string> &G, vector<string> &P, int R, int C, int r, int c)
{
    bool flag;
    for (int i = 0; i <= R - r; i++)
    {
        for (int j = 0; j <= C - c; j++)
        {
            flag = false;
            for (int k = 0; k < r; k++)
            {
                for (int l = 0; l < c; l++)
                {
                    if (G[i + k][j + l] != P[k][l])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                return true;
        }
    }
    return false;
}

void scan(int &x){
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
    fio;
    test
    {
        int R;
        int C;
        scan(R); scan(C);
        vector<string> G(R);
        f(i,0,R)
            cin>>G[i];
        int r;
        int c;
        scan(r); scan(c);
        vector<string> P(r);
        f(i,0,r)
            cin>>P[i];

        if (check(G, P, R, C, r, c))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cin>>t;
    return 0;
}
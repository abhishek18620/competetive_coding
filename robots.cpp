#include <bits/stdc++.h>
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define test int t; cin >> t; while (t--)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    test
    {
	int m, n, u = 0, d = 0, r = 0, l = 0;
	bool flag = 0;
	cin >> m >> n;
	string s;
	cin >> s;
	fuck(i, 1, m + 1)
	{
	    fuck(j, 1, n + 1)
	    {
		flag = 0;
		int hor = j;
		int ver = i;
		fuck(k, 0, s.length())
		{
		    if (s[k] == 'U')
			ver--;
		    else if (s[k] == 'R')
			hor++;
		    else if (s[k] == 'D')
			ver++;
		    else
			hor--;
		    if (hor <= 0 or hor > n or ver <= 0 or ver > m)
		    {
			flag = 1;
			break;
		    }
		}
		if (!flag)
		    break;
	    }
	    if (!flag)
		break;
	}
	if (flag)
	    cout << "unsafe" << endl;
	else
	    cout << "safe" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define M 500
using namespace std;
vector<int> solution;
int sol[M][M];
int f(int i, int j, int temp_blog[M][M], int temp_yele[M][M])
{
    int ans = 0;
    if (i < 0 || j < 0)
        return 0;
    else if (sol[i][j] != -1)
        return sol[i][j];
    else
    {
        int dir1 = temp_yele[i][j];
        int dir2 = temp_blog[i][j];
        ans += max(f(i - 1, j, temp_blog, temp_yele) + dir1, f(i, j - 1, temp_blog, temp_yele) + dir2);
        sol[i][j] = ans;
        return ans;
    }
}
int main()
{
    int hold;
    while (1)
    {
        int blog[M][M], yele[M][M];
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                sol[i][j] = -1;
        }
        if (m == 0 and n == 0)
            break;
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int temp;
                    cin >> temp;
                    if (j > 0)
                        yele[i][j] = yele[i][j - 1] + temp;
                    else
                        yele[i][j] = temp;
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int temp;
                    cin >> temp;
                    if (i > 0)
                        blog[i][j] = blog[i - 1][j] + temp;
                    else
                        blog[i][j] = temp;
                }
            }
            int final_sol = f(m - 1, n - 1, blog, yele);
            solution.push_back(final_sol);
        }
    }
    for (int i = 0; i < solution.size(); i++)
        cout << "\n"
             << solution[i];
    return 0;
}
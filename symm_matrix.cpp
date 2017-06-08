#include <bits/stdc++.h>
#define M 100
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
bool a[M][M];

int main()
{
    fio;
	int n,k;
    bool flag=1;
    cin>>n>>k;
    ll ch=0;
    if(k > n*n)
        cout<<-1<<endl;
    else
    {
        f(i,0,n)
        {
            if(ch < k) //diangonal element changeable
            {
                if(!a[i][i])
                {
                    a[i][i]=!a[i][i];
                    ch++;
                }
            }
            else
                break;
        }
        if((ch - k)%2 == 0)
        {
            f(i,0,n)
            {
                f(j,0,n)
                {
                    if(k-ch >= 2)
                    {
                        if(!a[i][j] and !a[n-1-i][n-1-j])
                        {
                            a[i][j]=!a[i][j];
                            a[n-1-i][n-1-j]=!a[n-1-i][n-1-j];
                            ch+=2;
                        }
                    }
                else
                    break;
            }
            }
        }
        else
        {
            flag=0;
            cout<<-1<<endl;
        }
        //print
        if(flag)
        {
            f(i,0,n)
            {
                f(j,0,n)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }
    }
    cin>>n;
	return 0;
}
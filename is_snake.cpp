#include <bits/stdc++.h>
#define M 505
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define test int t; cin>>t; while(t--)
using namespace std;
    
char a[2][M];
void reset()
{
    f(i,0,M)
    {
        a[0][i]='.';
        a[1][i]='.';
    }
}
    
    
int main()
{
    test
    {
        int n; cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int count=0;
        reset();
        f(i,0,n)
        {
            a[0][i]=s1[i];
            if(s1[i]=='#')
                count++;
            a[1][i]=s2[i];
            if(s2[i]=='#')
                count++;
        }
        int visited=0;
        bool flag=1;
        f(i,0,n)
        {
            if(a[0][i]=='#')
            {
                visited++;
                a[0][i]='.';
                if(a[1][i]=='#' and a[0][i+1]=='#')
                {
                    if(a[1][i+1]=='.')
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        visited+=2;
                        a[1][i]='.';
                        a[1][i+1]='.';
                    }
                }
                else if(a[1][i]=='#')
                {
                    visited++;
                    a[1][i]='.';
                    bool temp=1;
                    f(j,i+1,n)
                    {
                        if(a[0][j]=='#' and a[1][j]=='#')
                        {
                            visited++;
                            a[1][j]='.';
                            i=j-1;
                            break;
                        }
                        else if(a[1][j]=='.')
                        {
                            temp=0;
                            break;
                        }
                        else
                        {
                            visited++;
                            a[1][j]='.';
                        }
                    }
                    if(!temp)
                        break;
                }
                else if(a[0][i+1]=='#')
                    continue;
                else
                    break;
            }
            else if(a[1][i]=='#')
            {
                visited++;
                a[1][i]='.';
                flag=1;
                bool temp=1;
                f(j,i+1,n)
                {
                    if(a[0][j]=='#' and a[1][j]=='#')
                    {
                        visited++;
                        a[1][j]='.';
                        i=j-1;
                        break;
                    }
                    else if(a[1][j]=='.')
                    {
                        temp=0;
                        break;
                    }
                    else
                    {
                        visited++;
                        a[1][j]='.';
                    }
                }
                if(!temp)
                    break;
            }
        }
        if(!flag or visited!=count)
        {
            reset();
            f(i,0,n)
            {
                a[0][i]=s1[i];
                a[1][i]=s2[i];
            }
            flag=1;
            visited=0;
            f(i,0,n)
            {
                if(a[1][i]=='#')
                {
                    visited++;
                    a[1][i]='.';
                    if(a[0][i]=='#' and a[1][i+1]=='#')
                    {
                        if(a[0][i+1]=='.')
                        {
                            flag=0;
                            break;
                        }
                        else
                        {
                            visited+=2;
                            a[0][i]='.';
                            a[0][i+1]='.';
                        }
                    }
                    else if(a[0][i]=='#')
                    {
                        visited++;
                        a[0][i]='.';
                        bool temp=1;
                        f(j,i+1,n)
                        {
                            if(a[1][j]=='#' and a[0][j]=='#')
                            {
                                visited++;
                                a[0][j]='.';
                                i=j-1;
                                break;
                            }
                            else if(a[0][j]=='.')
                            {
                                temp=0;
                                break;
                            }
                            else
                            {
                                visited++;
                                a[0][j]='.';
                            }
                        }
                        if(!temp)
                            break;
                    }
                    else if(a[1][i+1]=='#')
                        continue;
                    else
                    {
                        break;
                    }
    
                }
                else if(a[0][i]=='#')
                {
                    visited++;
                    a[0][i]='.';
                    bool temp=1;
                    f(j,i+1,n)
                    {
                        if(a[1][j]=='#' and a[0][j]=='#')
                        {
                            visited++;
                            a[0][j]='.';
                            i=j-1;
                            break;
                        }
                        else if(a[0][j]=='.')
                        {
                            temp=0;
                            break;
                        }
                        else
                        {
                            visited++;
                            a[0][j]='.';
                        }
                    }
                    if(!temp)
                        break;
                }
            }
        }
        if(flag and visited==count)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
} 
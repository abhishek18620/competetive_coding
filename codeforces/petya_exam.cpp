#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define pb push_back
using namespace std;

int main()
{
	string str1,str2,str3;
	cin>>str1>>str2;
    int n;
    scanf("%d",&n);
	int len1=str1.length();
    int len2=str2.length();
    int len3;
    size_t found;
    while(n--)
    {
        bool star=0,ans=1;
        char need='-';
        cin>>str3;
        len3=str3.length();
        if(len2-len3 > 1)
            ans=0;
        else
        {
            f(i,0,len2)
            {
                if(str2[i]!=str3[i])    //it must be a '?' or '*'
                {
                    need=str3[i];
                    if(str2[i]=='?')
                    {
                        found=str1.find(need);
                        if(found==string::npos)  //not found
                        {
                            ans=0;
                            break;
                        }
                    }
                    else if(str2[i]=='*')
                    {
                        if(str2[i+1]==need)
                        {
                            str3.erase(i);
                            len2--;
                            continue;
                        }
                        if(i==len2-1)
                        {
                            string ns=str3.substr(i,(len3-i));
                            bool possible=1;
                            f(j,0,ns.length())
                            {
                                if(str1.find(ns[j])!=string::npos)
                                {
                                    ans=0; break;
                                    possible=0;
                                }
                                if(!possible)
                                    break;
                            }
                        }
                        else
                        {
                            found=str1.find(need);
                            if(found!=string::npos)  //not found
                                continue;
                            else
                            {
                                ans=0; break;
                            }
                        }
                    }
                    else
                    {
                        ans=0;
                        break;
                    }
                }
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    cin>>n;
    return 0;
}
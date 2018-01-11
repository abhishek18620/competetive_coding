#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m,n;
pair<int,char> dp[5009][5009];
char str1[5009],str2[5009];

int main()
{
    #ifdef LOCAL_DEFINE
        clock_t tStart = clock();
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        scanf("%s %s",str1,str2);
        dp[0][0]=make_pair(0,'\0');
        dp[1][0]=make_pair(0,str1[0]);
        dp[0][1]=make_pair(0,str2[0]);
        for(int i=2;i<=m;i++)
        {
            if(str1[i-2]==str1[i-1])
                dp[i][0]=make_pair(dp[i-1][0].first,str1[i-1]);
            else
                dp[i][0]=make_pair(dp[i-1][0].first+1,str1[i-1]);
        }
        for(int i=2;i<=n;i++)
        {
            if(str2[i-2]==str2[i-1])
                dp[0][i]=make_pair(dp[0][i-1].first,str2[i-1]);
            else
                dp[0][i]=make_pair(dp[0][i-1].first+1,str2[i-1]);
        }

        for(int i=1;i<=m;i++)
        {
            int min1,min2;
            char lst1,lst2;
            for(int j=1;j<=n;j++)
            {
                if(dp[i-1][j].second == str1[i-1])
                {
                    min1=dp[i-1][j].first;
                    lst1=str1[i-1];
                }
                else
                {
                    min1=dp[i-1][j].first+1;
                    lst1=str1[i-1];
                }

                if(dp[i][j-1].second == str2[j-1])
                {
                    min2=dp[i][j-1].first;
                    lst2=str2[j-1];
                }
                else
                {
                    min2=dp[i][j-1].first+1;
                    lst2=str2[j-1];
                }

                if(min1>=min2)
                {
                    dp[i][j]=make_pair(min2,lst2);
                }
                else
                    dp[i][j]=make_pair(min1,lst1);
            }
        }
        printf("%d\n",dp[m][n].first+1);
    }
    return 0;
}

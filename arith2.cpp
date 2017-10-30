#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define scan(t) scanf("%d",&t)
#define scanl(t) scanf("%lld",&t)
#define print(t) printf("%d\n",t)
#define printl(t) printf("%lld\n",t)
using namespace std;
 
int main() {
    //fio;
    int t;
    scan(t);
    while(t--)
    {
        long long int num;
        scanl(num);
        long long int ans=num;
        while(true)
        {
            char ch;
            scanf(" %c",&ch);
            if(ch=='=')
            break;
            cin>>num;
            if(ch=='/')
            ans/=num;
            else
            if(ch=='*')
            ans*=num;
            else if(ch=='+')
            ans+=num;
            else
            ans-=num;
        }
        printl(ans);
    }
	return 0;
}
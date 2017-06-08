#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false);
#define f(i, j, k) for (int i = j; i < k; i++)
using namespace std;
void scan(int &x){
    	register int c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

int nof(int n)
{
    int s,nf=1;
    s=sqrt(n);
    f(i,2,s+1)
        if(n%i==0)
        nf++;
    return nf;
}
int main()
{
    int n,nor=0;
    scan(n);
    f(i,1,n+1)
        nor+=nof(i);
    printf("%d",nor);
    return 0;
}
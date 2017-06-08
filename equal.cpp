#include <bits/stdc++.h>
#define M 1010
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
int a[M];
void writel(ll n)
{
	if(n<0){n=-n;putchar('-');}
	ll i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(int &x){
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	//fio;
    // For getting input from input.txt file
    // freopen("/home/abhi/Desktop/codes/input/input.txt", "r", stdin);
    
    // // // Printing the Output to output.txt file
    // freopen("/home/abhi/Desktop/codes/input/output.txt", "w", stdout);
	test
	{
        int n; scan(n);
        f(i,0,n)
            scan(a[i]);
        sort(a,a+n);
        int add=0,steps=0;
        f(i,0,n-1)
        {
            if(a[i]+add==a[i+1])
                continue;
            else
            {
                int diff=a[i+1]-a[i]+add;
                add=a[i+1]-a[i]+add;
                int part1=(diff/5);
                int part2=0;
                if(diff%5!=0)
                {
                    part2=(diff%5)/2;
                }
                if((diff%5)%2 != 0)
                {
                    part2++;
                }
                steps+=part1+part2;
            }
        }
        cout<<steps<<endl;
	}
    cin>>t;
    return 0;
}
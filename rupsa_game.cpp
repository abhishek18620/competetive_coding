    #include <bits/stdc++.h>
    #define M 1000000007
    #define INF 999999
    #define fio ios::sync_with_stdio(false);
    typedef long long ll;
    #define f(i, j, k) for (ll i = j; i <= k; i++)
    using namespace std;
     
    void writel(ll n){
    	if(n<0){n=-n;putchar('-');}
    	ll i=10;
    	char output_buffer[11];output_buffer[10]='\n';
    	do{output_buffer[--i]=(n%10)+'0';n/=10;}
    	while(n);
    	do{putchar(output_buffer[i]);}while(++i<11);
    }
     
    // void scan(int &x){
    //     	register int c = getchar_unlocked();
    //     	x = 0;
    //     	for(;c<48 || c>57;c=getchar_unlocked());
    //     	for(;c>47 && c<58;c=getchar_unlocked())
    //     		x=(x<<1)+(x<<3)+c-48;
    //     }
     
    void scanl(ll &x){
        	register ll c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
    }
        
        int main()
        {
            ll t; scanl(t);
            while(t--)
            {
                ll n,x,sol=0,prev=0,p=2,cur;
                scanl(n); scanl(x);
                prev=x;
                scanl(x);   // previous one(2^i-1) times
                sol=prev*x;
                sol*=2;
                sol%=M;               
                prev+=x;
                prev*=2;
                f(i,2,n)
                {
                    p*=2;
                    p%=M;            //
                    sol*=2;
                    sol%=M;           //
                    scanl(x);
                    sol+=prev*x;
                    sol%=M;           //
                    cur=p*x;
                    prev+=cur;
                    prev%=M;            //
                }
                writel(sol);
            }
            return 0;
        } 
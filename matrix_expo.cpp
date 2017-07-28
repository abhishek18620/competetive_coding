// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACk HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACkNOWLEDGED THEM.
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
typedef vector< vector<ll> > matrix;

//GLOBALS
int n,k;
const ll MOD=1000000000;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(k+1, vector<ll>(k+1));
    f(i,0,k)
        f(j,0,k) 
            f(s,0,k)
                C[i][j] = (C[i][j] + (A[i][s] * B[s][j])%MOD)%MOD;
    return C;
}

// computes A ^ p
matrix expo(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, expo(A, p-1));
    matrix X = expo(A, p/2);
    return mul(X, X);
}

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
    	bool neg=(c=='-')?1:0;
        x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

void scanl(ll &x){
    	register ll c = gc();
        bool neg=(c=='-')?1:0;
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
        x*=(neg)?-1:1;
    }

int main()
{
	//fio;
	test
	{
        scan(k);
        vector<ll> b(k),c(k),f1(k);
        matrix trans(k,vector<ll>(k));        // a 0 2D array
        
        f(i,0,k)
            scanl(b[i]);
        f(i,0,k)
            scanl(c[i]);
        //F1
        f(i,0,k)
            f1[i]=b[i];
        //create transformation matrix
        int te=1;
        f(i,0,k-1)
        {
            f(j,0,k)
                trans[i][j]=0;
            trans[i][te++]=1;
        }
        f(i,0,k)
            trans[k-1][i]=c[k-1-i];
        
        scan(n);
        //fn = trans^(n-1) * f1;
        trans = expo(trans,n-1);
        ll sol=0;
        f(i,0, k)
            sol = (sol + (trans[0][i] * f1[i]) % MOD)%MOD;
        
        writel(sol);
    }
    cin>>t;
	return 0;
}
class FastIO{
    //#define getchar() (getchar_unlocked()) //For hackerrank
    private:
        //inline if read speed is needed, huge compilation time required though
        //safe no fread implementation
        int readInt(int &n){
            register int c;
            n = 0;
            bool neg = false;
            c = getchar();
            if(!(~c)) return -1;
            for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
            if(c == '-') neg = true, c = getchar();
            for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
            if(neg) n = -n;
            return 1;
        }
        int readLL(long long &n){
            register int c;
            n = 0;
            bool neg = false;
            c = getchar();
            if(!(~c)) return -1;
            for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
            if(c == '-') neg = true, c = getchar();
            for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
            if(neg) n = -n;
            return 1;
        }
        int readDouble(double &n){
            register int c;
            n = 0;
            bool neg = false;
            c = getchar();
            if(!(~c)) return -1;
            for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
            if(c == '-') neg = true, c = getchar();
            for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
            if(c != '.'){
                if(neg) n = -n;
                return 1;
        }
            double div = 1;
            for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
            n /= div;
            if(neg) n = -n;
            return 1;
        }
        int readStr(char *str){
            register char c = getchar();
            register int len = 0;
            if(!(~c)) return -1;
            while(c < 33 && ~c) c = getchar(); //32 if space should be included
            //32 if stop at space, 10 if stop at next line
            while(c != 10 && c != 32 && ~c){
                str[len] = c;
                c = getchar();
                len++;
            }
            str[len] = '\0';
            //Just in case if needs to return arriving at end of line
            //if(c == 10) return 10;
            return 1;
        }
        int readStr(char *str, int len){
            //Reading string of size len
            for(int i = 0; i < len; i++){
                str[i] = getchar();
                if(!(~str[i])){
                    str[i] = '\0';
                    return -1;
                }
                //Remove this if str can't go to next line
                /*if(str[i] == 10){
                    str[i] = '\0';
                    return 10;
                }*/
            }
            str[len] = '\0';
            return 1;
        }

// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
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
	fio;
	test
	{

	}
	return 0;
}



// for cout and cin//
ios::sync_with_stdio(false); cin.tie(0);


// extremely fast

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


//	STRING MANIPULATION WITH SSTREAM
		vector<string> fir,sec;
		// string 1
		istringstream iss1(str1);
		copy(istream_iterator<string>(iss1),
     	istream_iterator<string>(),
     	back_inserter(fir));
		// string 2
		istringstream iss2(str2);
		copy(istream_iterator<string>(iss2),
     	istream_iterator<string>(),
     	back_inserter(sec));


// numeric string with spaces
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,out;
    stringstream ss;
    getline(cin,s);
    ss<<s;
    int x;
    while(ss>>out)
    {
        stringstream convert(out);
        convert>>x;
        cout<<x<<endl;
    }
    return 0;
}




void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}



#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long int slong;
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

#ifdef VSP4 
    #include "debug.h"    
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

const int MAXN = 6e5;
const int SQRTN = 300;
const int LOGN = 16;
const int INT_INFINITY = 1001001001;
const slong LONG_INFINITY = 2001001001001001001ll;
const double EPS = 1e-6;

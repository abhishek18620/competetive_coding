#include <bits/stdc++.h>
#define M 500
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;
typedef pair<ll,ll> pai;
//GLOBALS
ll a[M][M],b[M][M],n,m;
ll temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

ll neighbour_a(int i, int j)
{
    if(i==0)
    {
        if(j==0)
        {
            temp1=max(a[i][j],a[i][j+1]);
            temp2=max(temp1,a[i+1][j+1]);
            temp3=max(temp2,a[i+1][j]);
            return temp3;
        }
        else if(j==m-1)
        {
            temp1=max(a[i][j],a[i+1][j]);
            temp2=max(temp1,a[i+1][j-1]);
            temp3=max(temp2,a[i][j-1]);
            return temp3;
        }
        else
        {
            temp1=max(a[i][j],a[i][j+1]);
            temp2=max(temp1,a[i+1][j+1]);
            temp3=max(temp2,a[i+1][j]);
            temp4=max(temp3,a[i+1][j-1]);
            temp5=max(temp4,a[i-1][j-1]);
            return temp5;
        }
    }
    else if(i==m-1)
    {
        if(j==0)
        {
            temp1=max(a[i][j],a[i-1][j]);
            temp2=max(temp1,a[i-1][j+1]);
            temp3=max(temp2,a[i][j+1]);
            return temp3;
        }
        else if(j==m-1)
        {
            temp1=max(a[i][j],a[i-1][j]);
            temp2=max(temp1,a[i][j-1]);
            temp3=max(temp2,a[i][j]);
            return temp3;
        }
        else
        {
            temp1=max(a[i][j],a[i-1][j]);
            temp2=max(temp1,a[i-1][j+1]);
            temp3=max(temp2,a[i][j+1]);
            temp4=max(temp3,a[i][j-1]);
            temp5=max(temp4,a[i-1][j-1]);
            return temp5;
        }
    }
    else if(j==0)
    {
        
        temp1=max(a[i][j],a[i-1][j]);
        temp2=max(temp1,a[i-1][j+1]);
        temp3=max(temp2,a[i][j+1]);
        temp4=max(temp3,a[i+1][j+1]);
        temp5=max(temp4,a[i+1][j]);
        return temp5;
    }
    else if(j==n-1)
    {
        temp1=max(a[i][j],a[i-1][j]);
        temp2=max(temp1,a[i+1][j]);
        temp3=max(temp2,a[i+1][j-1]);
        temp4=max(temp3,a[i][j-1]);
        temp5=max(temp4,a[i-1][j-1]);
        return temp5;
    }
    else
    {
        temp1=max(a[i][j],a[i-1][j]);
        temp2=max(temp1,a[i-1][j+1]);
        temp3=max(temp2,a[i][j+1]);
        temp4=max(temp3,a[i+1][j+1]);
        temp5=max(temp4,a[i+1][j]);
        temp6=max(temp5,a[i+1][j-1]);
        temp7=max(temp6,a[i][j-1]);
        temp8=max(temp7,a[i-1][j-1]);
        return temp8;
    }
}

ll neighbour_b(int i, int j)
{
    if(i==0)
    {
        if(j==0)
        {
            temp1=max(b[i][j],b[i][j+1]);
            temp2=max(temp1,b[i+1][j+1]);
            temp3=max(temp2,b[i+1][j]);
            return temp3;
        }
        else if(j==m-1)
        {
            temp1=max(b[i][j],b[i+1][j]);
            temp2=max(temp1,b[i+1][j-1]);
            temp3=max(temp2,b[i][j-1]);
            return temp3;
        }
        else
        {
            temp1=max(b[i][j],b[i][j+1]);
            temp2=max(temp1,b[i+1][j+1]);
            temp3=max(temp2,b[i+1][j]);
            temp4=max(temp3,b[i+1][j-1]);
            temp5=max(temp4,b[i-1][j-1]);
            return temp5;
        }
    }
    else if(i==m-1)
    {
        if(j==0)
        {
            temp1=max(b[i][j],b[i-1][j]);
            temp2=max(temp1,b[i-1][j+1]);
            temp3=max(temp2,b[i][j+1]);
            return temp3;
        }
        else if(j==m-1)
        {
            temp1=max(b[i][j],b[i-1][j]);
            temp2=max(temp1,b[i][j-1]);
            temp3=max(temp2,b[i][j]);
            return temp3;
        }
        else
        {
            temp1=max(b[i][j],b[i-1][j]);
            temp2=max(temp1,b[i-1][j+1]);
            temp3=max(temp2,b[i][j+1]);
            temp4=max(temp3,b[i][j-1]);
            temp5=max(temp4,b[i-1][j-1]);
            return temp5;
        }
    }
    else if(j==0)
    {
        
        temp1=max(b[i][j],b[i-1][j]);
        temp2=max(temp1,b[i-1][j+1]);
        temp3=max(temp2,b[i][j+1]);
        temp4=max(temp3,b[i+1][j+1]);
        temp5=max(temp4,b[i+1][j]);
        return temp5;
    }
    else if(j==n-1)
    {
        temp1=max(b[i][j],b[i-1][j]);
        temp2=max(temp1,b[i+1][j]);
        temp3=max(temp2,b[i+1][j-1]);
        temp4=max(temp3,b[i][j-1]);
        temp5=max(temp4,b[i-1][j-1]);
        return temp5;
    }
    else
    {
        temp1=max(b[i][j],b[i-1][j]);
        temp2=max(temp1,b[i-1][j+1]);
        temp3=max(temp2,b[i][j+1]);
        temp4=max(temp3,b[i+1][j+1]);
        temp5=max(temp4,b[i+1][j]);
        temp6=max(temp5,b[i+1][j-1]);
        temp7=max(temp6,b[i][j-1]);
        temp8=max(temp7,b[i-1][j-1]);
        return temp8;
    }
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
	test
	{
        scanl(m); scanl(n);
        ll max=-1,cnt=0;
        f(i,0,m)
        {
            f(j,0,n)
            {
                scanl(a[i][j]);
                b[i][j]=a[i][j];
                if(a[i][j] > max)
                {
                    max=a[i][j];
                    cnt=1;
                }
                else if(a[i][j]==max)
                    cnt++;
            }
        }
        ll sol=0;
        ll ans=cnt;
        bool odd=1;
        //PROCESSING
        while(ans!=m*n)
        {
            //store in b check from a 
            if(odd)
            {
                f(i,0,m)
                {
                    f(j,0,n)
                    {
                        ll temp=neighbour_a(i,j);
                        if(a[i][j]==max)
                        {
                            b[i][j]=a[i][j];
                            continue;
                        }
                        //need to be updated
                        else if(temp!=a[i][j])
                        {
                            b[i][j]=temp;
                            if(temp==max)
                                ans++;
                        }
                    }
                }
                odd=0;
            }
            else
            {
                f(i,0,m)
                {
                    f(j,0,n)
                    {
                        ll temp=neighbour_b(i,j);
                        if(b[i][j]==max)
                        {
                            a[i][j]=b[i][j];
                            continue;
                        }
                        //need to be updated
                        else if(temp!=b[i][j])
                        {
                            a[i][j]=temp;
                            if(temp==max)
                                ans++;
                        }
                    }
                }
            }
            sol++;
        }
        cout<<sol<<endl;
    }
    cin>>t;
	return 0;
}
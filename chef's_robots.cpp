// TEMPLATE //
//ELLIOT ALDERSON(NO I'M NOT Mr. ROBOT)
//YES IAM AN ACTIVE BLACK HAT AIMING FOR 0.0 2M HERE
//MY TEAM HAD ALREADY REPORTED 3 BUGS IN CODECHEF'S SITE BUT THEY NEVER ACKNOWLEDGED THEM.
#include <bits/stdc++.h>
#define M 104
#define INF 1e8+9
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


//vertex indexing
// ind(i,j)=(i+1)*m+j

int a[M][M],ts1[M][M],ts2[M][M],n,m,k1,k2;
bool visited=0;
//here comes the original paradox of this problem
//bfs in a 2d matrix..a path finding problem and a very frequent one
//consider yourself on the middle of matrix and try to visualise where we can go 
// with a walking range of K. we'll find the point where we r standing is the centre of circular path
// seems difficult but easy to visualise
void bfs1(int x,int y,int k)
{
	f(i,0,n+1)
		f(j,0,m+1)
			ts1[i][j]=INF;
	queue< pair<int,int> > q;
	q.push(mp(x,y));
	ts1[x][y]=0;
	while(!q.empty())
	{
		int currx=q.front().F;
		int curry=q.front().S;
		int hops=ts1[currx][curry];
		q.pop();
		f(i,currx-k,currx+k+1)
		{
			f(j,curry-k,curry+k+1)
			{
				if(i<0 or j<0 or i>n-1 or j>m-1)
					continue;
				else
				{
					int dis=abs(currx-i)+abs(curry-j);
					//move allowed
					if(dis<=k and a[i][j]==0)
					{
						if(ts1[i][j]>hops+1)
						{
							ts1[i][j]=hops+1;
							q.push(mp(i,j));
						}
					}
				}
			}
		}
	}
} 

void bfs2(int x,int y,int k)
{
	f(i,0,n+1)
		f(j,0,m+1)
			ts2[i][j]=INF;
	queue< pair<int,int> > q;
	q.push(mp(x,y));
	ts2[x][y]=0;
	while(!q.empty())
	{
		int currx=q.front().F;
		int curry=q.front().S;
		int hops=ts2[currx][curry];
		q.pop();
		f(i,currx-k,currx+k+1)
		{
			f(j,curry-k,curry+k+1)
			{
				if(i<0 or j<0 or i>n-1 or j>m-1)
					continue;
				else
				{
					int dis=abs(currx-i)+abs(curry-j);
					//move allowed
					if(dis<=k and a[i][j]==0)
					{
						if(ts2[i][j]>hops+1)
						{
							ts2[i][j]=hops+1;
							q.push(mp(i,j));
						}
					}
				}
			}
		}
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
    	bool neg=0;
		if(x<0)
			neg=1;
		register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
		if(neg)
			x*=-1;
	}

void scanl(ll &x){
		bool neg=0;
		if(x<0)
			neg=1;
    	register ll c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
		if(neg)
			x*=-1;
	}

int main()
{
	fio;
    test
	{
        //scanf("%d %d %d %d",&n,&m,&k1,&k2);
        scan(n); scan(m); scan(k1); scan(k2);
		f(i,0,n)
            f(j,0,m)
                scan(a[i][j]);
				//scanf("%d",&a[i][j]);
		bfs1(0,0,k1);
		bfs2(0,m-1,k2);
		int sol=2*INF;
		f(i,0,n)
		{
			f(j,0,m)
			{
				sol=min(sol,max(ts1[i][j],ts2[i][j]));
			}
		}
		if(sol==INF)
			cout<<"-1"<<endl;
		else
			cout<<sol<<endl;
	}
	cin>>t;
	return 0;
}
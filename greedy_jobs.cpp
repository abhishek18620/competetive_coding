#include <bits/stdc++.h>
#define M 10000
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define pc(x) putchar_unlocked(x);
#define test int t; scan(t); while(t--)
using namespace std;
typedef pair<ll,ll> pai;

ll max_time;
// CUSTOM COMPARATOR
bool comp(const pai& lhs, const pai& rhs)
{
  return (lhs.second-max_time) < (rhs.second-max_time);
}

void write(int n)
{
	if(n<0){n=-n;putchar('-');}
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar(output_buffer[i]);}while(++i<11);
}

void scan(int &x){
    	register int c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

void scanl(ll &x){
    	register ll c = getchar_unlocked();
    	x = 0;
    	for(;c<48 || c>57;c=getchar_unlocked());
    	for(;c>47 && c<58;c=getchar_unlocked())
    		x=(x<<1)+(x<<3)+c-48;
    }

int main()
{
	test
	{
        int n; scan(n);
        vector<pai> job;
        f(i,0,n)
        {
            ll s,e; scanl(s); scanl(e);
            job.push_back(make_pair(s,e));
        }
        max_time=job[0].second;
        f(i,1,n)
        {
            if(job[i].second > max_time)
                max_time=job[i].second;
        }
        sort(job.begin(),job.end(),comp);
        // f(i,0,job.size())
        //     cout<<"\njob is :  start="<<job[i].first<<"     end :  "<<job[i].second;
        
        int jobs=0;
        ll st=-1;
        f(i,0,job.size())
        {
            if(job[i].first>=st) // if starting time is same
            {
                jobs++;
                st=job[i].second;
            }
        }
        write(jobs);
    }
    cin>>t;
	return 0;
}
#include <bits/stdc++.h>
#define M 300000
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define test int t; scan(t); while(t--)
using namespace std;

//GLOBALS
int seg[M],lazy[M],n,q,level,ch;
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
    	register int c = gc();
    	x = 0;
    	for(;c<48 || c>57;c=gc());
    	for(;c>47 && c<58;c=gc())
    		x=(x<<1)+(x<<3)+c-48;
    }

//BUILD SEGMENT TREE
void build_tree()
{
	//size of array(should be -1 but who needs errors)
	int sz=1 << (level+1);
	fr(i,sz,1)
	{
		if(i >= (1 << level))
			seg[i]=0;
		else
			seg[i]=seg[i >> i] + seg[(i >> 1)+ 1];
	}
}


//flip coin
void flip_lazy(int curr , int range)
{
	lazy[curr] = !lazy[curr];
	seg[curr] = range-seg[curr];
}


//FIND RESULT(QUERIES A RANGE)
int find_result(int curr, int qlow,int qhigh,int low,int high)
{
	if(qlow <= qhigh)
	{
		//total overlap
		if(low >= qlow and high <= qhigh)
			return seg[curr];
		//PARTIAL OVERLAP
		else if((qlow>=low and high >= qlow) or (qhigh >=low and qhigh <=high))
		{
			if(lazy[curr])		//check if any changes needs to be propagated
			{
				//propagate chages to left child
				flip_lazy(curr << 1 , (high-low+1) >> 1);
				//propagate chages to right child
				flip_lazy((curr << 1) +1 , (high-low+1) >> 1);
				lazy[curr]=0;
			}
			// NOW UPDATE BOTH SUBTREES
			int mid = (high+low) >>1;
			//LEFT + RIGHT
			return find_result(curr << 1, qlow, qhigh, low, mid) +
				   find_result((curr << 1) + 1, qlow, qhigh, mid + 1, high);
		} 
	}
	// no segment overlap
	return 0;
}


//update segment tree with lazy propagation
//ulow and uhigh = range given low and high (start from extreme ranges and then shrink)
void update_segment_tree(int curr, int ulow,int uhigh,int low,int high)
{
	if(ulow <= uhigh)
	{
		//total overlap
		if(low >= ulow and high <= uhigh)
		{
			flip_lazy(curr , high-low+1);
		}
		//PARTIAL OVERLAP
		else if((ulow>=low and high >= ulow) or (uhigh >=low and uhigh <=high))
		{
			if(lazy[curr])		//check if any changes needs to be propagated
			{
				//propagate chages to left child
				flip_lazy(curr << 1 , (high-low+1) >> 1);
				//propagate chages to right child
				flip_lazy((curr << 1) +1 , (high-low+1) >> 1);
				lazy[curr]=0;
			}
			// NOW UPDATE BOTH SUBTREES
			int mid = (high+low) >>1;
			//LEFT
			update_segment_tree(curr << 1, ulow, uhigh, low, mid);
            //RIGHT
			update_segment_tree((curr << 1) + 1, ulow, uhigh, mid + 1, high);
			
			if(curr < (1 << level))
				seg[curr]= seg[curr << 1]+seg[(curr << 1)+1];
		} 
	}
}

//MAIN
int main()
{
	scan(n); scan(q);
	//determine size of seg array
	while(n >= (1 << level))	// size = 2^(level + 1) - 1
	{
		level++;
	}
	int sz=1 << (level+1);
	f(i,1,sz)
		lazy[i]=0;
	// BUILD A SEGMENT TREE(as an array)
	build_tree();
	f(i,0,q)
	{
		int l,r,ans;
		scan(ch); scan(l); scan(r);
		if(ch == 0)
			update_segment_tree(1, (1 << level) + l, (1 << level) + r, 1 << level, (1 << (level + 1)) - 1);
		else
		{
			ans = find_result(1,(1 <<level) + l,(1 << level) + r, 1 << level , (1<<(level+1))-1 );
			//COUT ANSWER SEPARATELY FOR SIMPLICITY
			//FUCK MAN !!! FINALLY
			//PRETTY LONG LEARNING ADVENTURE
			write(ans);
		}
	}
	cin>>n;
	return 0;
}
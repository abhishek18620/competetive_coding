#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i, j, k) for (int i = j; i < k; i++)
#define test int t; cin>>t; while(t--)
using namespace std;

int main()
{
	fio;
	test
	{
		bool two[4];
		f(i,0,4)
			two[i]=0;
		vector<string> fir,sec;
		// string 1
		f(i,0,4)
		{
			string str1;
			cin>>str1;
			fir.push_back(str1);
		}
		// string 2
		f(i,0,4)
		{
			string str1;
			cin>>str1;
			sec.push_back(str1);
		}

		bool out=0;
		int count=0;
		f(i,0,4)
		{
			f(j,0,4)
			{
				if(!two[j])
				{
					if(!fir[i].compare(sec[j])) //equal
					{
						two[j]=1;
						count++;
						break;
					}
				}
			}
			if(count >=2)
			{
				cout<<"similar"<<endl;
				out=1; break;
			}
		}
		if(!out)
			cout<<"dissimilar"<<endl;
	}
	cin>>t;
	return 0;
}
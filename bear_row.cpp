#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (ll i = j; i < k; i++)
#define test int t; cin>>t; while(t--)
using namespace std;

int main()
{
    fio;
	test
	{
        string str;
        cin>>str;
        ll pack=0,av_pos=-1,ini_pos=-1,ti=0;
        bool first=1;
        ll n=str.length();
        // traverse once to find packs and palce them
        f(i,0,n)
        {
            if(first)
            {
                if(str[i]=='1')
                {
                    //pack++;
                    f(j,i,n) //find available place
                    {
                        if(str[j]=='1')
                            pack++;
                        else
                        {
                            if(first)   //first 0 means pack calculated
                            {
                                //pack+=j-i-1;
                                first=0;
                                ini_pos=j-1;
                            }

                            if(str[j+1]=='1')    // shouls be like [01]
                            {
                                av_pos=j;
                                ti+=pack*(av_pos-ini_pos+1);
                                pack++;
                                ini_pos=j+1;
                                av_pos=i=j+1;
                                break;
                            }
                            else if(j==n-1)
                            {
                                av_pos=j;
                                ti+=pack*(av_pos-ini_pos+1);
                                i=j+1;
                            }
                        }
                    }
                }
            }
            else
            {
                if(str[i]=='0')
                {
                    av_pos++;
                    if(str[i+1]=='1')
                    {
                        if(av_pos!=ini_pos)
                            ti+=pack*(av_pos-ini_pos+1);
                        pack++;
                        i++;
                        ini_pos=av_pos=i+1;
                    }
                    else if(i==n-1)
                    {
                        ti+=pack*(av_pos-ini_pos+1);
                    }
                }
                else
                    pack++;
            }
        }
        cout<<ti<<endl;
    }
    cin>>t;
	return 0;
}
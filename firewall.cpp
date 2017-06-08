#include <bits/stdc++.h>
#define fnf ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define fuck(i, j, k) for (int i = j; i < k; i++)
#define pu push_back
#define mp make_pair
using namespace std;
 
string sub_calc(string str1 , string str2)
{
    string te;
    int bou=min(str1.length(),str2.length());
    fuck(j,0,bou)
    {
        if(str1[j]==str2[j])
        {
            te.pu(str1[j]);
        }
        else
        {
            te.pu(str1[j]);
            break;
        }
    }
    return te;
}
 
bool sub_checker(string str1 , string str2, vector<string> &answer)
{
    string te;
    int bou=min(str1.length(),str2.length());
    fuck(j,0,bou)
    {
        if(str1[j]==str2[j])
        {
            te.pu(str1[j]);
        }
        else
            break;
    }
    ll ind=answer.size()-1;
    string lst=answer[ind];
    if(te.length()>=lst.length())
        return 1;
    else
        return 0;
}
  

int main()
{
    fnf;
    ll n;
    vector<string> allow,disall,answer;
    answer.pu("&");
    cin>>n;
    char ch;
    string s,prv="";
    ll size1=0,size2=0;
    fuck(i,0,n)
    {
        cin>>ch>>s;
        if(ch == '-')
            allow.pu(s);
        else
            disall.pu(s);
    }
    size1=allow.size(); size2=disall.size();
    sort(allow.begin(),allow.end());
    sort(disall.begin(),disall.end());
    ll ptr1=0,ptr2=0,bou=-1,prev_ptr1=0,save_ptr2=0;
    string str1,str2;
    bool exit_check=0;
    while(ptr1 < size1)
    {
        fuck(i,ptr2,size2)
        {
            str1=allow[ptr1];
            str2=disall[i];
            if(str1[0]==str2[0])
            {
                int temp_ptr2=ptr2;
                string sol1=sub_calc(str1,str2);
                if(sol1[sol1.length()-1] == str2[sol1.length()-1])
                {
                    int sr=sol1.length()-1;
                    char ter= str1[sr];
                    if(str1.length()>sol1.length())
                    {
                        sol1.pu(str1[sr+1]);
                    }
                    else if(sol1[sr] == str2[sr])
                    {
                        exit_check=1;
                        break;
                    }
                }
                if(sol1.length() > prv.length())
                {
                    prv=sol1;
                    ptr2=i;
                }
                else if(str1 > str2)
                {
                    continue;
                }
                else
                {
                    answer.pu(prv);
                    prv="";
                    ptr1++;
                    fuck(y,ptr1,size1)
                    {
                        if(sub_checker(allow[y-1],allow[y],answer))
                        {
                            ptr1++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    i=ptr2-1;
                }
            }
            else
            {
                if(prv.length() > 0)
                {
                    answer.pu(prv);
                    prv="";
                    ptr1++;
                    fuck(y,ptr1,size1)
                    {
                        if(sub_checker(allow[y-1],allow[y],answer))
                        {
                            ptr1++;
                        }
                        else
                            break;
                    }
                    prv="";
                }
                else
                {
                    fuck(j,ptr2,size2)
                    {
                        if(disall[j][0]>=str1[0])
                        {
                            ptr2=j;
                            break;
                        }
                    }
                    if(disall[ptr2][0]!=str1[0])
                    {
                        string lst=*(answer.end()-1);
                        string sol1 = sub_calc(str1,lst);
                        if(sol1.length()==lst.length())
                        {
                            ll st=sol1.length();
                            if(sol1[st-1] !=lst[st-1])
                                answer.pu(sol1);
                        }
                        else
                            answer.pu(sol1);
                        ptr1++;
                    }
                }
                i=ptr2-1;
            }
            if(ptr1 == size1)
                break;
        }
        if(exit_check)
            break;
        else if(ptr2 > size2-1)
        {
            if(prv.length() > 0)
            {
                answer.pu(prv);
                prv="";
                ptr1++;
                fuck(y,ptr1,size1)
                {
                    if(sub_checker(allow[y-1],allow[y],answer))
                    {
                        ptr1++;
                        ptr2=save_ptr2;                
                    }
                    else
                        break;
                }
            }
            fuck(i,ptr1,size1)
            {
                ll ind=answer.size()-1;
                string lst=answer[ind];
                str1=allow[ptr1];
                string sol1=sub_calc(str1,lst);
                if(sol1.length()==lst.length())
                {
                    ll st=sol1.length()-1;
                    if(sol1[st]!=lst[st])
                        answer.pu(sol1);
                }
                else
                    answer.pu(sol1);
                ptr1++;
            }
        }
        else
        {
            if(prv.length() > 0)
            {
                answer.pu(prv);
                prv="";
                ptr1++;
                fuck(y,ptr1,size1)
                {
                    if(sub_checker(allow[y-1],allow[y],answer))
                    {
                        ptr1++;
                        ptr2=save_ptr2;                
                    }
                    else
                        break;
                }
            }
        }
    }
    if(exit_check)
        cout<<"-1"<<endl;
    else
    {
        cout<<answer.size()-1<<endl;
        fuck(i,1,answer.size())
            cout<<answer[i]<<endl;
    }
    cin>>n;
    return 0;
}
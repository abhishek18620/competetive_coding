#include <bits/stdc++.h>
typedef long long ll;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i, j, k) for (int i = j; i < k; i++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
//GLOBALS    
int n,k,p,ctr=0,sol=-1,sol_ind=0,fr=0,re=0,key1=-1,key2=-1,f,r;
vector<int> ans;
vector<bool> a;
deque<bool> b;
deque<int> q;
    
    
void iterate()
{
    int temp=0,res=0,ind=0;
    for (deque<int>::iterator it = q.begin(); it!=q.end(); ++it)
    {
        if(temp < *it)
        {
            temp = *it;
            res=ind;
        }
        ind++;
    }
    sol_ind=res;
    sol=temp;
}
    
int main()
{
    fio;
    cin>>n; cin>>k; cin>>p;
    f=n-1; r=n-2;
    if(k>n)
        k=n;
    f(i,0,n)
    {
        bool te; cin>>te;
        a.pb(te);
        b.pb(te);
    }
    string s; cin>>s;
    f(i,0,k)
    {
        if(a[i])
            ctr++;
    }
    sol=ctr;
    sol_ind=0;
    q.push_back(ctr);
    fr=0; re=n-1;
    f(i,1,n-k+1)
    {
        if(a[i-1] and !a[i+k-1])
        {
            ctr--;
        }
        else if(!a[i-1] and a[i+k-1])
            ctr++;
        q.push_back(ctr);
        if(ctr > sol)
        {
            sol=ctr;
            sol_ind=i;
        }
    }
    int for_one=sol;
    deque<bool>::iterator k1=b.begin();
    k1+=sol_ind;
    fr=0; re=n-1; key1=k-1; key2=n-k;
    f(i,0,n-1)
    {
        q.pop_back();
        b.push_front(b.back());
        b.pop_back();
        if(b.front())
        {
            bool value=*(b.begin() +(k));
            if(!value)
            {
                q.push_front(q.front()+1);
                if(sol_ind == 1)
                {
                    sol=q.front();
                    sol_ind=0;
                }
                else if(sol_ind == n-k)
                {
                    if(q.front() >= sol)
                    {
                        sol=q.front();
                        sol_ind=0;
                    }
                    else
                    {
                        iterate();
                    }
                }
                else
                {
                    if(sol <= q.front())
                    {
                        sol=q.front();
                        sol_ind=0;
                    }
                    else
                        sol_ind++;
                }
            }
            else
            {
                q.push_front(q.front());
                if(sol_ind == n-k)
                {
                    iterate();
                }
                else if(sol_ind!=0)
                    sol_ind++;
                
            }
        }
        else 
        {
            bool value=*(b.begin() +(k));
            if(value)
            {
                q.push_front(q.front()-1);
                sol_ind++;
            }
            else
            {
                q.push_front(q.front());
                if(sol_ind != 0)
                    sol_ind++;
            }
        }
        ans.push_back(sol);
    }
    
        int flips =0;
        f(i,0,p)
        {
            char ch=s[i];
            if(s[i] == '!')
            {
                flips++;
            }
            else
            {
                if(flips==0 or flips%n==0)
                    cout<<for_one<<endl;
                else
                    cout<<ans[(flips%n) - 1]<<endl;
            }
        }
        cin>>n;
                return 0;
}
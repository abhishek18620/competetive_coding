include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false);
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i > k; i--)
using namespace std;
int main()
{
    fio; cin.tie(0);
    int n; cin>>n;
    int a[n],curr,len=-1000;
    f(i,0,n)
        cin>>a[i];
    sort(a,a+n);
    // f(i,0,n)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    f(i,0,n-1)
    {
        fr(j,n-1,i)
        {
            curr=1;
            int sum=a[i]+a[j],save_r=j-1;
            f(l,i+1,save_r)
            {
                fr(r,save_r,l)
                    if(a[l]+a[r] == sum)
                    {
                        curr++;
                        save_r=r-1;
                        break;
                    }
            }
        if(curr > len)
            len=curr;
        }
    }
    cout<<2*len<<endl;
    return 0;
} 
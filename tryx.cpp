#include <bits/stdc++.h>
#define M 509
#define INF 999999
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define mp(i,j) make_pair(i,j)
#define F first
#define S second
#define test int t; scan(t); while(t--)
using namespace std;
typedef pair<int,int> pai;
    
//GLOBALS
ll a[M][M],n,m;
int save[M*M],temp[M*M];
vector<pai> mid;
    
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
    fio;
    test
    {
    // {
    //     scanl(m); scanl(n);
    //     ll max_el=-1,cnt=0;
    //     f(i,0,m)
    //     {
    //         f(j,0,n)
    //         {
    //             scanl(a[i][j]);
    //             if(a[i][j] > max_el)
    //                 max_el=a[i][j];
    //         }
    //     }
    //     int top=INF,left=INF,right=INF,down=INF,mid_hor=INF,mid_ver=INF;
    //     pai p1[2],p2[2],p3[2],p4[2],p5[2];
    //     vector<pai> mid;
    //     f(i,0,m)
    //     {
    //         f(j,0,n)
    //         {
    //             if(a[i][j]!=max_el)
    //             {
    //                 if(i<=top)
    //                 {
    //                     if(i<top)
    //                     {
    //                         p1[0].F=i;
    //                         p1[0].S=j;
    //                     }
    //                     p1[1].F=i;
    //                     p1[1].S=j;
    //                     top=i;
    //                 }
    //                 if(n-1-j<=right)
    //                 {
    //                     if(n-1-j<right)
    //                     {
    //                         p2[0].F=i;
    //                         p2[0].S=j;
    //                     }
    //                     p2[1].F=i;
    //                     p2[1].S=j;right=n-1-j;
    //                 }
    //                 if(m-1-i<=down)
    //                 {
    //                     if(m-1-i<down)
    //                     {
    //                         p3[0].F=i;
    //                         p3[0].S=j;
    //                     }
    //                     p3[1].F=i;
    //                     p3[1].S=j;down=m-1-i;
    //                 }
    //                 if(j<=left)
    //                 {
    //                     if(j<left)
    //                     {
    //                         p4[0].F=i;
    //                         p4[0].S=j;
    //                     }
    //                     p4[1].F=i;
    //                     p4[1].S=j;left=j;
    //                 }
    //             int te1=abs(i-m/2),te2=abs(j-n/2);
    //             if(m%2==0)
    //                 te1-=1;
    //             if(n%2==0)
    //                 te2-=1;
    //             if(te1<=mid_hor or te2<=mid_ver)
    //             {
    //                 if(te1<mid_hor or te2<mid_ver)
    //                 {
    //                     p5[0].F=i;
    //                     p5[0].S=j;
    //                 }
    //                 p5[1].F=i;
    //                 p5[1].S=j;mid_hor=te1;
    //                 mid.push_back(p5[0]);
    //                 mid.push_back(p5[1]);
    //                 mid_ver=te2;
    //             }
    //         }
    //         }
    //         // mid.push_back(p5[0]);
    //         // mid.push_back(p5[1]);
    //     }
    //     int ans=INF;
    //     if(top==INF and left==INF and right ==INF and down==INF)
    //     {
    //         cout<<"0"<<endl;
    //         continue;
    //     }
    //     f(i,0,20+mid.size())
    //         save[i]=INF;
    //     f(i,0,m)
    //     {
    //         f(j,0,n)
    //         {
    //             if(a[i][j]==max_el)
    //             {
    //                 temp[0]=max(abs(p1[0].F-i),abs(p1[0].S-j));
    //                 temp[1]=max(abs(p1[1].F-i),abs(p1[1].S-j));
    //                 temp[2]=max(abs(p2[0].F-i),abs(p2[0].S-j));
    //                 temp[3]=max(abs(p2[1].F-i),abs(p2[1].S-j));
    //                 temp[4]=max(abs(p3[0].F-i),abs(p3[0].S-j));
    //                 temp[5]=max(abs(p3[1].F-i),abs(p3[1].S-j));
    //                 temp[6]=max(abs(p4[0].F-i),abs(p4[0].S-j));
    //                 temp[7]=max(abs(p4[1].F-i),abs(p4[1].S-j));
    //                 temp[8]=max(abs(p5[0].F-i),abs(p5[0].S-j));
    //                 temp[9]=max(abs(p5[1].F-i),abs(p5[1].S-j));
    //                 f(l,0,mid.size())
    //                 {
    //                     temp[10+l]=max(abs(mid[l].F-i),abs(mid[l].S-j));
    //                 }
    //                 f(k,0,10+mid.size())
    //                 {
    //                     if(temp[k]<save[k])
    //                         save[k]=temp[k];
    //                 }
    //                 //ans=min(ans,*(max_element(save,save+4)));
    //             }
    //         }
    //     }
    //     ans=*(max_element(save,save+10+mid.size()));
    //     cout<<ans<<endl;
    //     mid.clear();
        int n=10099000000;
     }
    cin>>t;
    return 0;
} 
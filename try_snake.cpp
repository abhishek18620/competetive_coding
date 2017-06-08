#include <bits/stdc++.h>
#define M 500
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
int save[4]={INF,INF,INF,INF};

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
        ll max_el=-1,cnt=0;
        f(i,0,m)
        {
            f(j,0,n)
            {
                scanl(a[i][j]);
                if(a[i][j] > max_el)
                    max_el=a[i][j];
            }
        }
        int top=INF,left=INF,right=INF,down=INF,mid_hor=INF,mid_ver=INF;
        pai p1[2],p2[2],p3[2],p4[2],p5[2],p6[2];
        f(i,0,m)
        {
            f(j,0,n)
            {
                if(a[i][j]!=max_el)
                {
                    if(i<=top)
                    {
                        if(i<top)
                        {
                            p1[0].F=i;
                            p1[0].S=j;
                        }
                        p1[1].F=i;
                        p1[1].S=j;
                        top=i;
                    }
                    if(n-1-j<=right)
                    {
                        if(n-1-j<right)
                        {
                            p2[0].F=i;
                            p2[0].S=j;
                        }
                        p2[1].F=i;
                        p2[1].S=j;right=n-1-j;
                    }
                    if(m-1-i<=down)
                    {
                        if(m-1-i<down)
                        {
                            p3[0].F=i;
                            p3[0].S=j;
                        }
                        p3[1].F=i;
                        p3[1].S=j;down=m-1-i;
                    }
                    if(j<=left)
                    {
                        if(j<left)
                        {
                            p4[0].F=i;
                            p4[0].S=j;
                        }
                        p4[1].F=i;
                        p4[1].S=j;left=j;
                    }
                    if(abs(i-m/2)<=mid_hor)
                    {
                        if(abs(i-m/2)<mid_hor)
                        {
                            p5[0].F=i;
                            p5[0].S=j;
                        }
                        p5[1].F=i;
                        p5[1].S=j;mid_hor=abs(i-m/2);
                    }
                    if(abs(j-n/2)<=mid_ver)
                    {
                        if(abs(j-n/2)<mid_ver)
                        {
                            p6[0].F=i;
                            p6[0].S=j;
                        }
                        p6[1].F=i;
                        p6[1].S=j;mid_hor=abs(i-n/2);
                    }
                }
            }
        }
        // int top_mid=(p1[1].S-p1[0].S)/2;
        // int right_mid=(p2[1].F-p2[0].F)/2;
        // int down_mid=(p3[1].S-p3[0].S)/2;
        // int left_mid=(p4[1].F-p4[0].F)/2;
        // //top
        // int temp1,temp2;
        // temp1=temp2=p1[0].S+top_mid;
        // int x=p1[1].F;
        // p1[2].F=x; p1[2].S=p1[0].S;
        // while(temp1!=p1[0].S)
        // {
        //     if(a[x][temp1]!=max_el)
        //     {
        //         p1[2].F=x;
        //         p1[2].S=temp1;
        //         break;
        //     }
        //     else if(a[x][temp2]!=max_el)
        //     {
        //         p1[2].F=x;
        //         p1[2].S=temp2;
        //         break;
        //     }
        //     temp1--; temp2++;
        // }
        // //down
        // temp1=temp2=p3[0].S+down_mid;
        // x=p3[1].F;
        // p3[2].F=x; p3[2].S=p3[0].S;
        // while(temp1!=p3[0].S)
        // {
        //     if(a[x][temp1]!=max_el)
        //     {
        //         p3[2].F=x;
        //         p3[2].S=temp1;
        //         break;
        //     }
        //     else if(a[x][temp2]!=max_el)
        //     {
        //         p3[2].F=x;
        //         p3[2].S=temp2;
        //         break;
        //     }
        //     temp1--; temp2++;
        // }
        // //right
        // temp1=temp2=p2[0].F+right_mid;
        // x=p2[1].S;
        // p2[2].F=p2[0].F; p2[2].S=x;
        // while(temp1!=p2[0].F)
        // {
        //     if(a[temp1][x]!=max_el)
        //     {
        //         p2[2].F=temp1;
        //         p2[2].S=x;
        //         break;
        //     }
        //     else if(a[temp2][x]!=max_el)
        //     {
        //         p2[2].F=temp2;
        //         p2[2].S=x;
        //         break;
        //     }
        //     temp1--; temp2++;
        // }
        // //left
        // temp1=temp2=p4[0].F+left_mid;
        // x=p4[1].S;
        // p4[2].F=p4[0].F; p4[2].S=x;
        // while(temp1!=p4[0].F)
        // {
        //     if(a[temp1][x]!=max_el)
        //     {
        //         p4[2].F=temp1;
        //         p4[2].S=x;
        //         break;
        //     }
        //     else if(a[temp2][x]!=max_el)
        //     {
        //         p4[2].F=temp2;
        //         p4[2].S=x;
        //         break;
        //     }
        //     temp1--; temp2++;
        // }


        int temp[4];
        int ans=INF;
        if(top==INF and left==INF and right ==INF and down==INF)
        {
            cout<<"0"<<endl;
            continue;
        }
        f(i,0,4)
            save[i]=INF;
        f(i,0,m)
        {
            f(j,0,n)
            {
                if(a[i][j]==max_el)
                {
                    temp[0]=max(max(abs(p1[0].F-i),abs(p1[0].S-j)), max(max(abs(p1[1].F-i),abs(p1[1].S-j)), max(abs(p1[2].F-i),abs(p1[2].S-j))));
                    temp[1]=max(max(abs(p2[0].F-i),abs(p2[0].S-j)), max(max(abs(p2[1].F-i),abs(p2[1].S-j)), max(abs(p2[2].F-i),abs(p2[2].S-j))));
                    temp[2]=max(max(abs(p3[0].F-i),abs(p3[0].S-j)), max(max(abs(p3[1].F-i),abs(p3[1].S-j)), max(abs(p3[2].F-i),abs(p3[2].S-j))));
                    temp[3]=max(max(abs(p4[0].F-i),abs(p4[0].S-j)), max(max(abs(p4[1].F-i),abs(p4[1].S-j)), max(abs(p4[2].F-i),abs(p4[2].S-j))));
                    f(k,0,4)
                    {
                        if(temp[k]<save[k])
                            save[k]=temp[k];
                    }
                    //ans=min(ans,*(max_element(save,save+4)));
                }
            }
        }
        ans=*(max_element(save,save+4));
        cout<<ans<<endl;
    }
    cin>>t;
	return 0;
}
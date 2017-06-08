    #include <bits/stdc++.h>
    #define f(i, j, k) for (int i = j; i < k; i++)
    #define f1(i, j, k, l, n) for (i = k, j = l; i < n and j < n; i++, j++)
    #define N 501
    //typedef long long LLi;
    using namespace std;
    int arr[N][N];
    int M = 1000;
     
    struct node
    {
        int ba;
        int u;
        int v;
    };
    bool operator<(const node &a, const node &b)
    {
        return a.ba < b.ba;
    }
     
    int min_band(priority_queue<node> &pq, int k)
    {
        int i_band=0,preband=0;
        int s_save = 0;
        bool check;
        // while(!pq.empty())
        // {
        //     cout<<pq.top().ba<<endl;
        //     pq.pop();
        // }
        while (!pq.empty())
        {
            i_band = pq.top().ba;
            if(i_band < preband)
                return preband;
            else
                preband=i_band;
            node n = pq.top();
            pq.pop();
            int x = n.u, y = n.v;
            int b1 = n.ba, b2 = n.ba, x1, x2, y1, y2;
            if (x==y+s_save or y==x+s_save)
            {
                //cout<<"x  = "<<x<<" y  = "<<y<<"\n";
                return s_save;
            }
            else
            {
                bool flag =1;
                f(s, s_save, k)
                {
                    if(!flag)
                        break;
                    int i, j;
                    f1(i, j, s, 0, k) if (!arr[i][j] and b1 > abs(i-j)) // lower diagonal search for vac
                    {
                        b1 = abs(i - j);
                        x1 = i;
                        y1 = j;
                        flag = 0;
                        s_save = s;
                        break;
                    }
     
                    if (flag)
                    {
                        int s1;
                        if (s == 0)
                            s1 = s + 1;
                        else
                            s1 = s;
                        int i, j;
                        f1(i, j, 0, s1, k) if (!arr[i][j] and b1 > abs(i-j)) // upper diagonal search for vac
                        {
                            b2 = abs(i - j);
                            x2 = i;
                            y2 = j;
                            s_save = s1;
                            flag = 0;
                            break;
                        }
                    }
                }
                check = flag;
            }
     
            // if (!pq.empty())
            //     ok = pq.top().ba;
     
            // now swap according to b1 and b2
            if (b1 <= b2 and x1 < k and y1 < k and !check)
            {
                swap(arr[x1][y1] ,arr[x][y]);
              //  cout<<"swap "<<x+1<<"  "<<y+1<<"---->  "<<x1+1<<"  "<<y1+1<<"\n";
                preband=abs(x1-y1);
            }
            else if (b2 < b1 and x2 < k and y2 < k and !check)
            {
                swap(arr[x2][y2] , arr[x][y]);
            //    cout<<"swap "<<x+1<<"  "<<y+1<<"---->  "<<x2+1<<"  "<<y2+1<<"\n";
                preband=abs(x2-y2);
            }
        }
        return preband;
    }
     
    void scan(int &x){
        	register int c = getchar_unlocked();
        	x = 0;
        	for(;c<48 || c>57;c=getchar_unlocked());
        	for(;c>47 && c<58;c=getchar_unlocked())
        		x=(x<<1)+(x<<3)+c-48;
        }
     
    int main()
    {
        int t;
        scan(t);
        while (t--)
        {
            int n;
            scan(n);
            int iband = 0;
            priority_queue<node> pq;
            f(i, 0, n)
            {
                f(j, 0, n)
                {
                    scan(arr[i][j]);
                    if (arr[i][j])
                    {
                        int te = abs(i - j);
                        if (te != 0)
                        {
                            node n1 = {te, i, j};
                            pq.push(n1);
                        }
                    }
                }
            }
            if (pq.empty())
                cout<<"0"<< "\n";
            else
            {
                int form = pq.top().ba;
                int ans = min_band(pq, n);
                if (ans == M)
                    cout<< form << "\n";
                else
                    cout<< ans << "\n";
            }
        }
        return 0;
    } 
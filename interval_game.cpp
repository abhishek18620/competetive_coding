    #include <bits/stdc++.h>
    using namespace std;
    const int N=3e5+5;
    const int K=205;
     
    int t,n,k,a[N],b[K];
    long long sum[N],c[K][N];
    deque<long long> dq;
     
    void push(long long x){
    	while (dq.size()&&dq.back()<x){
    		dq.pop_back();
    	}
    	dq.push_back(x);
    }
     
    void pop(long long x){
    	if (dq.front()==x){
    		dq.pop_front();
    	}
    }
     
    int main(){
    	// ios::sync_with_stdio(0);
    	// cin.tie(0);
    	cin >> t;
    	while (t--){
    		cin >> n >> k;
    		for (int i=1;i<=n;i++){
    			cin >> a[i];
    			sum[i]=sum[i-1]+a[i];
    		}
    		for (int i=1;i<=k;i++){
    			cin >> b[i];
    		}
    		for (int i=1;i+b[k]-1<=n;i++){
    			c[k][i]=sum[i+b[k]-1]-sum[i-1];
    		}
    		for (int i=k-1;i>=1;i--){
    			dq.clear();
    			int pos=0;
    			for (int j=1;j+b[i]-1<=n;j++){
    				while (pos+1+b[i+1]-1<j+b[i]-1){
    					push(c[i+1][++pos]);
    				}
    				pop(c[i+1][j]);
    				c[i][j]=sum[j+b[i]-1]-sum[j-1]-
    				dq.front();
    			}
    		}
    		long long ans=INT_MIN;
    		for (int i=1;i+b[1]-1<=n;i++){
    			ans=max(ans,c[1][i]);
    		}
    		cout << ans << "\n";
    	}
        cin>>t;
    } 
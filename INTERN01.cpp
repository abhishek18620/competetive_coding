#include <stdio.h>
#include <stdlib.h>

// you may add more methods here
const int INT_MAX = 100009;
inline int min(int a,int b) {
  return (a < b) ? a:b;
}

inline int max(int a,int b) {
  return (a > b) ? a:b;
}


struct node {
  int hor,ver,count;
};

struct node dp[110][110];

int calculate(int x, int y) {
  // u ---> v
  int u = x;
  int v = y;
  int left = dp[x][y].hor - 1;
  int up = dp[x][y].ver - 1;
  int range = min(left, up);
  int cnt = 0;
  while(cnt <= range) {
    cnt++;
    u--;
    v--;
    if(dp[u][v].count == 1)
      break;
  }
  int algx = INT_MAX;
  int algy = INT_MAX;
  for(int i =u; i <=x; i++) {
    algx = min(algx, dp[i][v].hor -1);
  }
  for(int j =v; j <= y; j++) {
    algy = min(algy, dp[u][j].ver - 1);
  }
  return ((cnt*cnt)+cnt+cnt+1)+ max((x-u+1)*algx, (y-v+1)*algy);
}

int greatestSortedSubmatrix(int matrixSize, int matrix[100][100]) {
    //add code to this function to solve the problem
    //don't write code in this editor
    //your code will not be saved across submissions
  int n = matrixSize;
  for(int i = 0; i < n; i++) {
    for(int j =0; j < n; j++) {
      dp[i][j].hor=1;
      dp[i][j].ver=1;
      dp[i][j].count=1;
    }
  }

  for(int j = 1; j < n; j++) {
    if(matrix[0][j] >= matrix[0][j-1]) {
      dp[0][j].hor += dp[0][j-1].hor;
    }
  }

  for(int i = 1; i<n; i++) {
    if(matrix[i][0] >= matrix[i-1][0]) {
      dp[i][0].ver += dp[i-1][0].ver;
    }
  }

  for(int i =1; i< n;i++) {
    for(int j=1; j < n ;j++) {
      if(matrix[i][j] >= matrix[i-1][j]) {
        dp[i][j].ver = dp[i][j].ver + dp[i-1][j].ver;
      }
      if(matrix[i][j] >= matrix[i][j-1]) {
        dp[i][j].hor = dp[i][j].hor + dp[i][j-1].hor;
      }

      if(matrix[i][j] >= matrix[i-1][j] && matrix[i][j] >= matrix[i][j-1] && matrix[i-1][j] >= matrix[i-1][j-1] && matrix[i][j-1] >= matrix[i-1][j-1]) {
        dp[i][j].count = calculate(i,j);
      }
    }
  }
  int ans = -1;
  for(int i =0; i<n; i++) {
    for(int j =0; j<n; j++) {
      //printf("%d %d %d\n", i,j, dp[i][j]);
      ans=max(ans, dp[i][j].hor);
      ans=max(ans, dp[i][j].ver);
      ans=max(ans, dp[i][j].count);
    }
  }
  return ans;
}

int main() {
    int N;
    int A[100][100];
    int i, j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&A[i][j]);
    printf("%d\n",greatestSortedSubmatrix(N,A));
    return 0;
}

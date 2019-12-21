// https://leetcode.com/problems/maximum-subarray/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int Solve(std::vector<int>& arr) {
  int N = arr.size();
  std::vector<int> dp(N+1, 0);
  dp[0] = arr[0];
  int sol = arr[0];
  for(int i = 1; i < N; i++) {
    dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
    sol = std::max(sol, dp[i]);
  }
  return dp[N-1];
}

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> arr(N);
  for(int i =0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%d", Solve(arr));
  return 0;
}

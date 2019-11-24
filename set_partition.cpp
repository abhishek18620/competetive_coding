//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

void solve(std::vector<int>& arr) {
  int n = arr.size();
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  std::vector<std::vector<bool> > dp(n+ 1, std::vector<bool> (sum+1));
  // base cases
  for(int i = 1; i < n; i++) {
    // sum could be 0 with all elements considered
    dp[i][0] = true;
  }
  for(int j = 0; j < sum+1; j++) {
    dp[0][j] = false;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dp[i][j] = dp[i - 1][j]
    }
  }
  return;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  solve(arr);
  return 0;
}


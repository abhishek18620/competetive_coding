// https://leetcode.com/problems/frog-jump/
#include <iostream>
#include <unordered_map>
#include <vector>

int GetIdxOfStoneX(const std::vector<int>& arr, const int x) {
  if (x < 0) {
    return false;
  }
  int left  = 0;
  int right = arr.size() - 1;
  int mid;
  while (left <= right) {
    mid = left + ((right - left) >> 1);
    if (arr[mid] == x) {
      return mid;
    }
    if (arr[mid] > x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

bool Solve(const std::vector<int>& arr) {
  const int                     n = arr.size();
  std::vector<std::vector<int>> dp(n);
  // base case
  dp[0].push_back(0);
  for (int des_stone = 1; des_stone < n; ++des_stone) {
    for (int src_stone = 0; src_stone < des_stone; ++src_stone) {
      for (const int jump : dp[src_stone]) {
        if (arr[des_stone] == arr[src_stone] + jump - 1) {
          dp[des_stone].push_back(jump - 1);
          break;
        } else if (arr[des_stone] == arr[src_stone] + jump) {
          dp[des_stone].push_back(jump);
          break;
        } else if (arr[des_stone] == arr[src_stone] + jump + 1) {
          dp[des_stone].push_back(jump + 1);
          break;
        }
      }
    }
  }
  return !dp[n - 1].empty();
}
int main() {
  freopen("large_input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (int& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  auto sol = Solve(arr);
  printf("here\n");
  printf("%s: solution = %s\n", __func__, sol ? "true" : "false");
  return 0;
}

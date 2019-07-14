// Given two sorted arrays , find the median of their merged ouput in O(logn)
#include <iostream>
#include <vector>
#include <algorithm>

inline int FindMid(int &lo, int& hi) {
  return lo + ((hi - lo) >> 1);
}

float Solve(std::vector<int> &arr1, std::vector<int> &arr2) {
  float sol = 0.0;
  if (arr1.size() > arr2.size()) {
    // assuming arr1 smaller than arr2 in size
    arr1.swap(arr2);
  }
  int lo1 = 0;
  int hi1 = arr1.size();
  while (lo1 <= hi1) {
    int partition1 = FindMid(lo1, hi1);
    int partition2 = ((arr1.size() + arr2.size() + 1) >> 1) - partition1;
    std::cout << partition1 << "  " << partition2 << std::endl;
    std::cout << arr1[partition1] << "  " << arr2[100] << std::endl;
    if (arr1[partition1] <= arr2[partition2 + 1] &&
        arr1[partition1 + 1] >= arr2[partition2]) {
      sol = (std::max(arr1[partition1], arr2[partition2]) +
             std::min(arr1[partition1 + 1], arr2[partition2 + 1])) >> 1;
      break;
    }
    else if(arr1[partition1] > arr2[partition2 + 1]) {
      // move left
      hi1 = partition1 - 1;
    }
    else {
      // move right
      lo1 = partition1 + 1;
    }
  }
  return sol;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> arr1 = {1, 2};
  std::vector<int> arr2(m);
  std::cout << arr1[100]<< " " << arr2[100]<< std::endl;
  for(int i = 0; i < n; i++) {
    std::cin >> arr1[i];
  }
  for(int i = 0; i < m; i++) {
    std::cin >> arr2[i];
  }
  std::cout << Solve(arr1, arr2) << std::endl;
  return 0;
}

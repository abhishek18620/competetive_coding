// Given two sorted arrays , find the median of their merged ouput in O(logn)
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>


int BinarySearch(std::vector<int>& arr, const int& ele, int& start, int& end) {
  int lo = start;
  int hi = end;
  int mid = -1;
  while(lo <= hi) {
    mid = lo + ((hi - lo) >> 1);
    if(arr[mid] == ele) {
      return mid + 1;
    }
    if(arr[mid] > ele) {
      // move left
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
  printf("element to be found %d and idx = %d\n", ele, (arr[mid] > ele) ? mid : mid+1);
  return (arr[mid] > ele) ? mid : mid+1;
}

int FindTargetIndex(std::vector<int>& nums1, std::vector<int>& nums2, int& target1) {
  int sz1 = nums1.size();
  int sz2 = nums2.size();
  int lo1 = 0;
  int lo2 = 0;
  int hi1 = sz1 - 1;
  int hi2 = sz2 - 1;
  int mid1 = -1;
  while(lo1 <= hi1) {
    mid1 = lo1 + ((hi1 - lo1) >> 1);
    int index_in_arr2 = BinarySearch(nums2, nums1[mid1], lo1, hi1);
    printf("Final idx for %d in merged array %d\n", nums1[mid1], index_in_arr2 + mid1);
    if(mid1 + index_in_arr2 == target1) {
      return nums1[mid1];
    }
    else if(mid1 + index_in_arr2 > target1) {
      hi1 = mid1 - 1;
      hi2 = index_in_arr2 - 1;
    }
    else {
      lo1 = mid1 + 1;
      lo2 = index_in_arr2 + 1;
    }
  }
  return -1;
}

double FindMedianSortedArrays(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
  int sz1 = nums1.size();
  int sz2 = nums2.size();
  int target1 = (sz1 + sz2) >> 1;
  int target2 = -1;
  std::pair<double, double> sol;
  if (!((sz1 + sz2) & 1)) {
    // even number of elements
    target2 = target1 - 1;
    std::swap(target1, target2);
  }
  sol.first = FindTargetIndex(nums1, nums2, target1);
  printf("First attempt = %f\n", sol.first);
  if (sol.first != -1.0) {
    if (target2 != -1.0) {
      sol.second = FindTargetIndex(nums1, nums2, target2);
      if (sol.second == -1.0) {
        // swap vectors
        nums1.swap(nums2);
        sol.second = FindTargetIndex(nums1, nums2, target2);
      }
    }
  }
  else {
    nums1.swap(nums2);
    sol.first = FindTargetIndex(nums1, nums2, target1);
    printf("Second attempt = %f\n", sol.first);
    if(target2 != -1.0) {
      sol.second = FindTargetIndex(nums1, nums2, target2);
    }
  }

  if(target2 != -1.0) {
    return (sol.first + sol.second)/2;
  }
  return sol.first;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n = 0;
  int m = 0;
  std::cin >> m >> n;
  std::vector<int> nums1(m);
  std::vector<int> nums2(n);
  for(int i = 0; i < m; i++) {
    std::cin >> nums1[i];
  }
  for(int i = 0; i < n; i++) {
    std::cin >> nums2[i];
  }
  std::cout << FindMedianSortedArrays(nums1, nums2) << std::endl;
  return 0;
}

// Q) Mth order statistic
/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-02-21
 *  File : leetcode3.cpp
 *******************************************/
#pragma comment(linker, "/ STACK: 100000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//-------------------------MACROS-------------------------------
#define trace2(x, y)                                                           \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                                                        \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z      \
            << ": " << z << endl;
#define trace4(a, b, c, d)                                                     \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c      \
            << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)                                                  \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c      \
            << ": " << c << " | " << #d << ": " << d << " | " << #e << ": "    \
            << e << endl;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

/**
 * @brief returns the median of first, last and middle
 *
 * @return index of the median and store median in the median variable
 */
int FindMiddle(std::vector<int> &arr, int &median, int l, int r) {
  int a = arr[l];
  int b = arr[(r - l + 1) >> 1];
  int c = arr[r];
  // Checking for b
  if ((a < b && b < c) || (c < b && b < a)) {
    median = b;
    return (r - l + 1) >> 1;
  }
  // Checking for a
  else if ((b < a && a < c) || (c < a && a < b)) {
    median = a;
    return l;
  }
  median = c;
  return r;
}

/**
 * @brief place the pivot element at the right index such that
 *        pivot > arr[i] for all i < pivot_index
 *        pivot < arr[i] for all i > pivot_index
 *
 * @return index of the pivot
 */
int PlaceThePivot(std::vector<int> &arr, int l, int r) {
  int median = -1;
  int median_ind = FindMiddle(arr, median, l, r);
  int pivot_index = l;
  std::swap(arr[r], arr[median_ind]);
  for (int i = l; i < r; ++i) {
    // arr[i] > median
    if (arr[i] < median) {
      std::swap(arr[i], arr[pivot_index]);
      pivot_index++;
    }
  }
  std::swap(arr[pivot_index], arr[r]);
  return pivot_index;
}

/**
 * @brief Calcultes mth order statistic. Derived from quicksort partition
 *        method.
 */
int partition(std::vector<int> &arr, int l, int r, int m) {
  // if m is greater than number of elements between l and r
  if (m > 0 and m <= r - l + 1) {
    int pivot_index = PlaceThePivot(arr, l, r);
    if (pivot_index - l == m - 1) {
      return arr[pivot_index];
    }
    // Kth order statistic lies in the right subarray
    else if (pivot_index - l <= m - 1) {
      return partition(arr, pivot_index + 1, r, m - pivot_index + l - 1);
    }
    // Kth order statistic lies in left subarray
    return partition(arr, l, pivot_index - 1, m);
  }
  return INF;
}

int Solve(std::vector<int> &arr, int &n, int &m) {
  // Replce m with (n - m + 1) for Mth Largest element
  return partition(arr, 0, n - 1, m);
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
  int n, m;
  scanf("%d %d", &n, &m);
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  std::cout << Solve(arr, n, m) << std::endl;
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
            << " s.\n";
#endif
  return 0;
}

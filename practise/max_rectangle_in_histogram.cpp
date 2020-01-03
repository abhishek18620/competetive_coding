// https://leetcode.com/problems/largest-rectangle-in-histogram/

// clang-format off
/* (Other approach)
 * Can also be solved using divide and conquer the partition would
 * be minimum of subarray (i, j) = k then divide the problems in
 * sol = std::max(sol, std::max(arr[k]*(j-i+1), std::max(Solve(i, k-1), Solve(k+1, n)))
 */
// clang-format on
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int Solve(std::vector<int>& arr) {
  int sol = 0;
  int n = arr.size();
  std::stack<int> st; // stack storing indices
  int curr_idx;
  for (int i = 0; i < n;) {
    if (st.empty() || arr[st.top()] <= arr[i]) {
      st.push(i);
      i++;
    } else {
      // top element is  greater than arr[i] calculate area now and pops
      curr_idx = st.top();
      st.pop();
      sol = std::max(sol, arr[curr_idx] * (st.empty() ? i : i - st.top() - 1));
    }
  }
  // now find areas from all mins left in stack
  while (!st.empty()) {
    curr_idx = st.top();
    st.pop();
    sol = std::max(sol, arr[curr_idx] * (st.empty() ? n : n - st.top() - 1));
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (auto& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s : solution : %d\n", __func__, Solve(arr));
  return 0;
}

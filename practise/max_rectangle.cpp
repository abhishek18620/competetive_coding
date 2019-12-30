// https://leetcode.com/problems/maximal-rectangle/
#include <iostream>
#include <stack>
#include <vector>

// https://leetcode.com/problems/largest-rectangle-in-histogram/
static int CalcMaxRectangleInHist(std::vector<int>& arr) {
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

int Solve(const std::vector<std::vector<char>>& grid) {
  if (grid.size() == 0) {
    return 0;
  }

  int m = grid.size();
  int n = grid[0].size();
  // stores heights of all histograms forming from level i
  std::vector<int> histogram_height(n);
  int sol = 0;
  // forms the histograms for each level
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '0') {
        histogram_height[j] = 0;
        continue;
      }
      // if '1'
      histogram_height[j] = histogram_height[j] + 1;
    }
    for (auto ele : histogram_height) {
      printf("%d   ", ele);
    }
    printf("\n");
    printf("%s: i = %d sol = %d\n", __func__, i,
           CalcMaxRectangleInHist(histogram_height));
    sol = std::max(sol, CalcMaxRectangleInHist(histogram_height));
  }

  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m;
  int n;
  scanf("%d %d", &m, &n);
  printf("%s: m = %d  n = %d\n", __func__, m, n);
  std::vector<std::vector<char>> grid(m, std::vector<char>(n));
  char ch;
  for (int i = 0; i < m; i++) {
    scanf("%c", &ch); // to ignore '\n' in the end of each line of input
    for (int j = 0; j < n; j++) {
      scanf("%c", &grid[i][j]);
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%c  ", grid[i][j]);
    }
    printf("\n");
  }

  printf("%s: solution = %d\n", __func__, Solve(grid));
  return 0;
}

#include <algorithm>
#include <iostream>

constexpr int INF = 1e9 + 9;
int N;
int dp[100][100];
int arr[100];
int popu[100];
int pre_sum[100];

float calc_avg_from_new_j(int new_po, int last_po) {
  // when last po is at j then nearest po changes for mid_j_i to N
  int mid_i_j = (last_po + new_po) >> 1;
  int ret = (pre_sum[N] - pre_sum[mid_i_j]) * (new_po - last_po);
  return (float)ret / N;
}

int solve(int i, int po_to_be_built) {
  if (i == N || po_to_be_built == 0) {
    return 0;
  }

  if (dp[i][po_to_be_built] != -1) {
    return dp[i][po_to_be_built];
  }

  // dp begins
  // built a PO at ith village
  int sol1 = INF;
  for (int j = 0; j < i; j++) {
    sol1 = std::min<float>((float)sol1, solve(j, po_to_be_built - 1) +
                                            calc_avg_from_new_j(i, j));
  }
  // don't build a PO here
  int sol2 = INF;
  int villages_left = N - i + 1;
  if (po_to_be_built < villages_left) {
    sol2 = solve(i - 1, po_to_be_built - 1);
  }

  return std::min<float>(sol1, sol2);
}

int main() {
  std::cin >> N;
  // pre compute sum
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
    std::cin >> popu[i];
    pre_sum[i] = (i > 0) ? pre_sum[i - 1] + popu[i] : pre_sum[i];
  }
  return 0;
}

// https://leetcode.com/problems/range-sum-query-immutable/
/*
 * Segment Tree
 */

#include <iostream>
#include <vector>

struct Node {
  int left;
  int right;
  int sum;
  Node* left_child = nullptr;
  Node* right_child = nullptr;
  Node(const int& val, const int& l, const int& r) {
    sum = val;
    left = l;
    right = r;
  }
  void MergeTwoNodes(Node& l, Node& r) { sum = l.sum + r.sum; }
};

int QueryRSQ(const Node* node, const int& l, const int& r) {
  if (node == nullptr) {
    return 0;
  }
  int node_left = node->left;
  int node_right = node->right;
  if (node_left == l && node_right == r) {
    return node->sum;
  }
  /*
   * 2 cases
   * 1) coincide range
   * 2) partially in range
   */
  int node_mid = node_left + ((node_right - node_left) >> 1);
  // NOTE: Don't put equality in first two cases
  if (r < node_mid) {
    return QueryRSQ(node->left_child, l, r);
  } else if (l > node_mid) {
    return QueryRSQ(node->right_child, l, r);
  } else if (l <= node_mid && r >= node_mid) {
    return QueryRSQ(node->left_child, l, node_mid) +
           QueryRSQ(node->right_child, node_mid + 1, r);
  }
  return 0;
}

Node* BuildSegmentTree(std::vector<int>& arr, int l, int r) {
  if (l > r) {
    return nullptr;
  }
  if (l == r) {
    return new Node(arr[l], l, r);
  }
  int mid = l + ((r - l) >> 1);
  Node* left = BuildSegmentTree(arr, l, mid);
  Node* right = BuildSegmentTree(arr, mid + 1, r);
  Node* ret = new Node(0, l, r);
  ret->left_child = left;
  ret->right_child = right;
  ret->MergeTwoNodes(*left, *right);
  return ret;
}

Node* SolveSegmentTree(std::vector<int>& arr) {
  int n = arr.size();
  Node* root = BuildSegmentTree(arr, 0, n - 1);
  return root;
}

std::vector<std::vector<int>> SolveDP(std::vector<int>& arr) {
  int n = arr.size();
  std::vector<std::vector<int>> dp(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = arr[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      dp[i][j] = dp[i][j - 1] + arr[j];
    }
  }
  return dp;
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
  auto sum_i_j = SolveDP(arr);
  Node* root = SolveSegmentTree(arr);
  printf("%s: (%d, %d) root sum = %d\n", __func__, root->left, root->right,
         root->sum);
  int queries;
  scanf("%d", &queries);
  for (int i = 0; i < queries; ++i) {
    int u;
    int v;
    scanf("%d %d", &u, &v);
    printf("%s:    DP    = (%d, %d) = %d\n", __func__, u, v, sum_i_j[u][v]);
    printf("%s: SEG TREE = (%d, %d) = %d\n", __func__, u, v,
           QueryRSQ(root, u, v));
  }
  return 0;
}

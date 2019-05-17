/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-05-17
 *  File : LinkedList.cpp
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
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                        \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << std::endl;
#define trace4(a, b, c, d)                                                     \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                  \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << std::endl;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

struct node {
  int ele;
  node *left;
  node *right;
  int freq;
};

node* create_node(int ele) {
  node *temp = new node;
  temp->ele = ele;
  temp->left = NULL;
  temp->right = NULL;
  temp->freq = 1;
  return temp;
}

void insert(node* root, int &ele, int &prev, int &next, bool &repeat) {
  if(root == NULL) {
    root = create_node(ele);
  }
  if(ele > root->ele) {
    if(root->ele > prev) {
      prev = root->ele;
    }
    if(root->right != NULL) {
      insert(root->right, ele);
      return;
    }
    else {
      root->right = create_node(ele);
    }
  }
   if(ele < root->ele) {
     if(root->ele < next) {
       next = root->ele;
     }
     if(root->left != NULL) {
       insert(root->left, ele);
       return;
     }
    else {
      root->left = create_node(ele);
    }
  }
  if(ele == root->ele) {
    root->freq++;
    repeat = true;
  }
  return;
}

long long solve(node *root) {
  vector<pair<int, int> > boundary_ind(2*1000000 + 8);
  for (int query = 0; query < q; ++query) {
    int prev = -1;
    int next = n + 9;
    bool repeat = false;
    int ele;
    std::cin >> ele;
    insert(root, ele, prev, next, repeat);
    if(prev == -1) {
      if(repeat) {

      }
      else {
        boundary_ind[ele].first = 1;
      }
    }
    else {
      boundary_ind[ele].first = prev + 1;
      boundary_ind[prev].second = ele - 1;
    }
    if(next == n + 9) {
      boundary_ind[ele].second = n;
    }
    else {
      boundary_ind[ele].second = next - 1;
      boundary_ind[next].first = ele + 1;
    }
    // find sum
    for
  }
}
int n, m;

int traverse(node *start) {

}

void insert() {

}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif
  std::cin >> n >> m;
  node *start = NULL;
  for (int i = 0; i < m; ++i) {
    int ele;
    std::cin >> ele;
    insert(ele);
  }
  // Logic goes here

#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

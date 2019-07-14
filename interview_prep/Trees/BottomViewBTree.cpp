/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-05-19
 *  File : BottomViewBTree.cpp
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

struct Node {
  Node *left;
  Node *right;
  int info;
  int dist; // horizontol distance

  Node(int info) {
    this->info = info;
  }
};

void Print_Bottom_View(Node *root) {
  std::queue <Node *> q;
  std::map <int, int> dict; // map for storing distance, node
  q.push(root);

  while(!q.empty()) {
    Node *curr = q.front();
    q.pop();
    int dist = curr->dist;
    dict[dist] = curr->info;
    // if left child exist
    if(curr->left != NULL) {
      curr->left->dist = dist - 1;
      q.push(curr->left);
    }
    //if right child exist
    if(curr->right != NULL) {
      curr->right->dist = dist + 1;
      q.push(curr->right);
    }
  }
  // if leaf Node
  if(root->left == NULL and root->right == NULL) {
    std::cout << root->info << std::endl;
    return;
  }

  for (auto pai : dict) {
    std::cout << pai.second << std::endl;
  }
  std::cout << std::endl;
  return;
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(5);
  root->left->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(25);
  root->left->right->left = new Node(10);
  root->left->right->right = new Node(14);
  std::cout << "Bottom view of the given binary tree :\n";
  Print_Bottom_View(root);
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
            << " s.\n";
#endif
  return 0;
}

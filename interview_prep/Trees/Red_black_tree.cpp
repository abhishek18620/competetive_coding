/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-07-14
 *  File : Red_black_tree.cpp
 *******************************************/
/**
 A red black tree is a self balancing BStree uses some interesting techniques
 to balance itself (No secret why do we want a Balanced BS Tree)
Rules :
 1) Every node has a color either red or black.

 2) Root of tree is always black.

 3) There are no two adjacent red nodes (A red node cannot have a red parent
 or red child).

 4) Every path from a node (including root) to any of its descendant NULL
 node has the same number of black nodes.
NOTE: Rules are from gfg. So not exactly my language
 IMP
 ---
 1) Insertion
 2) Deletion
**/
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
  int val;
  char color; // R = Red , B = Black
  Node *parent;
  Node *left;
  Node *right;
  Node(int x) : val(x), color('R'), left(NULL), right(NULL) {}
};

char GetUnclesColor(Node *root) {
  root->parent->
}
void Insert(Node *root, int element) {

}

void Delete(int element) {

}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here

#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}

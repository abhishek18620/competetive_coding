// Q) Symmetric binary tree
/*
  Input :
  7
  1 2 2 3 4 4 3

  7
  1 2 2 -1 3 -1 3
 */
/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-02-17
 *  File : leetcode2.cpp
 *******************************************/
#pragma comment(linker, "/ STACK: 100000000")
#include <bits/stdc++.h>
using namespace std;
#define M 1000
#define INF 999999
#define fio                                                                    \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);
typedef long long ll;
#define f(i, j, k) for (int i = j; i < k; i++)
#define fr(i, j, k) for (int i = j; i >= k; i--)
#define gc() getchar_unlocked()
#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb push_back
#define scan(d) scanf("%d", &d)
#define scan2(a, b) scanf("%d %d", &a, &b)
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define scanl(d) scanf("%lld", &d)
#define scanl2(a, b) scanf("%lld %lld", &a, &b)
#define scanl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scanl4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define print(t) printf("%d\n", t)
#define printl(t) printf("%lld\n", t)
#define printstr(t) printf("%s\n", t.c_str())
#define trace2(x, y)                                                           \
  cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                                                        \
  cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << endl;
#define trace4(a, b, c, d)                                                     \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)                                                  \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define eb emplace_back
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifdef LOCAL_DEFINE
#include <assert.h>
#else
#define debug(args...) // Just strip off all debug tokens
#endif

const int MOD = 1000000007;
const double EPS = 1e-6;

int scanstr(char *str) {
  register char c = getchar();
  register int len = 0;
  if (!(~c))
    return -1;
  while (c < 33 && ~c)
    c = getchar();
  while (c != 10 && c != 32 && ~c) {
    str[len] = c;
    c = getchar();
    len++;
  }
  str[len] = '\0';
  return 1;
}
void writel(ll n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  ll i = 10;
  char output_buffer[11];
  output_buffer[10] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
int power(int x, unsigned int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1)
      res = res * x;

    y = y >> 1;
    x = x * x;
  }
  return res;
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Print the pretty version fo btree using post order
 */
void PrintBtree(TreeNode *p, int indent = 0) {
  if (p != NULL) {
    if (p->right) {
      PrintBtree(p->right, indent + 4);
    }
    if (indent) {
      std::cout << std::setw(indent) << ' ';
    }
    if (p->right)
      std::cout << " /\n" << std::setw(indent) << ' ';
    std::cout << p->val << "\n ";
    if (p->left) {
      std::cout << std::setw(indent) << ' ' << " \\\n";
      PrintBtree(p->left, indent + 4);
    }
  }
}

bool CheckRecursive(TreeNode* root1, TreeNode* root2) {
  // empty tree
  if(root1 == NULL and root2 == NULL) {
    return true;
  }

  if(root1 != NULL and root2 != NULL and root1->val == root2->val) {
    return (CheckRecursive(root1->left, root2->right) and CheckRecursive(root1->right, root2->left));
  }

  return false;
}

bool CheckIterative(TreeNode *root) {
  std::queue<std::pair<TreeNode* , TreeNode*>> roots_pair_queue;
  roots_pair_queue.push(std::make_pair(root->left, root->right));
  bool sol = true;
  while(!roots_pair_queue.empty()) {
    auto curr_pair = roots_pair_queue.front();
    roots_pair_queue.pop();
    TreeNode* root1 = curr_pair.first;
    TreeNode* root2 = curr_pair.second;
    if(root1 == NULL and root2 == NULL) {
      continue;
    }
    if(root1 != NULL and root2 != NULL and root1->val == root2->val) {
      roots_pair_queue.push(std::make_pair(root1->left, root2->right));
      roots_pair_queue.push(std::make_pair(root1->right, root2->left));
    }
    else {
      sol = false;
      break;
    }
  }
  return sol;
}

bool isSymmetric(TreeNode* root) {
  if(root == NULL) {
    return true;
  }
  return CheckRecursive(root->left, root->right);
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
  int n;
  cin >> n;
  std::vector <int> arr(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    arr[i] = x;
  }
  TreeNode *root = new TreeNode(arr[0]);
  std::queue<pair<TreeNode*, int>> input_queue;
  input_queue.push(std::make_pair(root, 0));
  while(!input_queue.empty()) {
    TreeNode* temp_root = input_queue.front().first;
    int ind = input_queue.front().second;
    input_queue.pop();
    if(2*ind + 1 < n and arr[2*ind + 1] != -1) {
      TreeNode* left = new TreeNode(arr[2*ind + 1]);
      temp_root->left = left;
      input_queue.push(std::make_pair(left, 2*ind + 1));
    }
    if(2*ind + 2 < n and arr[2*ind + 2] != -1) {
      TreeNode* right = new TreeNode(arr[2*ind + 2]);
      temp_root->right = right;
      input_queue.push(std::make_pair(right, 2*ind + 2));
    }
  }
  //PrintBtree(root);
  std::cout << (isSymmetric(root) ? "Symmetric" : "Not Symmetric") << std::endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
  // cin>>t;
#endif
  return 0;
}

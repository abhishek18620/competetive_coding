/******************************************
 *  Author : abhishek18620
 *  Created On : Wed Aug 23 2017
 *  File : gss1.cpp
 *******************************************/
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long llu;
#define gc() getchar_unlocked()
#define gc() getchar_unlocked()
#define rep(i, x, y) for (i = x; i < y; i++)
#define rrep(i, x, y) for (i = x; i >= y; i--)
#define trv(y, x) for (typeof(x.begin()) y = x.begin(); y != x.end(); y++)
#define MID(x, y) (x + ((y - x) / 2))
using namespace std;

#define M 70000

int A[M];
struct node {
  int bestleftsum, bestrightsum, sum, bestsum;
  void Merge(node &A, node &B) {
    sum = A.sum + B.sum;
    bestleftsum = max(A.bestleftsum, A.sum + B.bestleftsum);
    bestrightsum = max(A.bestrightsum + B.sum, B.bestrightsum);
    bestsum = max(max(A.bestsum, B.bestsum), A.bestrightsum + B.bestleftsum);
  }
  void CreateLeaf(int val) { sum = bestleftsum = bestrightsum = bestsum = val; }
};

node T[M + M + 9];
void init(int index, int l, int r) {
  if (l == r) {
    T[index].CreateLeaf(A[l]);
    return;
  } else {
    int mid = MID(l, r);
    init(2 * index, l, mid);
    init(2 * index + 1, mid + 1, r);
    T[index].Merge(T[2 * index], T[2 * index + 1]);
  }
}

// index = node which covers [l,r]
// u and v = our querying range
// l,r = our editable range
void query(node &result, int l, int r, int u, int v, int index) {
  if (u == l && v == r) {
    result = T[index];
    return;
  } else {
    int mid = MID(l, r);
    // our query range lies in left of mid
    if (mid >= v)
      query(result, l, mid, u, v, 2 * index);
    // pur query range lies in right of mid
    else if (mid < u)
      query(result, mid + 1, r, u, v, 2 * index + 1);
    // partial overlap
    else {
      node left, right;
      query(left, l, mid, u, mid, 2 * index);
      query(right, mid + 1, r, mid + 1, v, 2 * index + 1);
      result.Merge(left, right);
    }
  }
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

void scan(int &x) {
  register int c = gc();
  bool neg = 0;
  x = 0;
  for (; c < 48 || c > 57; c = gc())
    if (c == '-') {
      neg = 1;
      c = gc();
      break;
    }
  for (; c > 47 && c < 58; c = gc())
    x = (x << 1) + (x << 3) + c - 48;
  x *= (neg) ? -1 : 1;
}

void scanl(ll &x) {
  register ll c = gc();
  bool neg = 0;
  x = 0;
  for (; c < 48 || c > 57; c = gc())
    if (c == '-') {
      neg = 1;
      c = gc();
      break;
    }
  for (; c > 47 && c < 58; c = gc())
    x = (x << 1) + (x << 3) + c - 48;
  x *= (neg) ? -1 : 1;
}

int main() {
  //   ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
  int n, t, x, y;
  scan(n);
  for (int i = 0; i < n; i++)
    scan(A[i]);
  init(1, 0, n - 1);
  scan(t);
  node Ans;
  while (t--) {
    scan(x);
    scan(y);
    query(Ans, 0, n - 1, x - 1, y - 1, 1);
    printf("%d\n", Ans.bestsum);
  }
  cin >> n;
  return 0;
}

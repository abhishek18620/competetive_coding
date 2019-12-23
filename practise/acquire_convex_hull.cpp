#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll a[50010], b[50010];

struct Line {
  ll m, c;
};

vector<Line> s;
int ptr;

void add(ll m, ll c) {
  int i, j;
  i = (int)s.size() - 2;
  j = (int)s.size() - 1;
  while (i >= 0) {
    if ((double)(s[i].c - c) / (double)(m - s[i].m) <
        (double)(s[i].c - s[j].c) / (double)(s[j].m - s[i].m)) {
      --i;
      --j;
      s.erase(s.end() - 1);
    } else
      break;
  }
  s.push_back({m, c});
}

ll query(ll x) {
  int n = (int)s.size();
  ll c1, c2;
  while (ptr + 1 < n) {
    c1 = s[ptr].m * x + s[ptr].c;
    c2 = s[ptr + 1].m * x + s[ptr + 1].c;
    if (c2 < c1)
      ptr++;
    else
      break;
  }
  return s[ptr].m * x + s[ptr].c;
}

pair<int, int> v[50010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j;
  ll cost = 0;
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  sort(v, v + n);
  j = 0;
  for (i = 0; i < n; i++) {
    while (j >= 1 && v[i].second >= b[j - 1])
      j--;
    a[j] = v[i].first;
    b[j] = v[i].second;
    j++;
  }
  add(b[0], 0);
  for (i = 0; i < j; i++) {
    cost = query(a[i]);
    if (i + 1 < n)
      add(b[i + 1], cost);
  }
  cout << cost << '\n';
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef DEBUG
void __print(int x) { std::cerr << x; }
void __print(long x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(unsigned x) { std::cerr << x; }
void __print(unsigned long x) { std::cerr << x; }
void __print(unsigned long long x) { std::cerr << x; }
void __print(float x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(long double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const std::pair<T, V> &x) {
  std::cerr << '{';
  __print(x.first);
  std::cerr << ',';
  __print(x.second);
  std::cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  std::cerr << '{';
  for (auto &i : x)
    std::cerr << (f++ ? "," : ""), __print(i);
  std::cerr << "}";
}
void _print() { std::cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    std::cerr << ", ";
  _print(v...);
}
#define debug(x...)                                                            \
  std::cerr << "[" << #x << "] = [";                                           \
  _print(x)

#define PrintSolution(sol...)                                                  \
  std::cerr << __func__ << ": solution = " << sol << std::endl;

#else
#define debug(x...)           // do nothing
#define PrintSolution(sol...) // do nothing
#endif

int Solve(const int n) {
  /** logic here */

  return 0;
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "rt", stdin);
#endif
  int t, m, n, x;
  std::unordered_set<int> ele_set;
  scanf("%d", &t);
  while (t--) {
    bool found = false;
    ele_set.clear();
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
      scanf("%d", &x);
      if (ele_set.find(x) != ele_set.end()) {
        continue;
      }
      ele_set.insert(x);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      if (found || ele_set.find(x) == ele_set.end()) {
        continue;
      } else {
        found = true;
        printf("YES\n");
        printf("1 %d\n", x);
      }
    }

    if (!found) {
      printf("NO\n");
    }
  }
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
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

std::string Solve(const int n, std::vector<int> &arr) {
  /** logic here */
  int ones = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] != 1) {
      break;
    }
    ones++;
  }

  return (ones & 1 ? "Second" : "First");
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "rt", stdin);
#endif
  int t, n;
  std::vector<int> arr;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    arr.resize(n);
    for (auto &ele : arr) {
      scanf("%d", &ele);
    }
    printf("%s\n", Solve(n, arr).c_str());
  }
  return 0;
}

// https://leetcode.com/problems/palindrome-number/
#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& str) {
  for (int i = 0, j = str.length() - 1; i <= j; ++i, --j) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

bool Solve(const int& n) {
  std::string num_str = std::to_string(n);
  return IsPalindrome(num_str);
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  printf("%s: solution : %s\n", __func__, Solve(n) ? "true" : "false");
  return 0;
}

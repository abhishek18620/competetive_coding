// https://leetcode.com/problems/regular-expression-matching/
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

inline bool ValidateIndex(const std::string& str, const int& idx) {
  return idx >= 0 && idx < str.length();
}

bool Solve(const std::string&  str, const std::string& pattern, int i, int j) {
  if(!ValidateIndex(pattern, j)) {
    printf("scanned the whole pattern %d %d\n", j, (int)pattern.length());
    return true;
  }
  if (!ValidateIndex(str, i)) {
    // scanned the whole string but not pattern yet
    if (ValidateIndex(pattern, j + 1) && pattern[j + 1] == '*')
      return false;
    if (ValidateIndex(pattern, j + 1) && ValidateIndex(pattern, j + 2) &&
        pattern[j + 1] == '.' && pattern[j + 2] == '*') {
      // ".*" matches empty string
      return true;
    }
    return false;
  }
  printf("i = %d and %c\n j = %d and %c", i, str[i], j, pattern[j]);
  if(pattern[j] == '.') {
    // matches any single character
    return Solve(str, pattern, i+1, j+1);
  }
  if(pattern[j] == '*') {
    // Matches zero or more of the preceding element
    if(ValidateIndex(pattern, j-1)) {
      const char& prev_char = pattern[j-1];
      if(prev_char == '.') {
        // ".*" matches everything
        return true;
      }
      // prev_char is not a wildcard
      // can further optimise this one by checking the next char
      bool ret = false;;
      for(int idx = i; ValidateIndex(str, idx) && str[idx] == prev_char; idx++) {
        ret |= Solve(str, pattern, idx+1, j);
      }
      return ret;
    }
    else {
      // pattern[j-1] is not a valid index which means pattern starts with *
      // which is a invalid pattern
      printf("ERROR: %d Invalid pattern", __LINE__);
      return false;
    }
  }
  // pattern[j] is not a wildcard
  if(str[i] == pattern[j]) {
    //not matching
    return Solve(str, pattern, i+1, j+1);
  }
  return false;
}

bool MatchRegex(const std::string&  str, const std::string& pattern) {
  for(int i = 0; i < str.length(); i++) {
    if(Solve(str, pattern, i, 0)) {
      return true;
    }
  }
  return false;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str("");
  std::string pattern("");
  getline(std::cin, str);
  getline(std::cin, pattern);
  printf("str: %s  pattern: %s  \nResult: %s\n", str.c_str(), pattern.c_str(), (MatchRegex(str, pattern) ? "Found" : "Not Found"));
  return 0;
}



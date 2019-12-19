// https://leetcode.com/problems/word-break/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

static constexpr int INF = 1e9 + 9;

static void CheckWordInDict(const std::string &str, const int start,
                            std::vector<std::string> dict,
                            std::vector<bool> &dp) {
  for (const auto &word : dict) {
    if (start + word.length() <= str.length() &&
        word == str.substr(start, word.length())) {
      dp[start + word.length() - 1] = true;
    }
  }
  // printf("%s: start = %d\n", __func__, start);
  // for (auto res : dp) {
  //  printf("%s\n", res ? "true" : "false");
  //}
}

bool Solve(const std::string &str, const std::vector<std::string> &dict) {
  int N = str.length();
  if (N == 0) {
    return 0;
  }
  int min_word_len = INF;
  std::vector<bool> dp(N + 1, false);
  for (const auto &word : dict) {
    min_word_len = std::min(min_word_len, (int)word.length());
  }
  // base cases
  CheckWordInDict(str, 0, dict, dp);
  for (int i = 1; i <= N - min_word_len; i++) {
    if (!dp[i - 1]) {
      continue;
    }
    CheckWordInDict(str, i, dict, dp);
  }

  return dp[N - 1];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  std::string str;
  std::getline(std::cin, str);
  printf("%s: str = %s\n", __func__, str.c_str());
  int num_of_words;
  scanf("%d", &num_of_words);
  printf("%s: word = %d\n", __func__, num_of_words);
  std::string word;
  std::vector<std::string> dict;
  for (int i = 0; i < num_of_words; i++) {
    std::cin >> word;
    printf("%s: %s  ", __func__, word.c_str());
    dict.emplace_back(word);
  }
  printf("\n%s: solution = %s\n", __func__,
         Solve(str, dict) ? "true" : "false");
  return 0;
}

// https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
#include <iostream>
#include <string>
#include <vector>

constexpr int INF = 1e9;

inline int CalcCost(int spaces) { return spaces * spaces * spaces; }

int Solve(std::vector<std::string> &sentence, int &width) {
  std::cout << "I'm here" << std::endl;
  int n = sentence.size();
  std::vector<std::vector<int>> cost(
      n + 1,
      std::vector<int>(
          n + 1,
          INF)); // cost(i, j) = cost of fitting words (i, j) in a single line

  // build the cost table
  for (int i = 0; i < n; i++) {
    int spaces_left = width - sentence[i].size();
    cost[i][i] = CalcCost(spaces_left);
    for (int j = i + 1; j < n; j++) {
      // words from i to j
      if ((int)sentence[j].length() > spaces_left - 1) { // -1 for space
        // if doesn't fit in the same line
        cost[i][j] =
            CalcCost(spaces_left) + CalcCost(width - (int)sentence[j].length());
        break;
      }
      spaces_left--; // for a space between words
      spaces_left -= sentence[j].length();
      cost[i][j] = CalcCost(spaces_left);
      //std::cout << i << " " << j << " " << cost[i][j] << std::endl;
    }
  }
  // Printing cost matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << cost[i][j] << "    ";
    }
    std::cout << std::endl;
  }
  // dp
  // state(i) = min(for(j: (0, i)) state(j) + cost(j+1, i))
  std::vector<int> dp(n + 1, INF);
  dp[0] = cost[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      dp[i] = std::min(dp[i], dp[j] + cost[j + 1][i]);
    }
    //std::cout << "i = " << i << " dp[i] " << dp[i] << std::endl;
  }
  return dp[n - 1];
}

int main() {
  int n;
  int width;
  std::cin >> n >> width;
  std::vector<std::string> sentence(n);
  for (int i = 0; i < n; i++) {
    std::cin >> sentence[i];
  }
  std::cout << Solve(sentence, width) << std::endl;
  return 0;
}

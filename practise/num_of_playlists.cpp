// https://leetcode.com/problems/number-of-music-playlists/
#include <iostream>
#include <string>
#include <vector>

static constexpr int MOD = 1e9 + 7;

inline static long long modmul(const long long &a, const long long &b) {
  return (a % MOD * b % MOD) % MOD;
}
inline static long long modadd(const int &a, const int &b) {
  return (a % MOD + b % MOD) % MOD;
}

int SolveOptimised(int N, int l, int k) {
  std::vector<long long> dpeven(N + 1);
  std::vector<long long> dpodd(N + 1);
  dpeven[0] = dpodd[0] = 1;                           // dpodd[0] = 0;
  for (int listened = 1; listened <= l; listened++) { // songs to be listened to
    if (listened & 1) {
      std::cout << "odd" << std::endl;
      std::cout << dpeven[0] * N - +1;
    } else {
      std::cout << "even" << std::endl;
    }

    for (int i = 1; i <= std::min(listened, N);
         i++) { // considering till i songs
      (listened & 1)
          ? dpodd[i]
          : dpeven[i] =
                modadd(modmul((listened & 1) ? dpeven[i - 1] : dpodd[i - 1],
                              (N - i + 1)) // add new song
                       ,
                       modmul((listened & 1) ? dpeven[i] : dpodd[i],
                              std::max(i - k, 0))); // reuse the same song
      if (listened == 2 && i == 2) {
        std::cout << "@debug prev = " << dpodd[1] << " sol = " << dpeven[2]
                  << std::endl;
      }
    }
    for (auto val : (listened & 1) ? dpodd : dpeven) {
      std::cout << val << "   ";
    }
    std::cout << std::endl;
  }
  return l & 1 ? dpodd[N] : dpeven[N];
}

int Solve(int N, int l, int k) {
  std::vector<std::vector<long long>> dp(l + 1,
                                         std::vector<long long>(N + 1, 0));
  std::vector<long long> dpeven(N + 1);
  std::vector<long long> dpodd(N + 1);
  dp[0][0] = 1;
  for (int listened = 1; listened <= l; listened++) { // songs to be listened to
    for (int i = 1; i <= std::min(listened, N);
         i++) { // considering till i songs
      dp[listened][i] =
          modadd(modmul(dp[listened - 1][i - 1], (N - i + 1)) // add new song
                 ,
                 modmul(dp[listened - 1][i],
                        std::max(i - k, 0))); // reuse the same song
    }
    for (auto vals : dp[listened]) {
      std::cout << vals << "   ";
    }
    std::cout << std::endl << std::endl;
  }
  return dp[l][N];
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n; // num of songs
  int l; // num of songs to be listened
  int k; // num of songs whoch has to be played after we can reuse one song
  scanf("%d %d %d", &n, &l, &k);
  printf("%s: Input: %d %d %d\n", __func__, n, l, k);
  printf("%s: solution = %d\n", __func__, Solve(n, l, k));
  printf("%s: solution = %d\n", __func__, SolveOptimised(n, l, k));
  return 0;
}

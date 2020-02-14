// https://leetcode.com/problems/arithmetic-slices/
#include <iostream>
#include <vector>

auto get_num_of_arithmetic_seq = [](const int& len) {
  if (len < 2) {
    return 0;
  }
  return (len * len - 3 * len + 2) / 2;
};

int Solve(const std::vector<int>& arr) {
  const int& n = arr.size();
  if (n < 3) { // sanity check
    return 0;
  }
  std::vector<int> diff(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    diff[i] = arr[i + 1] - arr[i];
  }
  diff.push_back(-1 * ((diff[n - 2] != 0)
                           ? diff[n - 2]
                           : 1)); // so that last sequence can also be calculated and this would be ignored
  std::vector<std::pair<int, int>> diff_freqs;
  diff_freqs.push_back({diff[0], 1});
  int sol = 0;
  int last_seq_length;
  for (int i = 1; i < n; ++i) {
    if (diff[i] == diff[i - 1]) {
      diff_freqs.back().second++;
    } else {
      last_seq_length = diff_freqs.back().second + 1;
      printf("%s: last_seq_length = %d of diff = %d\n", __func__, last_seq_length, diff[i - 1]);
      sol += get_num_of_arithmetic_seq(last_seq_length);
      diff_freqs.push_back({diff[i], 1});
    }
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  std::vector<int> arr(n);
  for (int& ele : arr) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  printf("%s: soution = %d\n", __func__, Solve(arr));
  return 0;
}

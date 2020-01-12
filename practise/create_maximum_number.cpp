// https://leetcode.com/problems/create-maximum-number/
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

auto print_vector = [](const std::vector<int>& arr, const std::string& name) {
  printf("%s: ", name.c_str());
  for (auto ele : arr) {
    printf("%d  ", ele);
  }
  printf("\n");
};

std::vector<int> GetMaxNumOfKLength(const std::vector<int>& arr, const int& K) {
  if (arr.size() < K) { // not possible case just playing safe
    return std::vector<int>();
  }
  if (arr.size() == K) {
    return arr;
  }
  printf("%s: K = %d\n", __func__, K);
  std::vector<int> sol(K);
  const int        sz           = arr.size();
  int              prev_sol_idx = -1;
  int              curr_sol;
  for (int k = 1; k <= K; ++k) {
    curr_sol = -1;
    for (int i = prev_sol_idx + 1; i < sz - K + k; ++i) {
      if (arr[i] > curr_sol) {
        curr_sol     = arr[i];
        prev_sol_idx = i;
      }
    }
    printf("@debug %d\n", prev_sol_idx);
    sol[k - 1] = arr[prev_sol_idx];
  }
  return sol;
}

/**
 * @brief Returns true if num1 is indeed greater than num2
 */
auto is_greater = [](const std::vector<int>& num1, int pos1, const std::vector<int>& num2,
                     int pos2) {
  int m = num1.size();
  int n = num2.size();

  while (pos1 < m && pos2 < n && num1[pos1] == num2[pos2]) {
    pos1++;
    pos2++;
  }

  if (pos2 == n) {
    return true;
  }

  if (pos1 < m && num1[pos1] > num2[pos2]) {
    return true;
  }

  return false;
};

/**
 * @brief See Merge Sort for reference.
 *        Anyways I don't think you should be looking at this problem
 *        if you are not aware of merge sort.
 *
 * @return Returns the merged number
 */
auto merge_two_nums = [](const std::vector<int>& num1, const std::vector<int>& num2) {
  const int        m = num1.size();
  const int        n = num2.size();
  std::vector<int> ret_sol(m + n);

  for (int idx = 0, i = 0, j = 0; idx < m + n; idx++) {
    if (is_greater(num1, i, num2, j)) {
      ret_sol[idx] = num1[i++];
    } else {
      ret_sol[idx] = num2[j++];
    }
  }

  return ret_sol;
};

auto get_max_nums_and_merge = [](const std::vector<int>& arr1,
                                 const std::vector<int>& arr2, const int K1,
                                 const int K2) {
  std::vector<int> num1 = GetMaxNumOfKLength(arr1, K1);
  if (arr1.empty()) {
    return std::vector<int>(); // return an empty vector if impossible
  }
  std::vector<int> num2 = GetMaxNumOfKLength(arr2, K2);
  printf("%s: sz1 = %d sz2 = %d\n", __func__, (int)num1.size(), (int)num2.size());
  // print_vector(num1, "num1");
  // print_vector(num2, "num2");
  std::vector<int> ret_sol = merge_two_nums(num1, num2);
  // if (num1.size() > num2.size()) {
  //  ret_sol = merge_two_nums(num1, num2);
  //} else {
  //  ret_sol = merge_two_nums(num2, num1);
  //}
  return ret_sol;
};
std::vector<int> Solve(const std::vector<int>& arr1, const std::vector<int>& arr2,
                       const int& K) {
  // crappy base cases
  const int m = arr1.size();
  const int n = arr2.size();
  if (m == 0) {
    return arr2;
  }
  if (n == 0) {
    return arr1;
  }
  std::vector<int> sol;
  std::vector<int> curr_sol;
  for (int k = 1; k <= K; ++k) {
    curr_sol.clear();
    printf("%s: k = %d\n", __func__, k);
    if (m > n && k <= n && K - k <= m) {
      curr_sol = get_max_nums_and_merge(arr2, arr1, k, K - k);
    } else if (k <= m && K - k <= n) {
      curr_sol = get_max_nums_and_merge(arr1, arr2, k, K - k);
    }
    if (sol.empty()) {
      sol = curr_sol;
    }
    // print_vector(sol, "sol");
    // print_vector(curr_sol, "curr_sol");
    if (is_greater(curr_sol, 0, sol, 0)) {
      sol = curr_sol;
    }
  }
  return sol;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m;
  int n;
  int K;
  scanf("%d %d %d", &m, &n, &K);
  printf("%s: m = %d  n = %d  k = %d\n", __func__, m, n, K);
  printf("%s: arr1 = ", __func__);
  std::vector<int> arr1(m);
  for (int& ele : arr1) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n%s: arr2 = ", __func__);
  std::vector<int> arr2(n);
  for (int& ele : arr2) {
    scanf("%d", &ele);
    printf("%d  ", ele);
  }
  printf("\n");
  // std::this_thread::sleep_for(std::chrono::seconds(2));
  auto sol = Solve(arr1, arr2, K);
  printf("%s: solution with size %d is as follows \n", __func__, (int)sol.size());
  for (auto ele : sol) {
    printf("%d  ", ele);
  }
  printf("\n");
  return 0;
}

// https://leetcode.com/problems/largest-divisible-subset/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto LCF = [](int x, int y, int min_factor) {
    if (x < y) {
        std::swap(x, y);
    }
    for (int i = min_factor; i <= y; ++i) {
        if (x % i && y % i) {
            return i;
        }
    }

    return -1;
};

std::vector<int> Solve(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    if (n < 2) {
        return nums;
    }
    std::vector<std::pair<int, int>> dp(n);
    std::pair<int, int>              max_sol   = {1, 1};
    int                              start_idx = 0;
    for (int i = 0; i < n; ++i) {
        std::pair<int, int> curr_sol = {i, 1};
        for (int j = i - 1; j >= 0; --j) {
            if (nums[i] % nums[j] == 0 && dp[j].second + 1 > curr_sol.second) {
                curr_sol = {j, dp[j].second + 1};
            }
        }
        dp[i] = curr_sol;
        if (dp[i].second > max_sol.second) {
            max_sol   = curr_sol;
            start_idx = i;
        }
        printf("dp[%d] = %d %d\n", i, dp[i].first, dp[i].second);
    }

    // build sol
    std::vector<int> sol;
    sol.resize(max_sol.second);
    printf("max = %d %d\n", max_sol.first, max_sol.second);
    for (int i = start_idx, j = sol.size() - 1; j >= 0; i = dp[i].first, --j) {
        sol[j] = nums[i];
    }

    return sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    std::vector<int> nums(n);
    for (auto& ele : nums) {
        scanf("%d", &ele);
    }
    auto sol = Solve(nums);
    printf("%s: Solution as follows\n", __func__);
    for (auto& ele : sol) {
        printf("%d ", ele);
    }
    printf("\n");
    return 0;
}

// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <vector>

static int BSearch(const std::vector<int>& arr, const int target) {
    int lo = 0;
    int hi = arr.size() - 1;
    int mid;
    while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        if (target == arr[mid]) {
            return mid;
        }
        if (target < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return -1;
}

long long Solve(std::vector<int> arr) {
    arr.push_back(0); // push the base slot
    const int N = arr.size();
    std::sort(arr.begin(), arr.end());
    int                    max_N = arr[N - 1];
    std::vector<long long> dp(max_N + 1, 0);
    dp[0] = 1;
    for (int jolt = 1; jolt <= max_N; ++jolt) {
        if (BSearch(arr, jolt) == -1) { // state doesn't exist
            continue;
        }
        int N_1 = jolt - 1;
        int N_2 = jolt - 2;
        int N_3 = jolt - 3;
        if (BSearch(arr, N_1) != -1) {
            dp[jolt] += dp[N_1];
        }
        if (BSearch(arr, N_2) != -1) {
            dp[jolt] += dp[N_2];
        }
        if (BSearch(arr, N_3) != -1) {
            dp[jolt] += dp[N_3];
        }
    }

    return dp[max_N];
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::vector<int> arr(99);
    for (auto& ele : arr) {
        scanf("%d", &ele);
    }
    printf("%s: Solution = %lld\n", __func__, Solve(arr));

    return 0;
}

// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <vector>

struct State {
    int diff_of_1 = 0;
    int diff_of_3 = 0;

    void PrintState() {
        printf("(%d, %d)\n", this->diff_of_1, this->diff_of_3);
    }
};

int BSearch(const std::vector<int>& arr, const int target) {
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

int Solve(std::vector<int> arr) {
    arr.push_back(0); // push the base slot
    const int N = arr.size();
    std::sort(arr.begin(), arr.end());
    int                max_N = arr[N - 1];
    std::vector<State> dp(max_N + 1);
    for (int jolt = 1; jolt <= max_N; ++jolt) {
        if (BSearch(arr, jolt) == -1) { // state doesn't exist
            continue;
        }

        int N_1 = jolt - 1;
        int N_2 = jolt - 2;
        int N_3 = jolt - 3;
        if (BSearch(arr, N_1) != -1) {
            dp[jolt] = dp[N_1];
            dp[jolt].diff_of_1 += 1;
            continue;
        }
        if (BSearch(arr, N_2) != -1) {
            dp[jolt] = dp[N_2];
            continue;
        }
        if (BSearch(arr, N_3) != -1) {
            dp[jolt] = dp[N_3];
            dp[jolt].diff_of_3 += 1;
            continue;
        }
    }

    dp[max_N].diff_of_3 += 1; // for last baggage adaptor to device
    return dp[max_N].diff_of_1 * dp[max_N].diff_of_3;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::vector<int> arr(99);
    for (auto& ele : arr) {
        scanf("%d", &ele);
    }
    printf("%s: Solution = %d\n", __func__, Solve(arr));

    return 0;
}

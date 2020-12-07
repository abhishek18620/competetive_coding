// https://adventofcode.com/2020/day/1
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int                     ele;
    std::unordered_set<int> set;
    std::vector<int>        arr;
    for (int i = 0; i < 200; ++i) {
        scanf("%d", &ele);
        printf("%d ", ele);
        set.insert(ele);
        arr.push_back(ele);
    }
    printf("\n");

    for (int idx1 = 0; idx1 < 200; idx1++) {
        for (int idx2 = idx1 + 1; idx2 < 200; idx2++) {
            int sum = arr[idx1] + arr[idx2];
            if (set.count(2020 - sum)) {
                printf("%d %d %d\n", arr[idx1], arr[idx2], 2020 - sum);
                printf("%d\n", arr[idx1] * arr[idx2] * (2020 - sum));
                break;
            }
        }
    }

    return 0;
}

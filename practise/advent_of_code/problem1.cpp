// https://adventofcode.com/2020/day/1
#include <iostream>
#include <unordered_set>

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int                     ele;
    std::unordered_set<int> set;
    for (int i = 0; i < 200; ++i) {
        scanf("%d", &ele);
        printf("%d ", ele);
        set.insert(ele);
    }
    printf("\n");
    for (auto it = set.begin(); it != set.end(); it++) {
        if (set.count(2020 - *it)) {
            printf("%d %d\n", *it, 2020 - (*it));
            printf("%d\n", (*it) * (2020 - *it));
            break;
        }
    }

    return 0;
}

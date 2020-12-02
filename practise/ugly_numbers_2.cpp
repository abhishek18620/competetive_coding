// https://leetcode.com/problems/largest-divisible-subset/
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

int SolveOptimised(const int n) {
    if (n < 7) {
        return n;
    }
    std::vector<int> dp = {1};
    int              i  = 0;
    int              j  = 0;
    int              k  = 0;
    while (dp.size() < n) {
        int mult_of_2 = dp.at(i) * 2;
        int mult_of_3 = dp.at(j) * 3;
        int mult_of_5 = dp.at(k) * 5;

        int min_num = std::min(mult_of_2, std::min(mult_of_3, mult_of_5));
        dp.push_back(min_num);

        if (min_num == mult_of_2) {
            i++;
        }
        if (min_num == mult_of_3) {
            j++;
        }
        if (min_num == mult_of_5) {
            k++;
        }
    }
    return dp.at(dp.size() - 1);
}

int Solve(const int n) {
    if (n < 7) {
        return n;
    }
    std::set<int> dp;
    dp.insert(1);
    dp.insert(2);
    dp.insert(3);
    dp.insert(4);
    dp.insert(5);
    dp.insert(6);

    int last_sol = -1;
    for (int i = 7, j = 7; dp.size() <= n; ++i) {
        // check for 2
        // printf("checking for %d\n", i);
        int fac_of_two = (i % 2) ? -1 : i / 2;
        if (fac_of_two != -1) {
            if (dp.count(fac_of_two)) {
                // printf("%d fac of 2 %d\n", i, fac_of_two);
                last_sol = i;
                dp.insert(last_sol);
                j++;
                continue;
            }
        }

        // check for 3
        int fac_of_three = (i % 3) ? -1 : i / 3;
        if (fac_of_three != -1) {
            if (dp.count(fac_of_three)) {
                // printf("%d fac of 3 %d\n", i, fac_of_three);
                last_sol = i;
                dp.insert(last_sol);
                j++;
                continue;
            }
        }

        // check for 5
        int fac_of_five = (i % 5) ? -1 : i / 5;
        if (fac_of_five != -1) {
            if (dp.count(fac_of_five)) {
                // printf("%d fac of 5 %d\n", i, fac_of_five);
                last_sol = i;
                dp.insert(last_sol);
                j++;
                continue;
            }
        }
    }

    return last_sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    printf("%s: n = %d\n", __func__, n);
    printf("%s: Solution = %d\n", __func__, SolveOptimised(n));
    return 0;
}

// https://leetcode.com/problems/airplane-seat-assignment-probability/
#include <iostream>

/*
 *  state(i, j) = Probability of ith person acquiring jth seat
 *  if(i == j) {
 *    // 1 - P(everyone acquiring j/ith seat)
 *    state(i, j) = 1 - sum(state(k, j))  // 1 <= k <= i-1
 *  }
 *  else {
 *    // first if ith person couldn't get ith seat then P of choosing a seat.
 *    state(i, j) = (1-state(i,i)) * (1/n-i+1)
 *  }
 */

float Solve(const int &n) {
  if (n == 1) {
    return 1;
  }
  return 0.5;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%s: Input = %d\n", __func__, n);
  printf("%s: Solution = %f\n", __func__, Solve(n));
  return 0;
}

#include "hackerrank/BuyingTickets.cpp"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) {
  int n = 5;
  int p = 2;
  vector<int> vec = {2, 6, 3, 4, 5};
  ASSERT_EQ(12, Solve(vec, n, p));
}

/*TEST(SquareRootTest, NegativeNos) {*/
/*}*/

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


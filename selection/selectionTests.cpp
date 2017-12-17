/**
 *
 * Tests for selection.cpp
 *
 * Author: ajpetrosky
 **/

#include <gtest/gtest.h>
#include "selection.cpp"

TEST(testSelection, select){
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(1, select(v, 0));
  EXPECT_EQ(2, select(v, 1));
  EXPECT_EQ(3, select(v, 2));
  int b[] = {7,3,2,10,9,8,1,6,4,5};
  std::vector<int> v1(b, b+10);
  EXPECT_EQ(1, select(v1, 0));
  EXPECT_EQ(2, select(v1, 1));
  EXPECT_EQ(3, select(v1, 2));
  EXPECT_EQ(4, select(v1, 3));
  EXPECT_EQ(7, select(v1, 6));
  EXPECT_EQ(5, select(v1, 4));
  EXPECT_EQ(10, select(v1, 9));
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

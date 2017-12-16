/**
 *
 * Tests for sorts.cpp
 *
 **/

#include <gtest/gtest.h>
#include "sorts.cpp"

TEST(testBubbleSort, intArrays){
  std::vector<int> v(0);
  EXPECT_EQ(v, bubbleSort(v));
  v.push_back(1);
  EXPECT_EQ(v, bubbleSort(v));
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v, bubbleSort(v));
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  v.assign(a,a+10);
  int b[] = {7,3,2,10,9,8,1,6,5,4};
  std::vector<int> v1(b, b+10);
  EXPECT_EQ(v, bubbleSort(v1));
}

TEST(testInsertionSort, intArrays){
  std::vector<int> v(0);
  EXPECT_EQ(v, insertionSort(v));
  v.push_back(1);
  EXPECT_EQ(v, insertionSort(v));
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v, insertionSort(v));
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  v.assign(a,a+10);
  int b[] = {7,3,2,10,9,8,1,6,5,4};
  std::vector<int> v1(b, b+10);
  EXPECT_EQ(v, insertionSort(v1));
}

TEST(testMergeSort, intArrays){
  std::vector<int> v(0);
  EXPECT_EQ(v, mergeSort(v));
  v.push_back(1);
  EXPECT_EQ(v, mergeSort(v));
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v, mergeSort(v));
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  v.assign(a,a+10);
  int b[] = {7,3,2,10,9,8,1,6,5,4};
  std::vector<int> v1(b, b+10);
  EXPECT_EQ(v, mergeSort(v1));
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
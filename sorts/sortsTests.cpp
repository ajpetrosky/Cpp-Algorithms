/**
 *
 * Tests for sorts.cpp
 *
 * Author: ajpetrosky
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
  int c[] = {1,2,3,4,5,6,7,8,9,10,10,11,12,13,14,15,16,17,18,19,20,21,22,23,23,23};
  v.assign(c,c+26);
  int d[] = {23,16,10,17,20,6,9,8,7,11,10,12,13,14,15,2,4,18,19,3,5,21,22,23,23,1};
  v1.assign(d,d+26);
  EXPECT_EQ(v, mergeSort(v1));
}

TEST(testQuicksort, intArrays){
  std::vector<int> v(0);
  EXPECT_EQ(v, quicksort(v));
  v.push_back(1);
  EXPECT_EQ(v, quicksort(v));
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v, quicksort(v));
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  v.assign(a,a+10);
  int b[] = {7,3,2,10,9,8,1,6,5,4};
  std::vector<int> v1(b, b+10);
  EXPECT_EQ(v, quicksort(v1));
  int c[] = {1,2,3,4,5,6,7,8,9,10,10,11,12,13,14,15,16,17,18,19,20,21,22,23,23,23};
  v.assign(c,c+26);
  int d[] = {23,16,10,17,20,6,9,8,7,11,10,12,13,14,15,2,4,18,19,3,5,21,22,23,23,1};
  v1.assign(d,d+26);
  EXPECT_EQ(v, quicksort(v1));
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

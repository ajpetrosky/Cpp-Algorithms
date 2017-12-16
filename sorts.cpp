/**
 *
 * sorts.cpp
 * A few common sorts
 *
 **/

#include <iostream>
#include "sorts.h"

// Helper for mergeSort
std::vector<int> merge(std::vector<int> v0, std::vector<int> v1) {
  std::vector<int> v(v0.size() + v1.size());
  if (v0.size() != 1) {
    int split = v0.size() / 2;
    std::vector<int>::const_iterator start0 = v0.begin();
    std::vector<int>::const_iterator end0 = v0.begin() + split;
    std::vector<int>::const_iterator start1 = v0.begin() + split;
    std::vector<int>::const_iterator end1 = v0.end();
    std::vector<int> v00(start0, end0);
    std::vector<int> v01(start1, end1);
    std::vector<int> result = merge(v00, v01);
    v0.assign(result.begin(), result.end());
  }
  if (v1.size() != 1) {
    int split = v1.size() / 2;
    std::vector<int>::const_iterator start0 = v1.begin();
    std::vector<int>::const_iterator end0 = v1.begin() + split;
    std::vector<int>::const_iterator start1 = v1.begin() + split;
    std::vector<int>::const_iterator end1 = v1.end();
    std::vector<int> v10(start0, end0);
    std::vector<int> v11(start1, end1);
    std::vector<int> result = merge(v10, v11);
    v1.assign(result.begin(), result.end());
  }
  int i = 0; int j = 0; int k = 0;
  while (i < v0.size() && j < v1.size()) {
    if (v0[i] < v1[j]) {
      v[k] = v0[i];
      i++;
    } else {
      v[k] = v1[j];
      j++;
    }
    k++;
  }
  while (i < v0.size()) {
    v[k] = v0[i];
    i++; k++;
  }
  while (j < v1.size()) {
    v[k] = v1[j];
    j++; k++;
  }
  return v;
}

// Implementation of merge sort for int vectors
std::vector<int> mergeSort(std::vector<int> v) {
  if (v.size() <= 1) {
    return v;
  } else {
    int split = v.size() / 2;
    std::vector<int>::const_iterator start0 = v.begin();
    std::vector<int>::const_iterator end0 = v.begin() + split;
    std::vector<int>::const_iterator start1 = v.begin() + split;
    std::vector<int>::const_iterator end1 = v.end();
    std::vector<int> v0(start0, end0);
    std::vector<int> v1(start1, end1);
    return merge(v0, v1);
  }
}

// Simple implementation of insertion sort for int vectors
std::vector<int> insertionSort(std::vector<int> v) {
  int i = 1;
  while (i < v.size()) {
    int j = i;
    while (j > 0 && v[j-1] > v[j]) {
      int temp = v[j-1];
      v[j-1] = v[j];
      v[j] = temp;
      j--;
    }
    i++;
  }
  return v;
}

// Simple implementation of bubble sort for int vectors
std::vector<int> bubbleSort(std::vector<int> v) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    int i = 1;
    while (i < v.size()) {
      if (v[i] < v[i-1]) {
        swapped = true;
        int temp = v[i];
        v[i] = v[i-1];
        v[i-1] = temp;
      }
      i++;
    }
  }
  return v;
}

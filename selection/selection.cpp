/**
 *
 * selection.cpp
 * Worst case O(n) selection
 *
 * Author: ajpetrosky
 **/

#include <math.h>
#include <iostream>
#include <algorithm>
#include "selection.h"

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

// Get the median of medians from the provided vector
int medianOfMedians(std::vector<int> v) {
  int n = v.size();
  int i = 0;
  // Base cases
  if (v.size() == 1) return v[0];
  if (v.size() == 2) {
    return (v[0] < v[1]) ? v[0] : v[1];
  }
  // Break up the vector into as many groups of 5 as possible
  std::vector<int> medians;
  while (n > 0) {
    std::vector<int> unsorted;
    if (n < 5) {
      unsorted.reserve(n);
      std::vector<int>::const_iterator start = v.begin() + i;
      std::vector<int>::const_iterator end = v.end();
      unsorted.insert(unsorted.end(), start, end);
      i += n;
      n = 0;
    } else {
      unsorted.reserve(5);
      std::vector<int>::const_iterator start = v.begin() + i;
      std::vector<int>::const_iterator end = v.begin() + i + 5;
      unsorted.insert(unsorted.end(), start, end);
      i += 5;
      n -= 5;
    }
    // Find the median of each group of five
    std::vector<int> sorted = insertionSort(unsorted);
    int med = sorted[ceil(((float) sorted.size()) / 2.0) - 1];
    medians.push_back(med);
  }
  // Find the median of the median of medians by recursively calling select
  int medLoc = ceil(((float) medians.size()) / 2.0) - 1;
  return select(medians, medLoc);
}

// Find the index of the median of medians in the vector
int getIndex(std::vector<int> v, int piv) {
  int i;
  for (i = 0; i < v.size(); i++) {
    if (v[i] == piv) break;
  }
  return i;
}

// Worst case O(n) selection
int select(std::vector<int> v, int k) {
  int r = v.size() - 1;
  // Base cases
  if (v.size() == 1) return v[0];
  if (v.size() == 2) {
    int hi; int lo;
    v[0] < v[1] ? hi = 1 : hi = 0;
    hi == 1 ? lo = 0 : lo = 1;
    if (k == 1) {
      return v[hi];
    } else {
      return v[lo];
    }
  }
  // Partition the vector based off the median of medians
  std::vector<int> copy(r+1);
  std::copy(v.begin(),v.end(),copy.begin());
  int piv = medianOfMedians(copy);
  int loc = getIndex(v, piv);
  v[loc] = v[r];
  v[r] = piv;
  int i = -1;
  int j = 0;
  while (j <= r-1) {
    if (v[j] <= piv) {
      i++;
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
    j++;
  }
  i++;
  if (piv < v[i]) {
    v[r] = v[i];
    v[i] = piv;
  }
  // Check if we have found the desired element;
  // o/w, call select on the lower half or upper half as appropriate
  if (k == i) {
    return piv;
  } else if (k < i) {
    std::vector<int>::const_iterator start = v.begin();
    std::vector<int>::const_iterator end = v.begin() + i;
    std::vector<int> v0(start, end);
    if (v0.size() == 0) {
      v0.push_back(v[i-1]);
    }
    return select(v0, k);
  } else {
    std::vector<int> v0;
    v0.reserve(v.size() - i);
    std::vector<int>::const_iterator start = v.begin() + i + 1;
    std::vector<int>::const_iterator end = v.end();
    v0.assign(start, end);
    if (v0.size() == 0) {
      v0.push_back(v[r]);
    }
    return select(v0, (k-i-1));
  }
}

/**
 *
 * sorts.cpp
 * A few common sorts
 *
 **/

#include <iostream>
#include "sorts.h"

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

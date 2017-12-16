/**
 *
 * sorts.cpp
 * A few common sorts
 *
 **/

#include <vector>
#include <iostream>
#include "sorts.h"

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

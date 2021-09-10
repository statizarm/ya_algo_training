/*
** Copyright (c) 08.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <vector>
#include <algorithm>

int bodyswap(std::vector<int> &bodies, int left, int right) {
  std::cout << left << " " << right << std::endl;
  std::swap(bodies[left], bodies[right]);
  return bodies[right];
}
int main() {
  int n, n_swaps;

  std::cin >> n >> n_swaps;

  std::vector<int> minds(n + 1);
  std::generate(minds.begin(), minds.end(), [x = 0] () mutable {return x++;});

  while (--n_swaps >= 0) {
    int first, second;
    std::cin >> first >> second;
    std::swap(minds[first], minds[second]);
  }

  // 1 3 2 4 5
  n_swaps = n - 2;
  
  n_swaps = -1;
  for (int i = 1; i < n - 1; ++i) {
    if (minds[i] != i) {
      int j = i;

      while (minds[i] != j) {
        i = bodyswap(minds, i, n - 1);
      }

      i = bodyswap(minds, i, n);
      i = bodyswap(minds, i, n);
      bodyswap(minds, minds[n - 1], n - 1);

      i = j;
    }
  }

  if (minds[n - 1] == n) {
    bodyswap(minds, n - 1, n);
  }

  return 0;
}

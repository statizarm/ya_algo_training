/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <algorithm>

int main() {
  int64_t n, k, min, max;

  std::cin >> n >> k; 

  if (n % 2) {
    std::cin >> min;
    max = min;
    n -= 1;
  } else {
    std::cin >> min >> max;
    if (min > max) {
      std::swap(min, max);
    }
    n -= 2;
  }

  while ((n -= 2) >= 0) {
    int num[2];
    std::cin >> num[0] >> num[1];

    if (num[1] > num[0]) {
      if (num[1] > max) {
        max = num[1];
      } else if (num[0] < min) {
        min = num[0];
      }
    } else {
      if (num[0] > max) {
        max = num[0];
      } else if (num[1] < min) {
        min = num[1];
      }
    }
  }

  std::cout << max - min << std::endl;
  return 0;
}

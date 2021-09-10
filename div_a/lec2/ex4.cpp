/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <algorithm>

int main() {
  int n, max;

  std::cin >> n >> max;

  int sum = max;
  while (--n > 0) {
    int l;

    std::cin >> l;

    max = std::max(max, l);
    sum += l;
  }

  if (sum - max >= max) {
    std::cout << sum << std::endl;
  } else {
    std::cout << max - sum + max << std::endl;
  }

  return 0;
}

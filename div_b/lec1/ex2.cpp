/*
** Copyright (c) day.month.year statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the COPYING file for more details. 
*/
#include <iostream>

int main() {
  int n, i, j;

  std::cin >> n >> i >> j;

  if (j < i) {
    std::cout << std::min(i - j - 1, n - i + j - 1) << std::endl;
  } else {
    std::cout << std::min(j - i - 1, n - j + i - 1) << std::endl;
  }
  return 0;
}

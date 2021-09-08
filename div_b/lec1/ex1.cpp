/*
** Copyright (c) 08.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>

int main() {
  int r, i, c;

  std::cin >> r >> i >> c;

  switch (i) {
  case 0:
    if (r == 0) {
      std::cout << c << std::endl;
    } else {
      std::cout << 3 << std::endl;
    }
    break;
  case 1:
    std::cout << c << std::endl;
    break;
  case 4:
    if (r != 0) {
      std::cout << 3 << std::endl;
    } else {
      std::cout << 4 << std::endl;
    }
    break;
  case 6:
    std::cout << 0 << std::endl;
    break;
  case 7:
    std::cout << 1 << std::endl;
    break;
  default:
    std::cout << i << std::endl;
    break;
  }

  return 0;
}

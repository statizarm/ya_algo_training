/*
** Copyright (c) 07.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <cmath>

int main() {
  int p;

  std::cin >> p;

  if (p < 3 || p == 4) {
    std::cout << -1 << std::endl;
  } else {
    int l = p / 3;

    switch (p % 3) {
      case 0:
        std::cout << l << " " << l << " " << l << std::endl;
        break;
      case 1:
        std::cout << l << " " << l << " " << l + 1 << std::endl;
        break;
      case 2:
        std::cout << l << " " << l + 1 << " " << l + 1 << std::endl;
        break;
    }

    if (p % 2) {
      l = (p - 1) / 2;
      std::cout << 1 << " " << l << " " << l << std::endl;
    } else {
      l = (p - 2) / 2;
      std::cout << 2 << " " << l << " " << l << std::endl;
    }
  }

  return 0;
}

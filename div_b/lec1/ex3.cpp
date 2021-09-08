/*
** Copyright (c) 08.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>

int main() {
  int x, y, z;

  std::cin >> x >> y >> z;

  if (x == y) {
    std::cout << 1 << std::endl;
  } else if (x > 12 || y > 12) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}

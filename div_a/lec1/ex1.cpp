/*
** Copyright (c) 06.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>

int main() {
  int a, b, c, d;

  std::cin >> a >> b >> c >> d;

  /*
  ** (a*x + b)
  ** --------- = 0
  ** (c*x + d)
  */

  if (a == 0) {
    if (b == 0) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  } else if (int x1 = b / a; x1 * a != b) {
    std::cout << "NO" << std::endl;
  } else if (c == 0) {
    std::cout << -x1 << std::endl;
  } else if (int x0 = d / c; x0 * c != d || x1 != x0) {
    std::cout << -x1 << std::endl;
  } else {
     std::cout << "NO" << std::endl;
  }

  return 0;
}

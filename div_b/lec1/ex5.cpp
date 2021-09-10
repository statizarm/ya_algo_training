/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <algorithm>
#include <utility>

int sqr_dist(int x0, int y0, int x1, int y1) {
  int dx = x0 - x1;
  int dy = y0 - y1;

  return dx * dx + dy * dy;
}

int main() {
  int d, x, y;

  std::cin >> d >> x >> y;

  if (x < 0 || y < 0 || x > d || y > d - x) {
    auto m = std::min({
        std::pair<int, int>(sqr_dist(x, y, 0, 0), 1),
        std::pair<int, int>(sqr_dist(x, y, d, 0), 2),
        std::pair<int, int>(sqr_dist(x, y, 0, d), 3)
    });

    std::cout << m.second << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}

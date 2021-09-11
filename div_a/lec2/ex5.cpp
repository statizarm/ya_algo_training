/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <utility>
#include <cmath>

std::pair<int, int> intersect(int l1, int r1, int l2, int r2) {
  std::pair<int, int> res {
    (l2 > l1) ? l2 : l1,
    (r2 < r1) ? r2 : r1
  };

  return res;
}

double calc_dx(double r, double dy) {
  return sqrt(r * r - dy * dy);
}

int main() {
  int x1, x2, x3, y1, y2, y3, r;

  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r;

  auto ry = intersect(y1, y2, y3 - r, y3 + r);

  uint64_t res = 0;
  for (int i = ry.first; i <= ry.second; ++i) {
    double dx = calc_dx(r, i - y3);
    
    auto rx = intersect(x1, x2, x3 - floor(dx), x3 + floor(dx));

    if (rx.second >= rx.first) {
      res += rx.second - rx.first + 1;
    }
  }

  std::cout << res << std::endl;
  return 0;
}

/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <cstring>

int n_sides(bool map[8][8], int row, int col) {
  int res = 0;

  if (map[row][col]) {
    if (row == 0 || !map[row - 1][col]) {
      res += 1;
    }

    if (row == 7 || !map[row+1][col]) {
      res += 1;
    }

    if (col == 0 || !map[row][col-1]) {
      res += 1;
    }

    if (col == 7 || !map[row][col+1]) {
      res += 1;
    }
  }
  

  return res;
}

int main() {
  int n;
  bool map[8][8];

  memset(map, 0, sizeof(map));

  std::cin >> n;

  while (--n >= 0) {
    int row, col;

    std::cin >> row >> col;

    map[row-1][col-1] = true;
  }

  int p = 0;

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      p += n_sides(map, i, j);
    }
  }

  std::cout << p << std::endl;

  return 0;
}

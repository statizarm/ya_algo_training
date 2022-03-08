/*
** Copyright (c) day.month.year statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the COPYING file for more details. 
*/
#include <iostream>

bool is_row_filled(int field[3][3], int row, int i) {
  return field[row][0] == field[row][1] &&
         field[row][1] == field[row][2] &&
         field[row][2] == i;
}

bool is_col_filled(int field[3][3], int col, int i) {
  return field[0][col] == field[1][col] &&
         field[1][col] == field[2][col] &&
         field[2][col] == i;
}

bool is_main_filled(int field[3][3], int i) {
  return field[0][0] == field[1][1] &&
         field[1][1] == field[2][2] &&
         field[2][2] == i;
}

bool is_side_filled(int field[3][3], int i) {
  return field[0][2] == field[1][1] &&
         field[1][1] == field[2][0] &&
         field[2][0] == i;
}

bool is_won(int field[3][3], int who) {
  for (int i = 0; i < 3; ++i) {
    if (is_row_filled(field, i, who) || is_col_filled(field, i, who)) {
      return true;
    }
  }

  return is_main_filled(field, who) || is_side_filled(field, who);
}

int count(int field[3][3], int sign) {
  int c = 0;

  for (int i = 0; i < 9; ++i) {
    if (field[i / 3][i % 3] == sign) {
      ++c;
    }
  }

  return c;
}

int main() {
  int field[3][3];

  std::cin >> field[0][0] >> field[0][1] >> field[0][2];
  std::cin >> field[1][0] >> field[1][1] >> field[1][2];
  std::cin >> field[2][0] >> field[2][1] >> field[2][2];

  auto x_won = is_won(field, 1);
  auto o_won = is_won(field, 2);
  auto x_count = count(field, 1);
  auto o_count = count(field, 2);

  if (x_won && o_won) {
    std::cout << "NO" << std::endl;
  } else if (o_won && o_count != x_count) {
    std::cout << "NO" << std::endl;
  } else if (x_won && x_count != o_count + 1) {
    std::cout << "NO" << std::endl;
  } else if (o_count < x_count - 1 || o_count > x_count) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }


  return 0;
}


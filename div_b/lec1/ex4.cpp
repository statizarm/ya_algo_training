/*
** Copyright (c) 08.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <cmath>

int n_greater(std::vector<int> numbers, double num) {
  int left = 0;
  int right = numbers.size();

  while (left != right) {
    int mid = (left + right) / 2;

    if (num > numbers[mid]) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  return numbers.size() - left - 1;
}

int main() {
  int64_t sum = 0;
  int n, dist;

  std::cin >> n;
  std::vector<int> places(n);

  for (auto &place : places) {
    std::cin >> place;
    sum += place;
  }

  double avg = static_cast<double>(sum) / static_cast<double>(n)

  std::cout <<  << std::endl;

  return 0;
}

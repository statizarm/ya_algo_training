/*
** Copyright (c) 08.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <cmath>

int main() {
  int n, place;

  std::cin >> n;

  for (int i = 0; i < n / 2; ++i) {
    std::cin >> place;
  }

  if (n % 2) {
    std::cin >> place;
  }

  std::cout << place << std::endl;

  return 0;
}

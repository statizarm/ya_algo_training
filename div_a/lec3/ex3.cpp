/*
** Copyright (c) 11.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <cstring>
#define SIZE ((uint64_t) 1e6 + 7)

bool set[SIZE];

int main() {
  int n, k;

  std::cin >> n >> k;

  memset(set, 0, sizeof(set));


  while (--k >= 0) {
    int a, b;

    std::cin >> a >> b;

    for (int i = a; i <= n; i += b) {
      set[i] = true;
    }
  }

  for (int i = 6; i <= n; i += 6) {
    set[++i] = set[i] = false;
  }

  int cnt = 0;

  for (int i = 1; i <= n; ++i) {
    if (set[i]) {
      ++cnt;
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}

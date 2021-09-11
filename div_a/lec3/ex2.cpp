/*
** Copyright (c) 11.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <utility>

int main() {
  int n, m;

  std::cin >> n >> m;

  std::set<std::pair<int, int>> edges;
  while (--m >= 0) {
    int u, v;

    std::cin >> u >> v;

    if (u == v) {
      continue;
    }

    auto p = std::minmax(u, v);

    if (edges.find(p) == edges.end()) {
      edges.insert(p);
    }
  }

  std::cout << n << " " << edges.size() << std::endl;
  for (auto e : edges) {
    std::cout << e.first << " " << e.second << std::endl;
  }
  return 0;
}

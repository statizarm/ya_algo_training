/*
** Copyright (c) 06.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sqr_dist(pair<int, int> p1, pair<int, int> p2) {
  int dx = p1.first - p2.first;
  int dy = p1.second - p2.second;

  return dx * dx + dy * dy;
}

template<typename It>
bool contains_duplicates(It &&begin, It &&end) {
  auto prev = *begin;
  for (begin = next(begin); begin != end; begin = next(begin)) {
    if (sqr_dist(prev, *begin) == 0) {
      return true;
    }
    prev = *begin;
  }

  return false;
}

pair<int, int> xy_dist(pair<int, int> p1, pair<int, int> p2) {
  return pair<int, int> {p1.first - p2.first, p1.second - p2.second};
}

int main() {
  int n;
  vector<pair<int, int>> points(4);

  cin >> n;
  while (--n >= 0) {
    for (auto &p : points) {
      cin >> p.first >> p.second;
    }

    sort(points.begin(), points.end());

    if (contains_duplicates(points.begin(), points.end())) {
      std::cout << "NO" << std::endl;
    } else if (xy_dist(points[0], points[1]) == xy_dist(points[2], points[3])) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}

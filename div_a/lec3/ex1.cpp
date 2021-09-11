/*
** Copyright (c) 11.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <sstream>

int set_from_string(bool *res, bool *mask, const std::string &input) {
  int prev_pos = 0;
  int curr_pos;
  int cnt = 0;
  std::istringstream in;
  in.str(input);
  int num;

  while (in >> num) {
    if (mask[num]) {
      ++cnt;
      res[num] = true;
      mask[num] = false;
    }
  }
  /*while ((curr_pos = input.find(' ', prev_pos)) != std::string::npos) {
    if (auto num = std::stoi(input.substr(prev_pos, curr_pos)); mask[num]) {
      ++cnt;
      res[num] = true;
      mask[num] = false;
    }
    prev_pos = curr_pos + 1;
  }

  if (auto num = std::stoi(input.substr(prev_pos, curr_pos)); mask[num]) {
    ++cnt;
    res[num] = true;
    mask[num] = false;
  }*/

  return cnt;
}

void print_set(bool *set, int n) {
  int i = 1;
  while (i <= n && !set[i]) {
    ++i;
  }
  if (i <= n) {
    std::cout << i;
    for (++i; i <= n; ++i) {
      if (set[i]) {
        std::cout << " " << i;
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  int n = std::stoi(input);
  bool *sets[2];
  char curr_set = 0;
  char temp_set = 1;
  //auto start = std::chrono::system_clock::now();

  sets[curr_set] = new bool[n+1];
  sets[temp_set] = new bool[n+1];
  for (int i = 1; i <= n; ++i) {
    sets[curr_set][i] = true;
  }
  memset(sets[temp_set], 0, sizeof(bool) * (n + 1));

  int n_available = n;

  while (std::getline(std::cin, input)) {
    if (input == "HELP") {
      print_set(sets[curr_set], n);
      break;
    } else {
      auto cnt = set_from_string(sets[temp_set], sets[curr_set], input);

      //print_set(sets[curr_set], n);
      if ((cnt << 1) <= n_available) {
        n_available -= cnt;
        std::cout << "NO" << std::endl;
      } else {
        n_available = cnt;
        std::cout << "YES" << std::endl;
        curr_set ^= 1;
        temp_set ^= 1;
      }
      //print_set(sets[curr_set], n);
      memset(sets[temp_set], 0, sizeof(bool) * (n + 1));
    }
  }
  //auto end = std::chrono::system_clock::now();
  //std::chrono::duration<double> diff = end - start;
  //std::cout << diff.count() << std::endl;
  return 0;
}

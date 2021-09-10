/*
** Copyright (c) 10.09.2021 statizarm
** This work is free. You can redistribute it and/or modify it under the
** terms of the Do What The Fuck You Want To Public License, Version 2,
** as published by Sam Hocevar. See the LICENSE file for more details. 
*/
#include <iostream>
#include <string>

template <typename It>
class CycleIterator {
 public:
  using value_type = typename It::value_type;
  CycleIterator(It it, It begin, It end) : it_(it), begin_(begin), end_(end) { }

  CycleIterator &operator++() {
    ++this->it_;
    if (this->it_ == this->end_) {
      this->it_ = this->begin_;
    }

    return *this;
  }

  value_type operator*() {
    return *this->it_;
  }
  It it_;
 protected:
 private:
  It begin_, end_;
};

int main() {
  std::string x, z, y;

  std::cin >> x >> z;
  y = z;

  for (auto x_it = x.begin(); x_it != x.end(); ++x_it) {
    auto ans_it = z.begin();
    CycleIterator c_it {x_it, x.begin(), x.end()};

    for (auto z_it = z.begin(); z_it != z.end() && *z_it == *c_it;) {
      ++c_it;
      ++z_it;
      if (c_it.it_ == x.begin()) {
        ans_it = z_it;
      }
    }
    
    if (auto tmp = std::string {ans_it, z.end()}; tmp.size() < y.size()) {
      y = tmp;
    }
  }

  std::cout << y << std::endl;

  return 0;
}


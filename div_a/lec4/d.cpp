#include <iostream>
#include <iterator>
#include <array>

int main() {
  std::array<uint64_t, 10> first;
  std::array<uint64_t, 10> second;

  first.fill(0);
  second.fill(0);

  char c;
  while (std::cin.get(c) && !isspace(c)) {
    ++first[c - '0'];
  }

  while (std::cin.get(c) && !isspace(c)) {
    ++second[c - '0'];
  }

  bool printed = false;
  std::ostream_iterator<char> out {std::cout};
  for (int i = 9; i > 0; --i) {
    char sym = i + '0';
    uint64_t count = std::min(first[i], second[i]);
    if (count) {
      printed = true;
    }
    std::fill_n(out, std::min(first[i], second[i]), sym);
  }

  if (auto n_zeros = std::min(first[0], second[0]); printed) {
    std::fill_n(out, n_zeros, '0');
  } else if (n_zeros) {
    std::cout << 0;
  } else {
    std::cout << -1;
  }

  std::cout << std::endl;

  return 0;
}

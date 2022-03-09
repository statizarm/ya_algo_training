#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

int main() {
  uint64_t n = 0;
  uint64_t m = 0;
  std::array<uint64_t, 26> letter_count;
  std::string temp;

  std::cin >> n >> m;

  letter_count.fill(0);
  for (int i = 0; i < n; ++i) {
    std::cin >> temp;

    std::for_each(temp.begin(), temp.end(), [&](auto c) {++letter_count[c - 'A'];});
  }
  
  for (int i = 0; i < m; ++i) {
    std::cin >> temp;

    std::for_each(temp.begin(), temp.end(), [&](auto c) {--letter_count[c - 'A'];});
  }

  std::ostream_iterator<char> out{std::cout};
  for (int i = 0; i < letter_count.size(); ++i) {
    char sym = i + 'A';
    std::fill_n(out, letter_count[i], sym);
  }

  std::cout << std::endl;
  return 0;
}

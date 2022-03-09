#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iterator>
#include <array>

std::string make_palindrome(std::string_view source) {
  std::array<uint64_t, 26> symbol_count;
  std::string res;
  res.reserve(source.size());

  symbol_count.fill(0);

  std::for_each(source.begin(), source.end(), [&](auto c) {++symbol_count[c - 'A'];});

  char odd_letter = 0;
  auto inserter = std::back_inserter(res);
  for (int i = 0; i < symbol_count.size(); ++i) {
    char sym = i + 'A';
    if ((symbol_count[i] & 1) && !odd_letter) {
      odd_letter = sym;
    }
    std::fill_n(inserter, symbol_count[i] >> 1, sym);
  }

  auto begin = res.rbegin();
  auto end = res.rend();
  if (odd_letter) {
    res.push_back(odd_letter);
  }

  std::copy(begin, end, std::back_inserter(res));
  return res;
}

int main() {
  uint64_t count;
  std::string in;

  std::cin >> count;
  std::cin >> in;

  std::cout << make_palindrome(in) << std::endl;

  return 0;
}

#include <iostream>
#include <array>
#include <unordered_set>
#include <algorithm>

int main() {
  std::string gems;
  std::array<std::unordered_set<char>, 128> pairs;
  std::array<uint64_t, 128> gem_count;
  uint64_t n, k;
  uint64_t res = 0;

  pairs.fill(std::unordered_set<char>());
  gem_count.fill(0);

  std::cin >> n >> k >> gems;

  for (int i = 0; i < k; ++i) {
    char left, right;
    std::cin >> left >> right;

    pairs[right].insert(left);
  }

  for (auto&& g : gems) {
    std::for_each(pairs[g].begin(), pairs[g].end(), [&](auto&& c) {
      res += gem_count[c];
    });

    ++gem_count[g];
  }

  std::cout << res << std::endl;

  return 0;
}


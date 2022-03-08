#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>


int calc_sum(std::vector<int> colors) {
  int sum = 0;

  auto [min, max] = std::minmax_element(colors.begin(), colors.end());

  return *max - *min;
}

auto min_colors(std::vector<std::vector<int>> sequences) {
  for (auto &seq : sequences) {
    std::sort(seq.begin(), seq.end());
  }

  std::vector<std::vector<int>::iterator> its(sequences.size());
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>> , std::greater<std::pair<int, int>>> queue;
  std::vector<int> colors(sequences.size());

  for (int i = 0; i < sequences.size(); ++i) {
    its[i] = sequences[i].begin();
    colors[i] = *its[i];
    ++its[i];
    if (its[i] != sequences[i].end()) {
      queue.emplace(*its[i], i);
    }
  }

  int min_sum = calc_sum(colors);
  auto colors_with_min_sum = colors;
  while (!queue.empty()) {
    auto [color, seq_id] = queue.top();
    queue.pop();

    colors[seq_id] = color;

    if (int sum = calc_sum(colors); sum < min_sum) {
      min_sum = sum;
      colors_with_min_sum = colors;
    }

    ++its[seq_id];
    if (its[seq_id] != sequences[seq_id].end()) {
      queue.emplace(*its[seq_id], seq_id);
    }
  }

  return colors_with_min_sum;
}


int main() {
  int n;
  std::vector<std::vector<int>> sequences(4);

  for (int i = 0; i < 4; ++i) {
    std::cin >> n;
    sequences[i].resize(n);
    for (int j = 0; j < n; ++j) {
      std::cin >> sequences[i][j];
    }
  }

  for (auto c : min_colors(sequences)) {
    std::cout << c << ' ';
  }

  std::cout << std::endl;

  return 0;
}


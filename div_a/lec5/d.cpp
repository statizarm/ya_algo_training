#include <iostream>
#include <type_traits>
#include <vector>


int main() {
    std::string bracket_sequence;
    uint64_t res = 0;

    std::cin >> bracket_sequence;
    std::vector<uint64_t> n_open(bracket_sequence.size() + 1, 0);

    res = bracket_sequence.size() + 1;
    res = res * (res + 1) / 2;

    for (int i = 1; i < n_open.size(); ++i) {
        auto prev_i = i - 1;
        auto bracket = bracket_sequence[prev_i];
        switch(bracket) {
            case '(':
                n_open[i] = n_open[prev_i] + 1;
                break;
            case ')':
                n_open[i] = n_open[prev_i] - 1;
                break;
        }
    }

    auto start = 0;
    uint64_t delta;
    for (int i = 1; i < n_open.size(); ++i) {
        if (n_open[i] > 0 && start == 0) {
            start = i;
        } else if (n_open[i] == 0) {
            delta = i - start + 1;
            start = 0;
            res += (delta * (delta - 1)) / 2;
        }
    }

    std::cout << res << std::endl;
    return 0;
}

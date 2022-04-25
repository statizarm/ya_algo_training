#include <iostream>

int main() {
    std::string input_seq;

    std::cin >> input_seq;

    int64_t res = 0;
    int64_t count[2] = {0, 1};
    int64_t it = 1;

    while (it < input_seq.size()) {
        if (input_seq[it] != input_seq[it - 1]) {
            count[0] = count[1];
            count[1] = 1;
            res += count[0];
        } else {
            count[1] += 1;
            res += count[0];
        }
        ++it;
    }

    res += (count[0] + 1) * count[1];

    std::cout << res << std::endl;
}

#include <iostream>

#define MAX_N ((int)3e5)

uint64_t prefix_sum[MAX_N + 1];

int main() {
    int n, q;

    std::cin >> n >> q;
    for (int i = 0; i < n;) {
        int ni = i + 1;
        uint64_t number;

        std::cin >> number;

        prefix_sum[ni] = prefix_sum[i] + number;

        i = ni;
    }

    while (--q >= 0) {
        uint64_t left, right;
        std::cin >> left >> right;

        if (left < 1 or right < 1) {
            throw std::runtime_error("Out of range");
        }

        std::cout << prefix_sum[right] - prefix_sum[left - 1] << std::endl;
    }

    return 0;
}

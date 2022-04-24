#include <iostream>
#include <vector>

#define MAX_HEAPS ((int64_t) 1e5)


uint8_t heaps[MAX_HEAPS];


int main() {
    int k;
    int n = 0;

    std::cin >> k;
    while (--k >= 0) {
        int val, count;
        std::cin >> val >> count;

        while (--count >= 0) {
            heaps[n] = val;
            ++n;
        }
    }

    int64_t pos[2] = {0, static_cast<int64_t>(n - 1)};
    int64_t curr[2] = {heaps[pos[0]], heaps[pos[1]]};
    int64_t next[2] = {heaps[pos[0] + 1], heaps[pos[1] - 1]};

    while (pos[1] - pos[0] > 2) {
        std::cout << "left curr: " << curr[0] << std::endl
                  << "right curr: " << curr[1] << std::endl;
        std::cout << "left next: " << next[0] << std::endl
                  << "right next: " << next[1] << std::endl;

        auto min = std::min(curr[0], curr[1]);
        for (auto i : {0, 1}) {
            curr[i] -= min;
            next[i] += min;
        }
        for (auto i : {0, 1}) {
            if (curr[i] == 0) {
                pos[i] = i ? pos[i] - 1 : pos[i] + 1;
                curr[i] = next[i];
                next[i] = heaps[pos[i]];
            }
        }
    }

    std::cout << pos[1] - pos[0] + 1 << std::endl
              << curr[0] << ' ' << curr[1] << std::endl;


    return 0;
}

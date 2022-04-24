#include <cctype>
#include <cstdint>
#include <iostream>
#include <map>


bool is_triangle(uint64_t a, uint64_t b, uint64_t c) {
    return c < a + b;
}


bool is_obtuse(uint64_t a, uint64_t b, uint64_t c) {
    return c * c > a * a + b * b;
}


int main() {
    std::map<uint64_t, int> tube_count;
    int k;

    std::cin >> k;
    while (--k >= 0) {
        int tube;
        std::cin >> tube;
        if (tube_count.find(tube) == tube_count.end()) {
            tube_count[tube] = 0;
        }
        ++tube_count[tube];
    }

    auto a = tube_count.begin();
    auto end = tube_count.end();
    uint64_t sum = 0;
    while (a != end) {
        auto b = a;
        auto c = b;

        while (c != end) {
            if (!is_obtuse(a->first, b->first, c->first)) {
                c = std::next(c);
            } else if (!is_triangle(a->first, b->first, c->first)) {
                b = std::next(b);
            } else {
                auto k = a->second * b->second;
                if (a == b) {
                    k = (a->second * (b->second - 1)) / 2;
                }
                sum += k * c->second;
                b = std::next(b);
            }
        }

        a = std::next(a);
    }

    std::cout << sum << std::endl;
    return 0;
}

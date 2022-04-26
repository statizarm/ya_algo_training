#include <iostream>
#include <iterator>


int main() {
    std::istream_iterator<char> it(std::cin);
    std::istream_iterator<char> end;
    int n_open = 0;

    while (it != end) {
        switch(*it) {
            case '(':
                ++n_open;
                break;
            case ')':
                --n_open;
                break;
            default:
                break;
        }

        if (n_open < 0) {
            break;
        }

        ++it;
    }

    if (n_open != 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <array>


template <class Cont>
std::string greates_common_subseq(Cont sequences) {
    std::string res;
    std::array<std::array<int, 27>, sequences.size()> sym_count;
    std::array<int, sequences.size()> positions;

    positions.fill(0);
    for (int i = 0; i < sequences.size(); ++i) {
        auto& counter = sym_count[i];
        counter.fill(0);
        for (const auto& elem : sequences[i]) {
            ++counter[elem - 'a'];
        }
    }

    for (int i = 26; i >= 0; --i) {
        auto min_count = sym_count[0][i];
        auto letter = 'a' + i;
        for (int j = 1; j < sequences.size(); ++j) {
            min_count = std::min(min_count, sym_count[j][i]);
        }
        for (int j = 0; j < sequences.size(); ++j) {
            auto& pos = positions[j];
            auto& seq = sequences[j];
            auto to_delete = min_count;

            while(to_delete > 0) {
                if (seq[pos] == letter) {
                    --to_delete;
                }
                --sym_count[j][seq[pos] - 'a'];
                ++pos;
            }
        }
        res.insert(res.size(), min_count, letter);
    }

    return res;
}


int main() {
    std::array<std::string, 2> names;

    for (auto& seq : names) {
        std::cin >> seq;
    }

    std::cout << greates_common_subseq(names) << std::endl;
}

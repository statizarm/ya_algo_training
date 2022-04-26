#include <iostream>
#include <algorithm>

#define MAX_N ((int) 1e5)

std::pair<int, int> group_size[MAX_N];
std::pair<int, int> room_size[MAX_N];
int group_position[MAX_N];

int main() {
    int n, m;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        std::cin >> group_size[i].first;
        group_size[i].second = i;
        group_position[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> room_size[i].first;
        room_size[i].second = i + 1;
    }

    std::sort(group_size, group_size + n);
    std::sort(room_size, room_size + m);

    int res = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (group_size[i].first < room_size[j].first) {
            group_position[group_size[i].second] = room_size[j].second;
            ++res;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    std::cout << res << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << group_position[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

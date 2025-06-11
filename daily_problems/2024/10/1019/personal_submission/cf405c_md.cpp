// 1019
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            std::cin >> val;
            if (i == j) {
                sum ^= val;
            }
        }
    }

    int q;
    std::cin >> q;
    std::string ret{};
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 3) {
            ret += std::string(1, sum + '0');
        } else {
            int x;
            std::cin >> x;
            x;
            sum ^= 1;
        }
    }

    std::cout << ret << '\n';

    return 0;
}
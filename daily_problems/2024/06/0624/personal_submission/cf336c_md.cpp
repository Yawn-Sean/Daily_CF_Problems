// 0624
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(a));

    constexpr int c_max_bit = 30;
    std::vector<std::vector<int>> has_bit(c_max_bit + 1);
    for (auto num : a) {
        for (int i = 0; i <= c_max_bit; ++i) {
            if ((num >> i) & 1) {
                has_bit[i].push_back(num);
            }
        }
    }

    for (int i = c_max_bit; i >= 0; --i) {
        int ans = std::accumulate(begin(has_bit[i]), end(has_bit[i]), (1 << (i + 1)) - 1, std::bit_and<int>());
        if ((ans & (ans - 1)) == 0) {
            std::cout << size(has_bit[i]) << '\n';
            for (auto num : has_bit[i]) {
                std::cout << num << ' ';
            }
            std::cout << '\n';
            return 0;
        }
    }
    std::cout << "-1\n";

    return 0;
}
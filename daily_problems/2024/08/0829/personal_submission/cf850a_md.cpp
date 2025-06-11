// 0829
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n > (1 << 5) + 1) {
        std::cout << "0\n";
        return 0;
    }

    std::vector<std::array<int, 5>> points(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> points[i][j];
        }
    }

    std::vector<int> ret;
    for (int i = 0; i < n; ++i) {
        const auto& a = points[i];
        auto is_good_point = [&]() -> bool{
            for (int j = 0; j < n; ++j) {
                const auto& b = points[j];
                for (int k = j + 1; k < n; ++k) {
                    const auto& c = points[k];

                    int product = 0;
                    for (int v = 0; v < 5; ++v) {
                        product += (b[v] - a[v]) * (c[v] - a[v]);
                    }

                    if (product > 0) {
                        return false;
                    }
                }
            }
            return true;
        };

        if (is_good_point()) {
            ret.push_back(i);
        }
    }

    std::cout << size(ret) << '\n';
    for (int i = 0; i < size(ret); ++i) {
        std::cout << ret[i] + 1 << " \n"[i + 1 == size(ret)];
    }

    return 0;
}
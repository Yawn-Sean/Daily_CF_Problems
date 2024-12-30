// 0824
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> ys(n);
    std::copy_n(std::istream_iterator<i64>(std::cin), n, begin(ys));
    std::vector<i64> xs(n);
    std::iota(begin(xs), end(xs), 0);

    for (int p2 = 0; p2 < 3; ++p2) {
        for (int p1 = 0; p1 < p2; ++p1) {
            i64 k = (ys[p2] - ys[p1]) * 2 / (p2 - p1);
            std::set<i64> bs;
            std::transform(begin(xs), end(xs), std::inserter(bs, end(bs)), [k, &ys](i64 x) {
                return 2ll * ys[x] - k * x;
            });

            if (size(bs) == 2) {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }
    std::cout << "No\n";
    return 0;
}
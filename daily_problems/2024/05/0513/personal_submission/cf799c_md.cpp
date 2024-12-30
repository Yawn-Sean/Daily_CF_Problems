// 0513
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c, d;
    std::cin >> n >> c >> d;
    optional<int> max_b_from_d = nullopt;
    optional<int> max_b_from_c = nullopt;
    Fenwick<Max> fenwick_d(1e5 + 1);
    Fenwick<Max> fenwick_c(1e5 + 1);

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int p; int b; char type;
        cin >> b >> p >> type;
        if (type == 'D') {
            if (p <= d) {
                max_b_from_d = max(max_b_from_d.value_or(0), b);
                auto last_b = fenwick_d.sum(d - p + 1).x;
                if (last_b > 0) {
                    ret = std::max(ret, b + last_b);
                }
                fenwick_d.add(p, b);
            }
        } else {
            if (p <= c) {
                max_b_from_c = max(max_b_from_c.value_or(0), b);
                auto last_b = fenwick_c.sum(c - p + 1).x;
                if (last_b > 0) {
                    ret = std::max(ret, b + last_b);
                }
                fenwick_c.add(p, b);
            }
        }
    }

    if (max_b_from_d.has_value() && max_b_from_c.has_value()) {
        ret = max(ret, max_b_from_d.value() + max_b_from_c.value());
    }

    std::cout << ret << endl;
    return 0;
}
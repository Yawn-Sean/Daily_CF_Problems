// 0624
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 A, B, n;
    std::cin >> A >> B >> n;

    while (n--) {
        i64 l, t, m;
        std::cin >> l >> t >> m;


        auto cando = [&](i64 r) -> bool {
            i64 sum = (A + (l - 1) * B + A + (r - 1) * B) * 1ll * (r - l + 1) / 2;
            return (sum <= t * m) && (A + (r - 1) * B <= t);
        };

        i64 low = l;
        i64 high = l + t * m + 1;
        while (low + 1ll < high) {
            auto mid = low + (high - low) / 2;
            if (cando(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (cando(high)) {
            std::cout << high << '\n';
        } else if (cando(low)) {
            std::cout << low << '\n';
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}
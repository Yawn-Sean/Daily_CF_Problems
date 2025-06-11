// 0831
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, l, r;
    std::cin >> n >> l >> r;
    --l; --r;

    auto f = [&](auto f, i64 n, i64 l, i64 r) -> i64 {
        if (n <= 1) {
            return n;
        }

        i64 bit_len = 64 - __builtin_clzll(n);
        i64 tree_siz = (1ll << (bit_len - 1)) - 1;

        i64 ret = 0;
        if (l <= tree_siz && tree_siz <= r) {
            ret += n % 2;
        }

        if (l < tree_siz) {
            ret += f(f, n / 2, l, std::min(r, tree_siz - 1));
        } 
        
        if (r > tree_siz) {
            ret += f(f, n / 2, std::max(l - tree_siz - 1, 0ll), r - tree_siz - 1);
        }

        return ret;
    };

    std::cout << f(f, n, l, r) << '\n';
    return 0;
}
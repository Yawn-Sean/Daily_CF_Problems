//  A. Harry Potter and Three Spells
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
using f128 = long double;

void nhir() {
    f128 a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    f128 ab = b / a;
    f128 cd = d / c;
    f128 ef = f / e;
    if (ab == 0.0 / 0.0) ab = 1.0;
    if (ef == 0.0 / 0.0) ef = 1.0;
    if (cd > 1e15) {
        std::cout << "Ron\n";
        return;
    }
    if (ab * cd > 1e15) {
        std::cout << "Ron\n";
        return;
    }
    if (ab * cd * ef > 1 + 1e-5) {
        std::cout << "Ron\n";
        return;
    } else {
        std::cout << "Hermione\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}

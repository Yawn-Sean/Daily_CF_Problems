#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

i64 cal(i64 C, i64 ha, i64 wa, i64 hb, i64 wb) {
    i64 ans = C / wb * hb;
    std::set<i64> vis;
    i64 x = wa;
    while (x <= C && !vis.count(x % wb)) {
        vis.insert(x % wb);
        ans = std::max(ans, x / wa * ha + (C - x) / wb * hb);
        x += wa;
    }
    x = C % wa;vis.clear();
    while (x <= C && !vis.count(x % wb)) {
        vis.insert(x % wb);
        ans = std::max(ans, x / wb * hb + (C - x) / wa * ha);
        x += wa;
    }
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 C, h1, h2, w1, w2;std::cin >> C >> h1 >> h2 >> w1 >> w2;
    if (w1 < w2)std::swap(w1, w2), std::swap(h1, h2);
    //w1>=w2
    //h1/w1<=h2/w
    std::cout << cal(C, h1, w1, h2, w2);
    return 0;
}

#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;

constexpr double eps = 1e-12;

/*
    优先拿大的

    考虑p[i]拿不拿进来？

    (1 - p) * res + prod * p > res

    p * (prod - res) > 0

    prod - res > 0
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<double> p(n);
    for (int i = 0; i < n; ++ i) std::cin >> p[i];
    std::sort(p.begin(), p.end());
    double res = 0, s = 1;
    for (int i = n - 1; ~i; -- i) {
        if (s - res > eps) res += (s - res) * p[i];
        else break;
        s *= (1 - p[i]);
    }
    std::cout << std::setprecision(15) << res;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> w(n);
    for (int i = 0; i < n; i ++ ) std::cin >> w[i];
    int bound = 500;
    int p;
    std::cin >> p;
    std::vector<std::vector<PII>> q(bound);
    std::vector<i64> ans(p);
    for (int i = 0, a, b; i < p; i ++ ) {
        std::cin >> a >> b;
        -- a;
        if (b >= bound) {
            i64& s = ans[i];
            for (int j = a; j < n; j += b)
                s += w[j];
        }
        else
            q[b].push_back( { a, i } );
    }

    for (int i = 1; i < bound; i ++ ) {
        if (q[i].size()) {
            std::vector<i64> acc(n + i);
            for (int j = n - 1; j >= 0; j -- ) {
                acc[j] = acc[j + i] + w[j];
            }
                std::cout << '\n';
            for (auto [j, id] : q[i])
                ans[id] = acc[j];
        }
    }

    for (i64 x : ans) std::cout << x << '\n';
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
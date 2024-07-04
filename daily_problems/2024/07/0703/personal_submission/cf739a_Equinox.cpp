#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const i64 inf = 1e18 + 7, P = 1e9 + 7;

/*
min { r - l + 1 }
*/
void solve() {
    int n, m;
    std::cin >> n >> m;
    int mi = 1e9;
    for (int i = 0, l, r; i < m; i ++ ) 
        std::cin >> l >> r, mi = std::min(mi, r - l + 1);
    std::cout << mi << '\n';
    for (int i = 0; i < n; i ++ )
        std::cout << (i % mi) << " \n"[i == n - 1];
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
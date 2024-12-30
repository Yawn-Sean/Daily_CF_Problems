#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;

const int inf = 1e9;


void solve() {
    int N, x;
    std::cin >> N >> x;
    if (N == 1) {
        std::cout << "YES\n" << x;
        return;
    }
    else if(N == 2) {
        if (x) {
            std::cout << "YES\n" << 0 << ' ' << x;
            return;
        }
        std::cout << "NO";
        return;
    }
    std::cout << "YES\n";
    int pre = 0, o = 1 << 17, w = 1 << 18;
    for (int i = 1; i <= N - 3; i ++ ) std::cout << i << ' ', pre ^= i;
    std::cout << (o ^ pre) << ' ' << (w ^ o) << ' ' << (x ^ w);
}


int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
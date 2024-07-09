#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;

void solve() {
    i64 res = 0;
    int n;
    std::cin >> n;

    std::vector<int> a(n), cnt(11);
    for (int i = 0; i < n; i ++ ) {
        std::cin >> a[i];
        int x = a[i], c = 0;
        while (x)
            ++ c, x /= 10;
        ++ cnt[c];
    }  

    for (int x : a) {
        i64 pw = 1LL, w = 0LL;
        for (int j = 1; j < 11; j ++ ) {
            w = (w + x % 10 * pw) % P;
            x /= 10;
            res = (res + ((x * pw * 100 + w) % P) * cnt[j] % P) % P;
            res = (res + ((x * pw * 100 + w * 10) % P) * cnt[j] % P) % P;
            pw = pw * 100 % P;
        }
    }
    std::cout << res;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}

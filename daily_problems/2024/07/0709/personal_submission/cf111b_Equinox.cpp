#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    const int N = 1e5 + 10;
    std::vector<int> last(N);
    auto func = [&](int x, int y, int p) -> int {
        int res = 0;
        for (int i = 1; i * i <= x; i ++ ) {
            if (x % i == 0) {
                res += (last[i] < p - y);
                if (i * i < x) {
                    res += (last[x / i] < p - y);
                }
                last[i] = last[x / i] = p;
            }
        }
        return res;
    };

    for (int i = 1, x, y; i <= n; i ++ ) {
        std::cin >> x >> y;
        std::cout << func(x, y, i) << '\n';
    }
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
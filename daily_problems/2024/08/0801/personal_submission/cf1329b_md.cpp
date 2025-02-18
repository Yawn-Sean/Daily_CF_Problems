// 0801
// b_i = a_1 ^ a_2 ^ ... ^ a_i, and b_i should have one more significant bit than b_{i-1}

#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int d, m;
    std::cin >> d >> m;   

    std::vector<int> cnt;
    for (int i = 0; i <= 30 && (d >= (1 << i)); ++i) {
        if (d >= (1 << (i + 1))) {
            cnt.push_back(1 << i);
        } else {
            // can't use all (1 << i) because some of the values >= (1 << i) are larger than d
            cnt.push_back(d - (1 << i) + 1);
            break;
        }
    }

    i64 ans = std::accumulate(begin(cnt), end(cnt), 1ll, [&](i64 acc, int x) {
        return acc * (x + 1) % m;
    });

    std::cout << (ans - 1 + m) % m << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
} 
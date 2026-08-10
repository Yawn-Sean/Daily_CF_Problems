#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int r, c, m, k;
    std::cin >> r >> c >> m >> k;

    if (k > std::min({r, c, m}) || k * std::max(r, c) < m) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector s(r, std::vector<char>(c, '.'));
    int x = 0, y = 0;
    for (int i = 0; i < k; i++) {
        int nx = (x + i) % r, ny = (y + i) % c;
        s[nx][ny] = '#';
    }
    m -= k;

    if (c > r) {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (m == 0) {
                    break;
                }
                if (s[x][y] == '.') {
                    s[x][y] = '#';
                    m--;
                }   
            }
        }
    } else {
        for (int y = 0; y < c; y++) {
            for (int x = 0; x < r; x++) {
                if (m == 0) {
                    break;
                }
                if (s[x][y] == '.') {
                    s[x][y] = '#';
                    m--;
                }   
            }
        }
    }


    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            std::cout << s[x][y];
        }
        std::cout << "\n";
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

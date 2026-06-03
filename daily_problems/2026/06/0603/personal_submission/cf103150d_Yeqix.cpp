#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    i64 n, d;
    cin >> n >> d;

    if (d > (n / 2) * (n / 2) * 2) {
        cout << "NO\n";
        return;
    }

    auto print = [&](int a, int b, int c, int d) {
        cout << a << " " << b << " " << c << " " << d << "\n";
        cout << c << " " << d << " " << a << " " << b << "\n";
    };

    cout << "YES\n";
    if (n & 1) {
        for (int i = 1; i <= (n + 1) / 2; i++) {
            for (int j = 1; j <= (n + 1) / 2; j++) {
                if (i == 1 && j == 1 || (i == (n + 1) / 2 && j == (n + 1) / 2)) {
                    continue;
                }
                print(i, j, i + n / 2, j + n / 2);
            }
        }

        for (int i = 1; i <= n / 2; i++) {
            for (int j = (n + 1) / 2 + 1; j <= n; j++) {
                print(i, j, i + (n + 1) / 2, j - (n + 1) / 2);
            }
        }

        cout << 1 << " " << 1 << " " << (n + 1) / 2 << " " << (n + 1) / 2 << "\n";
        cout << (n + 1) / 2 << " " << (n + 1) / 2 << " " << n << " " << n << "\n";
        cout << n << " " << n << " " << 1 << " " << 1 << "\n";
    } else {
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= n; j++) {
                if (j <= n / 2) {
                    print(i, j, i + n / 2, j + n / 2);
                } else {
                    print(i, j, i + n / 2, j - n / 2);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void rev(char& c) {
    c = (c - '0' ^ 1) + '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    if (n > 1 && m > 1 && k == n * m - 1) {
        cout << "NO\n";
        return 0;
    }

    vector<string> f(n, string(m, '0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i * m + j + 1 > k) {
                if (i >= 1 && i == (k - 1) / m && (k - 1) % m != m - 1 && j == k % m) {
                    f[i][j] = (f[i - 1][j] - '0' ^ 1) + '0';
                } else if (i == 0) {
                    f[i][j] = f[i][j - 1];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            } else {
                f[i][j] = (i + j & 1) + '0';
            }
        }
    }

    if (n > 1 && m > 1 && (k - 1) % m == m - 2) {
        rev(f[n - 1][m - 2]);
    }

    cout << "YES\n";
    for (const auto& x : f) {
        cout << x << "\n";
    }
    return 0;
}
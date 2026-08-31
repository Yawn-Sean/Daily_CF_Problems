#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int md = 1e9 + 7;

i64 qpow(i64 a, i64 b) {
    a %= md;
    i64 ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % md;
            b--;
        }
        a = a * a % md;
        b >>= 1;
    }
    return ans;
}

vector<i64> kitamasa(const vector<i64>& a, i64 n) {
    int k = a.size();
    auto deal = [&](const vector<i64>& A, vector<i64> B) -> vector<i64> {
        vector<i64> C(k);
        for (auto& v : A) {
            for (int j = 0; j < k; j++) {
                C[j] = (C[j] + v * B[j]) % md;
            }

            i64 bk1 = B.back();
            for (int i = k - 1; i >= 1; i--) {
                B[i] = (B[i - 1] + bk1 * a[k - 1 - i]) % md;
            }
            B[0] = bk1 * a[k - 1] % md;
        }
        return C;
    };

    vector<i64> res(k), c(k);
    res[0] = c[1] = 1;
    while (n > 0) {
        if (n & 1) {
            res = deal(c, res);
        }
        c = deal(c, c);
        n >>= 1;
    }

    return res;
}

i64 a[129][129];
i64 gauss(i64 n) {
    i64 c, r;
    for (c = 0, r = 0; c < n; c++) {
        i64 t = r;
        for (int i = r; i < n; i++) {
            if (a[i][c] > a[t][c]) {
                t = i;
            }
        }
        for (int j = c; j < n + 1; j++) {
            swap(a[t][j], a[r][j]);
        }
        for (int j = n; j >= c; j--) {
            a[r][j] = a[r][j] * qpow(a[r][c], md - 2) % md;
        }
        for (int i = r + 1; i < n; i++) {
            if (a[i][c]) {
                for (int j = n; j >= c; j--) {
                    a[i][j] = (a[i][j] - a[r][j] * a[i][c] % md + md) % md;
                }
            }
        }
        r++;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] = (a[i][n] - a[i][j] * a[j][n] % md + md) % md;
        }
    }
    return 0;
}

constexpr i64 N = 1e9 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    vector<i64> f(k), g(k);
    for (auto& x : f) {
        cin >> x;
    }
    for (auto& x : g) {
        cin >> x;
    }

    if (k == 1) {
        cout << qpow(f[0], g[0]) << '\n';
        return 0;
    }

    vector<vector<i64>> w(k + 1);
    w[0] = kitamasa(f, N);
    for (int i = 1; i <= k; i++) {
        w[i] = kitamasa(f, N - g[i - 1]);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = w[j + 1][i] % md;
        }
        a[i][k] = w[0][i] % md;
    }

    gauss(k);

    for (int i = 0; i < k; i++) {
        cout << a[i][k] << " ";
    }

    return 0;
}
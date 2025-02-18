#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;
using i64 = long long;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read(), k = read();
    i64 res = 0;
    ve<i64> d(k + 1);
    d[1] = 0, d[2] = 1;
    rep(i, 3, k + 1) {
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
    }
    auto solve = [&](int n, int m) {
        i64 res = 1, button = 1;
        rep(i, 1, m + 1) {
            button *= i;
            res *= n;
            n--;
        }
        return res / button;
    };
    rep(i, n - k, n + 1) {
        res += solve(n, n - i) * d[n - i];
    }
    cout << res + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

using pl = pair<int64_t, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), m = red(), k = red(), s = red();
    ve<int64_t> e(m);
    ve<pl> f(m);
    ve<int> a(n), b(n), c(m), d(m);
    generate(all(a), red);
    generate(all(b), red);
    rep(i, 0, m) {
        int op = red();
        if (op == 1) {
            c[i] = red();
        } else {
            d[i] = red();
        }
    }

    auto check = [&](int mid, int flag) -> bool {
        int64_t sum = 0;
        int mx1 = 1e9 + 7, mx2 = 1e9 + 7, d1, d2;
        rep(i, 0, mid) {
            if (mx1 > a[i]) {
                mx1 = a[i];
                d1 = i;
            }
            if (mx2 > b[i]) {
                mx2 = b[i];
                d2 = i;
            }
        }

        rep(i, 0, m) {
            e[i] = (int64_t)c[i] * mx1 + (int64_t)d[i] * mx2;
        }
        sort(all(e));
        rep(i, 0, k) {
            sum += e[i];
        }
        if (flag) {
            rep(i, 0, m) {
                f[i] = {(int64_t)c[i] * mx1 + (int64_t)d[i] * mx2, i};
            }
            sort(all(f));
            rep(i, 0, k) {
                if (c[f[i].se]) {
                    cout << f[i].se + 1 << ' ' << d1 + 1 << '\n';
                } else {
                    cout << f[i].se + 1 << ' ' << d2 + 1 << '\n';
                }
            }
        }
        return sum <= s;
    };

    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (check(mid, 0)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (check(low, 0)) {
        cout << low << '\n';
        check(low, 1);
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/problemset/problem/609/D
*/
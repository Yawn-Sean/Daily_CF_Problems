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
    int n = read();
    const int N = 5e3 + 7;
    ve<int> a(n);
    generate(all(a), read);
    sort(all(a));
    ve<int> cnt(N);
    ve<double> d(N);
    int tot = n * (n - 1) / 2;
    rep(i, 0, n) {
        rep(j, 0, i) {
            cnt[a[i] - a[j]]++;
        }
    }
    rep(i, 1, 5001) {
        rep(j, 1, 5001 - i) {
            d[i + j] += (1.0 * cnt[i] / tot) * (1.0 * cnt[j] / tot);
        }
    }
    double res = 0;
    rep(i, 1, 5001) {
        d[i] += d[i - 1];
    }
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            int dif = a[j] - a[i];
            res += d[dif - 1] / tot;
        }
    }
    cout << res << '\n';
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
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<i128> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }

    double ans = 0;
    i64 cnt = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        ans += 1.0 * (pre[n] - pre[i - 1] - pre[n - i]) / i;
    }

    cout << fixed << setprecision(12) << ans / cnt << "\n";
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
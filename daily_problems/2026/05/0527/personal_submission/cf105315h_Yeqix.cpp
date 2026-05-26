#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }

    sort(f.begin() + 1, f.end(), [&](auto x, auto y) { return x[1] < y[1]; });

    i64 ans = LLONG_MIN;
    priority_queue<i64, vector<i64>, greater<i64>> que;
    i64 res = 0;
    for (int i = 1; i <= n; i++) {
        que.push(f[i][0]);
        res += f[i][0];
        if (i > k) {
            res -= que.top();
            que.pop();
        }
        if (i >= k) {
            ans = max(ans, res - f[i][1]);
        }
    }

    cout << ans << "\n";
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
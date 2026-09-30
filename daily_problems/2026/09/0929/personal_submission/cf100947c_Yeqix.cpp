#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n * 2 + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    vector<vector<i64>> pre(2, vector<i64>(n * 2 + 1));
    for (int i = 1; i <= n * 2; i++) {
        pre[0][i] = pre[0][i - 1];
        pre[1][i] = pre[1][i - 1];
        pre[i & 1][i] += a[i];
    }

    i64 ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i & 1][i + n - 1] - pre[i & 1][i - 1]);
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
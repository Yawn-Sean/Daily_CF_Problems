#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n), pre(n+1), suf(n+1);
    for (int i = 0; i < n; ++i) cin >> a[i], pre[i+1] = pre[i] | a[i];
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i+1] | a[i];
    long long m = 1;
    for (int i = 0; i < k; ++i) m *= x;
    long long ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, (a[i] * m) | pre[i] | suf[i+1]);
    cout << ans << endl;
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

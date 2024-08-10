#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), pre(n+1);
    for (int i = 0; i < n; ++i) cin >> a[i], pre[i+1] = pre[i] + a[i];
    vector<ll> d(n+1); d[n] = pre[n];
    for (int i = n - 1; i >= 2; --i) d[i] = max(d[i+1], pre[i] - d[i+1]);
    cout << d[2] << '\n';
}

// -6 -8 -5

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

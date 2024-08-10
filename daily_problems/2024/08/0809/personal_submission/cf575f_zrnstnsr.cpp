#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n), r(n);
    ll ans = 0;
    int s = x, t = x;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    for (int i = 0; i < n; ++i) {
        if (l[i] > t) {
            ans += l[i] - t;
            s = t; t = l[i];
        } else if (r[i] < s) {
            ans += s - r[i];
            t = s; s = r[i];
        } else {
            s = max(s, l[i]);
            t = min(t, r[i]);
        }
    }
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

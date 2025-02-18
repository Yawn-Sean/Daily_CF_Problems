#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int x1, x2;
    cin >> x1 >> x2;
    vector<pair<ll, ll>> y(n);
    for (int i = 0; i < n; ++i) {
        ll k, b;
        cin >> k >> b;
        y[i] = {k * x1 + b, k * x2 + b};
    }
    ranges::sort(y);
    bool suc = true;
    for (int i = 1; i < n; ++i) suc = suc && y[i].second >= y[i-1].second;
    println("{}", suc ? "NO" : "YES");
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

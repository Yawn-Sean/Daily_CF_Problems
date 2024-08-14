#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    set<int> y;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        y.insert(v);
    }
    int v = 1;
    while (v) {
        auto p = prev(y.end());
        for (v = *p >> 1; v; v >>= 1) if (!y.count(v)) {
            y.erase(p);
            y.insert(v);
            break;
        }
    }
    for (auto v: y) cout << v << ' ';
    cout << endl;
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

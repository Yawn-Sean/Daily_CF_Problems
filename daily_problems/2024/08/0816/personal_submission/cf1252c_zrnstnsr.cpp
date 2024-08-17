#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> er, ec;
    int u, v;
    cin >> u;
    for (int i = 1; i < n; ++i) {
        cin >> v;
        if ((u + v) & 1) er.push_back(i), u = v;
    }
    er.push_back(n);
    cin >> u;
    for (int i = 1; i < n; ++i) {
        cin >> v;
        if ((u + v) & 1) ec.push_back(i), u = v;
    }
    ec.push_back(n);
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (lower_bound(er.begin(), er.end(), r1) == lower_bound(er.begin(), er.end(), r2) && lower_bound(ec.begin(), ec.end(), c1) == lower_bound(ec.begin(), ec.end(), c2) ? "YES\n" : "NO\n");
    }
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

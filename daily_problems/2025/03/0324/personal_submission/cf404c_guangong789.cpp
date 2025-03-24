#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, d;
    cin >> n >> k;
    vector<vector<int>> v(n);
    for (int i = 1; i <= n; ++i) {
        cin >> d;
        v[d].emplace_back(i);
    }
    if (v[0].size() != 1) {  // 根节点不止一个
        cout << -1;
        return;
    }
    for (int i = 1; i < n; ++i) {
        if (i == 1) {
            if (v[i].size() > k) {  // 第一层根节点最多连k个
                cout << -1;
                return;
            }
        } else if (v[i].size() > v[i-1].size() * (k-1)) {
            // 其余层因为连了一个父节点，每一个节点最多还能连k-1个
            cout << -1;
            return;
        }
    }
    // 可以合法构造
    cout << n-1 << '\n';
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            // 下一层
            if (i == 1) {
                cout << v[i-1][0] << ' ' << v[i][j] << '\n';
            } else {
                cout << v[i-1][j / (k-1)] << ' ' << v[i][j] << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
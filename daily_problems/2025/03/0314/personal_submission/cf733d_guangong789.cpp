#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx_mn = 0, idx = 0;
    vector<vector<int>> v(n, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        ranges::sort(v[i], greater<>{});
        v[i][3] = i+1;
        if (v[i][2] > mx_mn) {
            mx_mn = v[i][2];
            idx = v[i][3];
        }
    }
    pair<int, int> ans;
    ans = {idx, 0};
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return a[2] > b[2];
    });
    for (int i = 0; i < n-1; ++i) {
        if (v[i][0] == v[i+1][0] && v[i][1] == v[i+1][1]) {
            int mn = v[i][2] + v[i+1][2];
            mn = min(mn, v[i][1]);
            if (mn > mx_mn) {
                mx_mn = mn;
                ans = {v[i][3], v[i+1][3]};
            }
        }
    }
    if (ans.second == 0) {
        cout << 1 << '\n';
        cout << ans.first;
    } else {
        cout << 2 << '\n';
        cout << ans.first << ' ' << ans.second;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
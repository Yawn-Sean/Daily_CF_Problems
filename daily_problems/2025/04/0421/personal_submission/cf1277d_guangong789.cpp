#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 * 32 + 10;
const int MOD = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<string, int>>> vvp(4);
    string s;
    set<string> vis;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vis.insert(s);
        int len = s.length();
        int l = s[0] - '0', r = s[len - 1] - '0';
        int ns = 2 * l + r;
        vvp[ns].emplace_back(s, i + 1);
    }
    int a = vvp[0].size(), b = vvp[1].size(), c = vvp[2].size(), d = vvp[3].size();
    if (b == 0 && c == 0) {
        if (a == 0 || d == 0) cout << "0\n";
        else cout << "-1\n";
        return;
    }
    vector<int> ans;
    if (b > c) {
        int idx = 0;
        while (abs(b - c) > 1) {
            if (idx >= vvp[1].size()) {
                cout << "-1\n";
                return;
            }
            string str = vvp[1][idx].first;
            reverse(str.begin(), str.end());
            if (!vis.count(str)) {
                ans.emplace_back(vvp[1][idx].second);
                --b, ++c;
            }
            ++idx;
        }
    } else {
        int idx = 0;
        while (abs(b - c) > 1) {
            if (idx >= vvp[2].size()) {
                cout << "-1\n";
                return;
            }
            string str = vvp[2][idx].first;
            reverse(str.begin(), str.end());
            if (!vis.count(str)) {
                ans.emplace_back(vvp[2][idx].second);
                ++b, --c;
            }
            ++idx;
        }
    }
    cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
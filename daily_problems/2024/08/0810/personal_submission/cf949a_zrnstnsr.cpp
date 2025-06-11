#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    queue<int> q0, q1;
    char c;
    vector<vector<int>> ans;
    int i = 0;
    while (cin >> c && c != '\n') {
        if (c == '1') {
            if (q0.empty()) {
                q1.push(inf);
                break;
            } else {
                auto j = q0.front(); q0.pop();
                ans[j].push_back(i);
                q1.push(j);
            }
        } else {
            if (q1.empty()) {
                q0.push(ans.size());
                ans.push_back(vector<int>{i});
            } else {
                auto j = q1.front(); q1.pop();
                ans[j].push_back(i);
                q0.push(j);
            }
        }
        ++i;
    }
    if (q1.empty()) {
        cout << ans.size() << '\n';
        for (auto &v: ans) {
            cout << v.size();
            for (auto &x: v) cout << " " << x + 1;
            cout << '\n';
        }
    } else cout << "-1\n";
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

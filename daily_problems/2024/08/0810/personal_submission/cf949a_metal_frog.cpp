#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    queue<int> lack0, lack1;
    vector<vector<int>> ans;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '0') {
            if (!lack0.empty()) {
                int idx = lack0.front(); 
                lack0.pop();
                ans[idx].push_back(i + 1);
                lack1.push(idx);
            } else {
                ans.emplace_back();
                ans[sz(ans) - 1].push_back(i + 1);
                lack1.push(sz(ans) - 1);
            }
        } else {
            if (lack1.empty()) {
                cout << "-1\n";
                return;
            }
            int idx = lack1.front();
            lack1.pop();
            ans[idx].push_back(i + 1);
            lack0.push(idx);
        }
    }
    if (!lack0.empty()) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < sz(ans); i++) {
        cout << sz(ans[i]) << " ";
        for (int x : ans[i]) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}


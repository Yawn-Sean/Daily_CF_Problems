#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string s;
    cin >> s;
    int n = static_cast<int>(s.size());
    vector<vector<int>> pre(n + 1);
    pre[0] = vector<int>(26, 0);
    for (int i = 0; i < n; ++i) {
        pre[i+1] = pre[i];
        ++pre[i+1][s[i] - 'a'];
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (s[l-1] == s[r-1]) {
            int cnt = 0;
            for (int j = 0; j < 26; ++j) cnt += min(pre[r][j] - pre[l-1][j], 1);
            if (cnt <= 2 && r > l) cout << "No\n";
            else cout << "Yes\n";
        } else cout << "Yes\n";
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

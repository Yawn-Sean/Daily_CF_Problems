#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> st;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        st.insert({u, v});
    }
    if (st.size() == 1LL * n * (n - 1) / 2) cout << "NO\n";
    else {
        vector<int> ans(n+1);
        iota(ans.begin(), ans.end(), 0);
        for (int i = 1; i < n; ++i) for (int j = i + 1; j <= n; ++j) if (!st.count({i, j})) {
            if (i != 2) { swap(ans[1], ans[i]); swap(ans[2], ans[j]); }
            else { swap(ans[1], ans[i]); swap(ans[1], ans[j]); }
            cout << "YES\n";
            for (int k = 1; k <= n; ++k) cout << ans[k] << " \n"[k == n];
            ans[j] = 1;
            for (int k = 1; k <= n; ++k) cout << ans[k] << " \n"[k == n];
            goto end;
        }
    }
    end:;
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

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> wt(n-1, 0);
    vector<long long> cnt(n-1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        wt[i] = w;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    auto dfs = [&](auto &&self, int u, int p) -> int {
        int sz = 1;
        for (auto &&[v, i] : g[u]) {
            if (v == p) continue;
            int c = self(self, v, u);
            cnt[i] = 1LL*c*(c-1)*(n-c) + 1LL*(n-c)*(n-c-1)*c;
            sz += c;
        }
        return sz;
    };
    dfs(dfs, 0, -1);
    long double ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += 1.0*wt[i]*cnt[i]/n/(n-1)/(n-2)*6;
    }
    int q;
    cin >> q;
    while (q--) {
        int i, w;
        cin >> i >> w;
        i--;
        ans -= 1.0*wt[i]*cnt[i]/n/(n-1)/(n-2)*6;
        wt[i] = w;
        ans += 1.0*wt[i]*cnt[i]/n/(n-1)/(n-2)*6;
        cout << fixed << setprecision(10) << ans << '\n';
    }
    
    return 0;
}

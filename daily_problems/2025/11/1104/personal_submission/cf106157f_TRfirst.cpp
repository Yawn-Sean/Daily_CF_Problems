#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> high(n + 5);
    for (int i = 1; i <= n; i++) cin >> high[i];
    vector<pair<int, int>> edge(m + 5);
    for (int i = 1; i <= m; i++) cin >> edge[i].first >> edge[i].second;
    sort(edge.begin() + 1, edge.begin() + 1 + m, [&](pair<int, int> a, pair<int, int> b) {
        return max(high[a.first], high[a.second]) < max(high[b.first], high[b.second]);
    });
    vector<int> fa(n + 5);
    auto find = [&](auto find, int u) -> int {
        if (fa[u] == u) return u;
        return fa[u] = find(find, fa[u]);
    };
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) fa[j] = j;
        int mx = 0;
        for (int j = 1; j <= m; j++) {
            int u = edge[j].first, v = edge[j].second;
            if (min(high[u], high[v]) < high[i]) continue;
            fa[find(find, u)] = find(find, v);
            mx = max(mx, max(high[u], high[v]));
            if (find(find, 1) == find(find, 2)) {
                ans = min(ans, mx - high[i]);
                break;
            }
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
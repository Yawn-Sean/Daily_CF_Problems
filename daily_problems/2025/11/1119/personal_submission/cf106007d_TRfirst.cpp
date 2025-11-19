#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    vector<string> mp(n + 5);
    for (int i = 1; i <= n; i++) cin >> mp[i], mp[i] = "!" + mp[i];
    vector<pair<int, int>> ans;
    vector<int> vis(n + 5);
    auto dfs = [&](auto dfs, int u) -> void {
        vis[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (mp[u][i] != '0' && !vis[i]) {
                ans.push_back({u, i});
                dfs(dfs, i);
            }
        }
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) if (!vis[i]) {cout << "No" << endl; return;}
    cout << "Yes" << endl;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i].first << " " << ans[i].second << endl;
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



void solve(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 5);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<char> s(n + 5);
    vector<map<char, int>> check(n + 5);
    auto dfs = [&](auto dfs, int u) -> void {
        char c;
        for (int i = 0; i < 3; i++) {
            if (!check[u][char('a' + i)]) {
                s[u] = char('a' + i);
                c = char('a' + i);
                break;
            }
        }
        for (auto v : mp[u]) {
            if (s[v]) continue;
            check[v][c] = 1;
            if (check[v].size() == 2) {
                dfs(dfs, v);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!s[i]) dfs(dfs, i);
    }
    for (int i = 1; i <= n; i++) cout << s[i];
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}

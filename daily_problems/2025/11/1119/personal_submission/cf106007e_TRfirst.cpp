#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "!" + s;
    vector<vector<int>> mp(n + 5);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vector<int> query(q + 5);
    for (int i = 1; i <= q; i++) cin >> query[i];
    int root = query[1];
    s[root] = '0';
    vector<int> fa(n + 5);
    
    auto dfs = [&](auto dfs, int u, int f) -> void {
        fa[u] = f;
        for (auto v : mp[u]) {
            if (v != f) dfs(dfs, v, u);
        }
    };
    dfs(dfs, root, root);

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) if (s[i] == '1') cnt1++;
    
    auto find = [&](auto find, int u) -> void {
        if (s[u] != '1') return;
        s[u] = '2';
        cnt2++, cnt1--;
        find(find, fa[u]);
    };

    for (int i = 1; i <= n; i++) if (s[i] == '0') find(find, fa[i]);
    cout << cnt1 * (cnt1 + 1) / 2 + cnt1 * cnt2 << endl;
    for (int i = 2; i <= q; i++) {
        if (s[query[i]] == '1') cnt1--;
        if (s[query[i]] == '2') cnt2--;
        s[query[i]] = '0';
        find(find, fa[query[i]]);
        cout << cnt1 * (cnt1 + 1) / 2 + cnt1 * cnt2 << endl;
    }
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
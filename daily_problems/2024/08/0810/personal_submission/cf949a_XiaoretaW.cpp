int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    int n = sz(s);
    array<set<int>, 2> pos;
    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].insert(i);
    }
    vector<int> vis(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (sz(pos[1]) == 0) break;
        if (s[i] == '1') {
            cout << -1 << '\n';
            return 0;
        }
        vis[i] = 1; pos[0].erase(i);
        vector<int> cur; cur.emplace_back(i);
        int p = i, s = 0;
        while (true) {
            s ^= 1;
            auto it = pos[s].upper_bound(p);
            if (it == pos[s].end()) {
                if (s == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                break;
            }
            p = *it; vis[p] = 1;
            pos[s].erase(it);
            cur.emplace_back(p);
        }
        ans.emplace_back(cur);
    }

    if (sz(pos[1])) {
        cout << -1 << '\n';
        return 0;
    }

    while (sz(pos[0])) {
        ans.push_back({*(pos[0].begin())});
        pos[0].erase(pos[0].begin());
    }

    cout << sz(ans) << '\n';
    for (auto cur : ans) {
        cout << sz(cur) << ' ';
        for (int p : cur) cout << p + 1 << ' ';
        cout << '\n';
    }

    return 0;
}

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> ans;
    vector<vector<int>> st(2, vector<int>());
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (st[1].empty()) {
                ans.push_back({i + 1});
                st[0].emplace_back(cnt);
                cnt++;
            } else {
                int id = st[1].back();
                st[1].pop_back();
                ans[id].push_back(i + 1);
                st[0].push_back(id);
            }
        } else {
            if (st[0].empty()) {
                cout << -1 << endl;
                return;
            } else {
                int id = st[0].back();
                st[0].pop_back();
                ans[id].push_back(i + 1);
                st[1].push_back(id);                
            }
        }
    }
    if (!st[1].empty()) {
        cout << -1 << endl;
        return;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i].size() << " ";
        for (int x : ans[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
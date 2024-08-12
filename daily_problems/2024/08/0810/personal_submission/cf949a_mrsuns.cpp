void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    vector<int> nxt(n + 1);
    vector a(2, vector<int>(0));vector<int> vis(n + 1);
    for (int i = 1;i <= n;i++) {
        if (s[i] == '0') {
            if (a[1].size()) {
                nxt[a[1].back()] = i;
                a[1].pop_back();
                a[0].push_back(i);
            }
            else {
                a[0].push_back(i);
            }
        }
        else {
            if (a[0].size()) {
                nxt[a[0].back()] = i;
                a[0].pop_back();
                a[1].push_back(i);
            }
            else {
                cout << "-1\n";
                return;
            }
        }
    }
    if (a[1].size()) return cout << "-1\n", void();
    vector<vector<int>> res;
    for (int i = 1;i <= n;i++) {
        if (vis[i]);
        else {
            vector<int> vec;
            for (int j = i;j;j = nxt[j]) {
                vis[j] = 1;
                vec.push_back(j);
            }
            res.push_back(vec);
        }
    }
    cout << res.size() << endl;
    for (auto i : res) {
        cout << i.size() << ' ';
        for (auto j : i) cout << j << ' ';
        cout << endl;
    }
}

void Solve() {
    int n;cin >> n;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1];
    vector<vector<int>> pos(n + 1);
    for (int i = 1;i <= n;i++) {
        pos[a[i][0]].push_back(i);
    }
    vector<int> vis(n + 1), p(1);
    for (int i = n;i >= 1;i--) {
        if (!vis[a[i][0]]) {
            vis[a[i][0]] = 1;
            p.push_back(a[i][0]);
        }
    }
    
    int q;cin >> q;
    while (q--) {
        int m;cin >> m;
        set<int> st;
        for (int i = 1;i <= m;i++) {
            int x;cin >> x;st.insert(x);
        }
        int i;
        for (i = 1;i < p.size();i++) {
            if (!st.count(p[i])) break;
        }
        if (i == p.size()) cout << "0 0" << endl;
        else {
            int j;
            for (j = i + 1;j < p.size();j++) {
                if (!st.count(p[j])) break;
            }
            if (j == p.size()) {
                cout << p[i] << " " << a[pos[p[i]].front()][1] << endl;
            }
            else {
                int lst = pos[p[j]].back();
                auto ptr = upper_bound(pos[p[i]].begin(), pos[p[i]].end(), lst);
                cout << p[i] << " " << a[*ptr][1] << endl;
            }
        }
    }
}

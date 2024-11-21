int n, m;
vector<vector<int>> e(N);
vector<vector<PII>> pos(N);

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        e[u].push_back(v);
    }
    int cur_x = 1, cur_y = 1;
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
        if (e[i].size() == 0) {
            if (pos[i].size() == 0) {
                PII cur = {cur_x, cur_y};
                pos[i].push_back(cur);
                cur_x++;
                cur_y++;
            } else {
                PII last = pos[i].back();
                PII cur = {cur_x, cur_y};
                cur_x++;
                cur_y++;
                pos[i].push_back({last.x, cur.y});
                pos[i].push_back(cur);
            }
            continue;
        }
        PII cur = {cur_x, cur_y};
        if (pos[i].size() != 0) {
            PII last = pos[i].back();
            pos[i].push_back({last.x, cur.y});
        }
        for (int j = 0; j < e[i].size(); j++) {
            int v = e[i][j];
            pos[i].push_back({cur_x, cur_y});
            if (pos[v].size() == 0) {
                pos[v].push_back({cur_x + j + 1, cur_y});
            } else {
                PII last = pos[v].back();
                cur = {cur_x + j + 1, cur_y};
                pos[v].push_back({last.x, cur.y});
                pos[v].push_back(cur);
            }
            cur_y++;
        }
        cur_x += e[i].size() + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << pos[i].size() << "\n";
        for (auto p : pos[i]) {
            cout << p.x << " " << p.y << "\n";
        }
    }
}

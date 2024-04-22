// link : https://codeforces.com/contest/623/submission/256891136


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    vector<char> color(n + 1, '0');
    for (int i = 1; i <= n; i++) {
        mp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (!mp[i][j]) flag = false;
        }
        if (flag) color[i] = 'b';
    }
    auto same = [&](int x, int y) {

    };
    bool flag = true;
    auto dfs = [&](auto self, int x) {
        for (int i = 1; i <= n; i++) {
            if (!mp[x][i]) {
                if (color[x] == color[i]) {
                    flag = false;
                    return;
                }
                if (color[i] == '0') {
                    color[i] = 2 - color[x] + 'a' * 2;

                    self(self, i);
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (color[i] == '0') {
            color[i] = 'a';
            dfs(dfs, i);
        }
    }
    debug(color);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[i] == color[j] && (!mp[i][j]))flag = false;
            if (color[i] == 'a' && color[j] == 'c' && mp[i][j])flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            cout << color[i];
        }
    } else {
        cout << "No" << endl;
    }

}

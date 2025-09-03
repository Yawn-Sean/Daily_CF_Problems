/*
从某个值为 1 的点开始走，经过若干 0 和 2，最后停在一个值为 2 的点上，则这些点被称为被访问过
图是一个有向图

什么样的点不会被访问到？
- 0：前面没 1 或者后边遇到下一个 1 之前没有 2
- 1：后边遇到下一个 1 之前没有 2
- 2：前面没 1

起点和终点比较确定，考虑直接从起点和终点开始搜，都能走到的点就是对的
*/

int n, m, f[N], vis1[N], vis2[N];
vector<vector<int>> e(N);
vector<vector<int>> rev_e(N);

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        rev_e[v].push_back(u);
    }

    auto dfs1 = [&] (auto &self, int u) -> void {
        vis1[u] = 1;
        for (auto v : e[u]) {
            if (f[v] != 1 && !vis1[v]) {
                self(self, v);
            }
        }
    };

    auto dfs2 = [&] (auto &self, int u) -> void {
        vis2[u] = 1;
        if (f[u] == 1) {
            return;
        }
        for (auto v : rev_e[u]) {
            if (!vis2[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (f[i] == 1) {
            dfs1(dfs1, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] == 2 && !vis2[i]) {
            dfs2(dfs2, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis1[i] && vis2[i]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}

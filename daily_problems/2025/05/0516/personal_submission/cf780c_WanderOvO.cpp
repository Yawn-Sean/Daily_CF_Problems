/*
考虑 DFS 的时候顺便做了这个事情
假设某个点 u 和一系列 v1...vk 相连，则这些点的颜色都不能一样
*/

vector<vector<int>> e(N);
int n, c[N], cnt = 0;

void dfs(int u, int fa) {
    set<int> colors;
    int used_color = 1;
    if (c[u] != 0) {
        colors.insert(c[u]);
    }
    for (auto v : e[u]) {
        if (c[v] != 0) {
            colors.insert(c[v]);
        }
    }

    if (c[u] == 0) {
        while (colors.count(used_color)) {
            used_color++;
        }
        c[u] = used_color;
        cnt = max(cnt, used_color);
        used_color++;
    }

    for (auto v : e[u]) {
        if (c[v] == 0) {
            while (colors.count(used_color)) {
                used_color++;
            }
            c[v] = used_color;
            cnt = max(cnt, used_color);
            used_color++;
        }
    }

    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
}  

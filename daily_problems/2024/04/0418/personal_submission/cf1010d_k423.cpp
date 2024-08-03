// https://codeforces.com/contest/1010/submission/257113573

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> type(n), val(n), tag(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        string op;
        cin >> op >> x;
        type[i] = op[0];
        if (op[0] == 'I') {
            val[i] = x;
        } else if (op[0] == 'N') {
            g[i].emplace_back(x - 1);
        } else {
            cin >> y;
            x--, y--;
            g[i].emplace_back(x);
            g[i].emplace_back(y);
        }
    }
    vector<int> order(1);
    for (int i = 0; i < n; ++i) {
        for (int v: g[order[i]]) {
            order.emplace_back(v);
        }
    }
    for (int u: order | views::reverse) {
        if (type[u] == 'N') val[u] = val[g[u][0]] ^ 1;
        else if (type[u] == 'A') val[u] = val[g[u][0]] & val[g[u][1]];
        else if (type[u] == 'X') val[u] = val[g[u][0]] ^ val[g[u][1]];
        else if (type[u] == 'O') val[u] = val[g[u][0]] | val[g[u][1]];
    }
    tag[0] = 1;
    for (int u: order) {
        if (!tag[u] || type[u] == 'I') continue;
        if (type[u] == 'N' || type[u] == 'X') for (int v: g[u]) tag[v] = 1;
        else if (type[u] == 'A') {
            int l = g[u][0], r = g[u][1];
            tag[l] = ((val[l] ^ 1) & val[r]) != val[u];
            tag[r] = (val[l] & (val[r] ^ 1)) != val[u];
        } else {
            int l = g[u][0], r = g[u][1];
            tag[l] = ((val[l] ^ 1) | val[r]) != val[u];
            tag[r] = (val[l] | (val[r] ^ 1)) != val[u];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (type[i] == 'I') cout << (val[0] ^ tag[i]);
    }
    cout << endl;
}

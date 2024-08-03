void Solve() {
 
    int n, m;cin >> n >> m;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    basic_string<array<int, 2>> v;
    for (int i = 1;i <= m;i++) {
        int op;cin >> op;op--;
        int pos;cin >> pos;
        while (v.size() && v.back().at(0) <= pos) v.pop_back();
        if (v.size() == 0 || v.back().at(1) != op) v += { pos, op };
    }
    v += array<int, 2> { 0, v.back().at(1) ^ 1 };
    sort(a.begin() + 1, a.begin() + v[0][0] + 1);
    if (v[0][1] == 1) reverse(a.begin() + 1, a.begin() + v[0][0] + 1);
    vector<int> res(n + 1);for (int i = v[0][0] + 1;i <= n;i++) res[i] = a[i];
    auto dfs = [&](auto&& dfs, int ptr, int l, int r, int c) {
        if (ptr >= v.size()) return;
        if (c == -1) {
            int nr = r;
            for (int i = v[ptr - 1][0];i > v[ptr][0];i--) res[i] = a[nr--];
            dfs(dfs, ptr + 1, l, nr, -c);
        }
        else if (c == 1) {
            int nl = l;
            for (int i = v[ptr - 1][0];i > v[ptr][0];i--) res[i] = a[nl++];
            dfs(dfs, ptr + 1, nl, r, -c);
        }
        };
    dfs(dfs, 1, 1, v[0][0], -1);
    for (int i = 1;i <= n;i++) cout << res[i] << " \n"[i == n];
 
}

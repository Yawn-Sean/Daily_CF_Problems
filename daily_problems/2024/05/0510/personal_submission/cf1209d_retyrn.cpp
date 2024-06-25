int n, m;

void solve() {
    cin >> n >> m;
    DSU dsu(n);
    multiset<int> S;
    for (int i = 0; i < n; i ++) {
        S.insert(1);
    }
    // 记录连通块的大小
    for (int i = 1, cnt = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (!dsu.same(x, y)) {
            S.erase(S.find(dsu.size(x)));
            S.erase(S.find(dsu.size(y)));
            dsu.merge(x, y);
            S.insert(dsu.size(x));
        }
        else {
            cnt ++;
        }
        // 最大的cnt个 - 1
        int cur = 0;
        auto it = S.rbegin();
        int res = 0;
        while (cur < cnt and it != S.rend()) {
            res += *it;
            it ++;
            cur ++;
        }
        cout << res - 1 << endl;
    }
}
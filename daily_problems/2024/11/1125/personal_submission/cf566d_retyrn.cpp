int n, q;

void solve() {
    cin >> n >> q;
    vector<int> next(n); // 后面第一个和自己不是一个联通块的点
    DSU dsu(n);
    iota(all(next), 1);
    
    while (q --) {
        int op, x, y;
        cin >> op >> x >> y;
        x --, y --;
        if (x > y) swap(x, y);
        
        if (op == 1) {
            dsu.merge(x, y);
        }
        else if (op == 2) {
            int cur = x + 1;
            while (cur <= y) {
                dsu.merge(cur - 1, cur);
                auto to = next[cur];
                next[cur] = next[y];
                cur = to;
            }
        }
        else {
            cout << (dsu.same(x, y) ? "YES" : "NO") << endl;
        }
    }
}
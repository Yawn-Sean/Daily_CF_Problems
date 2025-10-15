int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] -= 1;
        pos[a[i]] = i;
    }
    
    // 维护下降段 横坐标是值域
    Fenwick<int> fen(n + 1);
    
    auto change = [&](int x, int y, int flag) -> void {
        if (x > y) swap(x, y);
        if (x + 1 == y) {
            // x-1 x y
            if (x - 1 >= 0) {
                fen.add(x - 1, flag * (pos[x - 1] > pos[x]));
            }
            fen.add(x, flag * (pos[x] > pos[y]));
            if (y + 1 < n) {
                fen.add(y, flag * (pos[y] > pos[y + 1]));
            }
        }
        else {
            // x-1 x  y-1 y
            if (x - 1 >= 0) {
                fen.add(x - 1, flag * (pos[x - 1] > pos[x]));
            }
            fen.add(x, flag * (pos[x] > pos[x + 1]));
            fen.add(y - 1, flag * (pos[y - 1] > pos[y]));
            if (y + 1 < n) {
                fen.add(y, flag * (pos[y] > pos[y + 1]));
            }
        }
    };
    
    for (int i = 0; i + 1 < n; i ++) {
        fen.add(i, (pos[i] > pos[i + 1]));
    }
    
    cin >> m;
    while (m --) {
        int op, x, y;
        cin >> op >> x >> y;
        x --, y --;
        if (op == 1) {
            if (x > y) swap(x, y);
            auto ans = fen.rangeSum(x, y) + 1;
            cout << ans << endl;
        }
        else {
            if (x > y) swap(x, y);
            int vx = a[x], vy = a[y];
            change(vx, vy, -1);
            swap(a[x], a[y]);
            pos[a[x]] = x;
            pos[a[y]] = y;
            change(vx, vy, 1);
        }
    }
}
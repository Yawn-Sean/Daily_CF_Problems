int n, m;

void solve() {
    cin >> n >> m;
    vector<int> row(n), col(n);
    cin >> row >> col;
    // 把很坐标奇偶相同的连起来
    DSU d_col(n), d_row(n);
    for (int i = 1; i < n; i ++) {
        if ((row[i-1] & 1) == (row[i] & 1)) d_row.merge(i - 1, i);
        if ((col[i-1] & 1) == (col[i] & 1)) d_col.merge(i - 1, i);
    }
    while (m --) {
        pii p1, p2;
        cin >> p1 >> p2;
        p1.fi --, p1.se --;
        p2.fi --, p2.se --;
        if (d_col.same(p1.se, p2.se) and d_row.same(p1.fi, p2.fi)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
// https://codeforces.com/contest/1016/submission/254367155

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    vector<int> row(n), col(m);
    for (int &x: row) cin >> x;
    for (int &x: col) cin >> x;
    int vr = accumulate(itr(row), 0, std::bit_xor<>{});
    int vc = accumulate(itr(col), 0, std::bit_xor<>{});
    if (vr != vc) {
        return NO();
    }
    YES();
    cout << (vr ^ col[0] ^ row[0]) << ' ';
    for (int j = 1; j < m; ++j) {
        cout << col[j] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; ++i) {
        cout << row[i] << ' ';
        for (int j = 1; j < m; ++j) {
            cout << 0 << " ";
        }
        cout << endl;
    }
}

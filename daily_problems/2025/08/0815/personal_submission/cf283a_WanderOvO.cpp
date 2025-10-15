/*
毛毛虫火箭
*/

SegmentTree tr;
LL n;

void meibao() {
    cin >> n;
    tr.init(n + 1);
    LL cur_len = 1;
    for (int i = 1; i <= n; i++) {
        LL t, a, x, k;
        cin >> t;
        if (t == 1) {
            cin >> a >> x;
            tr.add(1, n + 1, 1, min(a, cur_len), 1, x);
        } else if (t == 2) {
            cin >> k;
            cur_len++;
            LL val = tr.query(1, n + 1, cur_len, cur_len, 1);
            tr.add(1, n + 1, cur_len, cur_len, 1, -val + k);
        } else {
            LL val = tr.query(1, n + 1, cur_len, cur_len, 1);
            tr.add(1, n + 1, cur_len, cur_len, 1, -val);
            cur_len--;
        }
        LL s = tr.query(1, n + 1, 1, cur_len, 1);
        cout << setprecision(15) << (1.0 * s) / cur_len << "\n";
    }
}

/*
|q| >= 2 时，至多输出 64 个数
我们直接暴力循环，如果能输出超过 64 个数，说明输出 INF 个数
*/

LL b1, q, l, m;

void meibao() {
    cin >> b1 >> q >> l >> m;
    set<LL> a;
    for (int i = 1; i <= m; i++) {
        LL val;
        cin >> val;
        a.insert(val);
    }
    int res = 0;
    for (int i = 1; i <= 200; i++) {
        LL abs_b = b1 > 0 ? b1 : -b1;
        if (abs_b > l) {
            break;
        }
        if (!a.count(b1)) {
            res++;
        }
        b1 *= q;
        // cout << b1 << "\n";
    }
    if (res >= 64) {
        cout << "inf\n";
    } else {
        cout << res << "\n";
    }
}

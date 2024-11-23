void Solve() {
    int l, r;cin >> l >> r;
    int res = 0;
    auto calc = [&](int lim) {
        if (lim == 0) return 0LL;
        int sz = __lg(lim) + 1;
        vector<int> res(sz + 1);
        for (int i = 1;i < sz;i++) {
            for (int d = 1;d < i;d++) {
                if (i % d == 0) {
                    res[i / d] += 1LL << (d - 1);
                }
            }
        }
        for (int d = 1;d < sz;d++) {
            if (sz % d == 0) {
                int base = 0;
                for (int j = 0;j < sz;j += d) base ^= 1LL << j;
                res[sz / d] += min(max(0LL, lim / base - (1LL << d - 1) + 1), (1LL << d) - 1);
            }
        }
        int ret = 0;
        for (int i = sz;i >= 2;i--) {
            for (int j = i * 2;j <= sz;j += i) {
                res[i] -= res[j];
            }
            ret += res[i];
        }
        return ret;
        };
    cout << calc(r) - calc(l - 1) << endl;
}

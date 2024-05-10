// https://codeforces.com/contest/1609/submission/260203497

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    multiset<int> S;
    int ext = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (dsu[x] != dsu[y]) {
            if (dsu.size(x)) S.extract(dsu.size(x));
            if (dsu.size(y)) S.extract(dsu.size(y));
            dsu.join(x, y);
            S.insert(dsu.size(x));
        } else {
            ext++;
        }
        int k = ext;
        auto it = S.rbegin();
        int ans = 0;
        while (k >= 0 && it != S.rend()) {
            ans += *it + 1;
            it++, k--;
        }
        cout << ans + k << endl;
    }
}

// https://codeforces.com/contest/1132/submission/262094732

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, q;
    cin >> n >> q;
    vector<int> f(n + 1), f1(n + 1), f2(n + 1);
    vector<pii> a(q);
    for (auto &[l, r]: a) {
        cin >> l >> r, l--, r--;
        f[l]++, f[r + 1]--;
    }
    ranges::sort(a);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        f1[i] += f[i] == 1;
        f2[i] += f[i] == 2;
        f[i + 1] += f[i];
        f1[i + 1] += f1[i];
        f2[i + 1] += f2[i];
        tot += f[i] > 0;
    }
 
    auto range_sum = [&](vector<int> &f, int l, int r) {
        return l <= r ? f[r] - (l ? f[l - 1] : 0) : 0;
    };
 
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        auto [l1, r1] = a[i];
        for (int j = i + 1; j < q; ++j) {
            auto [l2, r2] = a[j];
            if (r1 < l2) {
                chmax(ans, tot - range_sum(f1, l1, r1) - range_sum(f1, l2, r2));
            } else {
                chmax(ans, tot - range_sum(f1, l1, max(r1, r2)) - range_sum(f2, max(l1, l2), min(r1, r2)));
            }
        }
    }
    cout << ans << endl;
}

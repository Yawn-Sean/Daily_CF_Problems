// https://codeforces.com/contest/558/submission/256857180

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m = 20;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x, m = min(m, __lg(x));
    vector<int> b = a;
    for (int &x: b) x >>= __lg(x) - m;
    int or_val = accumulate(itr(b), 0, bit_or<>{});
    int mask = accumulate(itr(b), or_val, bit_and<>{});
    while (mask != or_val) m--, mask >>= 1, or_val >>= 1;
    vector<int> cnt(20);
    int ext = 0, cur = 0;
    for (int x: a) {
        int t = mask << (__lg(x) - m);
        if (t != x) {
            int k = __lg(t ^ x) + 1;
            ext += k;
            x >>= k;
        }
        cnt[__lg(x)]++;
        cur += __lg(x);
    }
    int tot = 0, ans = cur;
    for (int i = 0; i < 20; ++i) {
        tot += cnt[i];
        cur += tot - (n - tot);
        ans = min(ans, cur);
    }
    cout << ans + ext << endl;
}

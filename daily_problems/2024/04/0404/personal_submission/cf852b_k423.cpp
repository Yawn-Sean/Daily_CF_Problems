// https://codeforces.com/contest/852/submission/254986783

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k), b(k), tmp(n), c(k);
    for (int i = 0, x; i < n; ++i) cin >> x, a[x % k]++;
    for (int i = 0; i < n; ++i) cin >> tmp[i], b[tmp[i] % k]++;
    for (int i = 0, x; i < n; ++i) cin >> x, c[(tmp[i] + x) % k]++;

    matrix m1(k, vector<Mint>(k)), m2 = m1, m3 = m1;
    auto init = [&](matrix &mat, vector<int> &a) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                mat[i][(i + j) % k] += a[j];
            }
        }
    };
    init(m1, a), init(m2, b), init(m3, c);
    matrix ans(1, vector<Mint>(k));
    ans[0][0] = 1;
    ans = ans * m1;
    m -= 2;
    while (m) {
        if (m & 1) ans = ans * m2;
        m2 = m2 * m2;
        m >>= 1;
    }
    ans = ans * m3;
    cout << ans[0][0] << endl;
}

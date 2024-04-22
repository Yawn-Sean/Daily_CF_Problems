// https://codeforces.com/contest/1148/submission/254649394


/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    using pii = pair<int, int>;

    int n;
    cin >> n;
    vector<pii> p(n);
    vector<int> inc, dec;
    for (int i = 0; i < n; ++i) {
        auto &[x, y] = p[i];
        cin >> x >> y;
        (x < y ? inc : dec).emplace_back(i);
    }
    if (inc.size() >= dec.size()) {
        ranges::sort(inc, [&](int i, int j) {return p[i] > p[j]; });
        cout << inc.size() << endl;
        for (int x: inc) cout << x + 1 << " \n"[x == inc.back()];
    } else {
        ranges::sort(dec, [&](int i, int j) {return p[i] < p[j]; });
        cout << dec.size() << endl;
        for (int x: dec) cout << x + 1 << " \n"[x == dec.back()];
    }
}

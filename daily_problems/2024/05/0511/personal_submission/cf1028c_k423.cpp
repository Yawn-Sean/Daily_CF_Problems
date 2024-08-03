// https://codeforces.com/contest/1028/submission/260525098

/* 我永远喜欢爱莉希雅♪ */
struct rect {
    int l, b, r, t;

    rect() : l(-inf), b(-inf), r(inf), t(inf) {}

    rect &operator+=(const rect &o) {
        chmax(l, o.l), chmin(r, o.r);
        chmax(b, o.b), chmin(t, o.t);
        return *this;
    }

    bool test() {
        return l <= r && b <= t;
    }
};

rect operator+(const rect &a, const rect &b) { return rect(a) += b; }

void elysia() {
    int n;
    cin >> n;
    vector<rect> a(n), f(n + 1);
    for (auto &[l, b, r, t]: a) cin >> l >> b >> r >> t;
    for (int i = n - 1; i >= 0; --i) {
        f[i] = a[i] + f[i + 1];
    }
    rect p;
    for (int i = 0; i < n; ++i) {
        rect t = p + f[i + 1];
        if (t.test()) {
            cout << t.l << ' ' << t.b << endl;
            return;
        }
        p += a[i];
    }
}



inline int read() {
    int x;
    cin >> x;
    return x;
}

struct nod {
    int type;
    i64 st, ed;
    int x;
    int l; 
};

void solve() {
    vector<nod> a;
    vector<i64> b;
    int m = read();
    i64 pre = 0;
    rep(i, 0, m) {
        int cur = read();
        if (cur == 1) {
            int x = read();
            i64 st = pre + 1, ed = st;
            a.emplace_back(1, st, ed, x, 0);
            pre = ed;
        } else {
            int l = read(), c = read();
            i64 range = (i64)l * c, st = pre + 1, ed = pre + range;
            a.emplace_back(2, st, ed, 0, l);
            pre = ed;
        }
        b.emplace_back(a.back().st);
    }
    int n = read();
    rep(i, 0, n) {
        i64 k;
        cin >> k;
        i64 cur = k;
        while (true) {
            auto it = upper_bound(all(b), cur);
            int idx = it - b.begin() - 1;
            if (idx < 0) {
                idx = 0;
            }
            nod& tmp = a[idx];
            if (tmp.type == 1) {
                cout << tmp.x << ' ';
                break;
            } else {
                i64 mut = cur - tmp.st;
                cur = mut % tmp.l + 1;
            }
        }
    }
    cout << '\n';
}


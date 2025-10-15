LL m, n;
vector<LL> a, ps, vals;

void meibao() {
    cin >> m;

    int maxlen = 1e5;

    ps.push_back(0);
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            LL x;
            cin >> x;
            if (a.size() < maxlen) {
                a.push_back(x);
            }
            vals.push_back(-x);
            ps.push_back(ps.back() + 1);
        } else {
            LL l, c;
            cin >> l >> c;
            for (int i = 0; i < l * c && a.size() < maxlen; i++) {
                a.push_back(a[i % l]);
            }
            vals.push_back(l);
            ps.push_back(ps.back() + l * c);
        }
    }

    cin >> n;
    while (n--) {
        LL pos;
        cin >> pos;
        
        int p = lower_bound(ps.begin(), ps.end(), pos) - ps.begin() - 1;
        if (vals[p] < 0) {
            cout << -vals[p] << " ";
        } else {
            cout << a[(pos - 1 - ps[p]) % vals[p]] << " ";
        }
    }
}

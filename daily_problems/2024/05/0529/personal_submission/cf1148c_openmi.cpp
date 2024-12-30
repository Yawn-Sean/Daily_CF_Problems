void solve() {
    int n, mid = 0;
    cin >> n;
    vi a(n + 1);
    vi iv(n + 1);
    mid = n / 2;
    vc<pair<int, int>> vp;
    auto sp = [&](int x, int y) {
        swap(a[x], a[y]); 
        vp.emplace_back(x, y);
        return;
    };
    auto op_from_to = [&](int x, int y) {
        if (x == y) return;
        int l = 1, r = n;
        if (x <= mid && y <= mid) {
            sp(x, r); sp(y, r); sp(x, r);
        } else if (x > mid && y <= mid) {
            if (x - y >= mid) {
                sp(x, y);
            } else {
                sp(x, l); sp(l, r); sp(r, y); sp(l, r); sp(x, l);
            }
        } else if (x >= mid) {
            sp(x, l); sp(y, l); sp(x, l);
        }
        iv[a[x]] = x;
        iv[a[y]] = y;
    };
    rb (i, 1, n) {
        cin >> a[i];
        iv[a[i]] = i;
    }
    rb (i, 1, n - 1) {
        op_from_to(iv[i], i);
    }
    cout << vp.size() << nl;;
    for (auto& [x, y]: vp) {
        cout << x << ' ' << y << nl;
    }
    // rb (i, 1, n) cout << a[i] << " "[i == n];
}

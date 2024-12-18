int n, l, x, y;

void solve() {
    cin >> n >> l >> x >> y;
    vector<int> a(n);
    cin >> a;
    
    // 最多只标记两处
    int st = 0;
    auto check = [&](int val, int t) -> pii {
        pii res = {-1, -1};
        for (int i = 0, j = 0; i < n; i ++) {
            while (j < n and a[j] - a[i] < val) j ++;
            if (j < n and a[j] - a[i] == val) {
                st |= t;
                if (res.fi == -1) res.fi = i;
                res.se = i;
            }
        }
        return res;
    };
    
    check(x, 1);
    check(y, 2);
    
    if (st == 3) {
        cout << 0 << endl;
        return;
    }
    
    if (st == 1) {
        cout << 1 << endl << y << endl;
        return;
    }
    if (st == 2) {
        cout << 1 << endl << x << endl;
        return;
    }
    
    // 找间隔为 x + y
    auto t = check(x + y, 1);
    if (t.fi >= 0) {
        cout << 1 << endl << a[t.fi] + x << endl;
        return;
    }
    
    // 找间隔为 y - x
    t = check(y - x, 1);
    if (t.fi >= 0) {
        if (a[t.se] - x >= 0) {
            cout << 1 << endl << a[t.se] - x << endl;
            return;
        }
        if (a[t.fi] + y <= l) {
            cout << 1 << endl << a[t.fi] + y << endl;
            return;
        }
    }
    
    cout << 2 << endl << x << ' ' << y << endl;
    
}
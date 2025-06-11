int b1, q, l, m;

void solve() {
    cin >> b1 >> q >> l >> m;
    set<int> S;
    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    
    if (abs(b1) > l) {
        cout << 0 << endl;
        return;
    }
    
    if (b1 == 0) {
        if (S.count(0)) {
            cout << 0 << endl;
        }
        else {
            cout << "inf" << endl;
        }
        return;
    }
    
    if (q == 1) {
        if (S.count(b1)) {
            cout << 0 << endl;
        }
        else {
            cout << "inf" << endl;
        }
        return;
    }
    
    if (q == -1) {
        if (S.count(b1) and S.count(-b1)) {
            cout << 0 << endl;
        }
        else {
            cout << "inf" << endl;
        }
        return;
    }
    
    if (q == 0) {
        int cnt = !S.count(b1);
        if (S.count(0)) {
            cout << cnt << endl;
        }
        else {
            cout << "inf" << endl;
        }
        return;
    }
    
    int cnt = 0;
    ll x = b1;
    while (abs(x) <= l) {
        cnt += !S.count(x);
        x *= q;
    }
    
    cout << cnt << endl;
}
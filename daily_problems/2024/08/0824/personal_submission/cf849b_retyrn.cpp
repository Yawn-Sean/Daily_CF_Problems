int n;

pii cal(pii x, pii y) {
    int dx = x.fi - y.fi;
    int dy = x.se - y.se;
    if (dx == 0 and dy != 0) dy = 1;
    else if (dy == 0 and dx != 0) dx = 1;
    else if (dx and dy) {
        auto t = __gcd(abs(dx), abs(dy));
        dx /= t, dy /= t;
    }
    if (dx < 0) dx = -dx, dy = -dy;
    return make_pair(dx, dy);
}
void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    for (int i = 1; i < n; i ++) {
        auto k = cal(mpr(0, a[0]), mpr(i, a[i]));
        // 直线1 (0, a[0]) (i, a[i])
        int u = -1;
        for (int j = 1; j < n; j ++) {
            auto k1 = cal(mpr(0, a[0]), mpr(j, a[j]));
            if (k != k1) {
                u = j;
                break;
            }
        }
        
        if (u == -1) continue;
        bool ok = true;
        for (int j = u + 1; j < n; j ++) {
            if (cal(mpr(0, a[0]), mpr(j, a[j])) != k and cal(mpr(u, a[u]), mpr(j, a[j])) != k) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
    }
    
    // 0 自己一条线
    for (int i = 2; i < n; i ++) {
        auto k = cal(mpr(1, a[1]), mpr(i, a[i]));
        // 直线1 (1, a[1]) (i, a[i])
        int u = -1;
        for (int j = 2; j < n; j ++) {
            auto k1 = cal(mpr(1, a[1]), mpr(j, a[j]));
            if (k != k1) {
                u = j;
                break;
            }
        }
        if (u == -1 and cal(mpr(1, a[1]), mpr(0, a[0])) != k) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
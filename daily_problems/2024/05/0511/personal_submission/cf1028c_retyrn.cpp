using ai4 = array<int, 4>;
int n;

void solve() {
    cin >> n;
    vector<pii> a(n), b(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i] >> b[i];
    }
    
    // 前后缀分解
    // {x_min, x_max, y_min, y_max}
    vector<ai4> l(n + 1), r(n + 1);
    l[0] = r[0] = {-inf, inf, -inf, inf};
    
    for (int i = 1; i <= n; i ++) {
        l[i] = l[i - 1];
        l[i][0] = max(l[i][0], a[i-1].fi);
        l[i][1] = min(l[i][1], b[i-1].fi);
        l[i][2] = max(l[i][2], a[i-1].se);
        l[i][3] = min(l[i][3], b[i-1].se);
        
        r[i] = r[i - 1];
        r[i][0] = max(r[i][0], a[n-i].fi);
        r[i][1] = min(r[i][1], b[n-i].fi);
        r[i][2] = max(r[i][2], a[n-i].se);
        r[i][3] = min(r[i][3], b[n-i].se);
    }
    
    for (int i = 0; i < n; i ++) {
        int x_min = max(l[i][0], r[n-i-1][0]);
        int x_max = min(l[i][1], r[n-i-1][1]);
        int y_min = max(l[i][2], r[n-i-1][2]);
        int y_max = min(l[i][3], r[n-i-1][3]);
        if (x_min <= x_max and y_min <= y_max) {
            cout << x_min << ' ' << y_min << endl;
            return;
        }
    }
}
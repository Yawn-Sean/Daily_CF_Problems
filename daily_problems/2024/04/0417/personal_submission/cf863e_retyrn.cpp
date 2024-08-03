int n;
using ai3 = array<int, 3>;

void solve() {
    cin >> n;
    vector<ai3> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    sort(all(a), [](ai3& x, ai3& y) {
        if (x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    });
    
    int r = -1;
    for (int i = 0; i < n; i ++) {
        if (r >= a[i][1]) {
            cout << a[i][2] << endl;
            return;
        }
        r = max(r, a[i][1]);
    }
    
    // 剩下的区间互不包含
    r = -1;
    for (int i = 0; i < n; i ++) {
        if (i + 1 < n and a[i + 1][0] <= r + 1) {
            cout << a[i][2] << endl;
            return;
        }
        r = max(r, a[i][1]);
    }
    cout << -1 << endl;
}
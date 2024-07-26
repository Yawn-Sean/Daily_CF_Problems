int n;

//-----------------------function-----------------------

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int t = a[0];
    for (auto x : a) {
        t = gcd(x, t);
        if (t == 1) break;
    }
    
    if (t > 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    
    for (auto& x : a) {
        x &= 1;
    }
    int res = 0;
    for (int i = 0; i < n; i ++) {
        while (a[i] & 1) {
            if (i + 1 < n) {
                int x = a[i], y = a[i + 1];
                a[i] = x + y, a[i + 1] = x - y;
            }
            else {
                int x = a[i - 1], y = a[i];
                a[i - 1] = x + y, a[i] = x - y;
            }
            res += 1;
        }
    }
    cout << "YES" << endl;
    cout << res << endl;
}
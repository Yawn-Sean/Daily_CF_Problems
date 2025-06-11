int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(n);
    cin >> a >> b;
    
    Z res = 0;
    Z cur = 1;
    
    for (int i = 0; i < n; i ++) {
        if (a[i] and b[i]) {
            if (a[i] != b[i]) {
                if (a[i] > b[i]) res += cur;
                break;
            }
            continue;
        }
        if (!a[i] and !b[i]) {
            res += cur * (m - 1) / 2 / m;
            cur /= m;
            continue;
        }
        if (!a[i]) {
            res += cur * (m - b[i]) / m;
            cur /= m;
        }
        else {
            res += cur * (a[i] - 1) / m;
            cur /= m;
        }
    }
    
    cout << res << endl;
}
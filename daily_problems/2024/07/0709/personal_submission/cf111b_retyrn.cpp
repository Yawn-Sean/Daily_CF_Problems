int n;

void solve() {
    cin >> n;
    vector<int> f(100010);
    
    for (int id = 1; id <= n; id ++) {
        int x, y;
        cin >> x >> y;
        int res = 0;
        for (int i = 1; i <= x / i; i ++) {
            if (x % i) continue;
            res += (f[i] < id - y);
            f[i] = id;
            
            if (i != x / i) {
                res += (f[x / i] < id - y);
                f[x / i] = id;
            }
        }
        cout << res << endl;
    }
}
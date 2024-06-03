int n, x;

void solve() {
    cin >> n >> x;
    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return;
    }
    if (n == 2) {
        if (x == 0) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << 0 << ' ' << x << endl;
        return;
    }
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < n - 3; i ++) {
        res.push_back(i);
        sum ^= i;
    }
    int u = (1 << 17);
    res.push_back(u);
    res.push_back(u << 1);
    res.push_back(sum ^ x ^ u ^ (u << 1));
    cout << "YES" << endl;
    cout << res << endl;
}
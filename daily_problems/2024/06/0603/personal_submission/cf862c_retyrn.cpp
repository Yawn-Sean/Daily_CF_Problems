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
    for (int i = 0; i < n - 2; i ++) {
        res.push_back(i);
        sum ^= i;
    }
    if (sum == x) {
        sum ^= n - 3;
        sum ^= n - 2;
        res.pop_back();
        res.push_back(n - 2);
    }
    
    res.push_back(1 << 18);
    res.push_back((1 << 18) ^ sum ^ x);
    
    cout << "YES" << endl;
    cout << res << endl;
}

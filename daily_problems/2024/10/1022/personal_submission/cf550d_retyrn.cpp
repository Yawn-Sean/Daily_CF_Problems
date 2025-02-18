int k;

void solve() {
    cin >> k;
    
    if (k % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pii> res;
    
    int ver = k * 4 - 2;
    res.emplace_back(1, 2);
    for (int i = 3; i < k + 2; i ++) {
        res.emplace_back(1, i);
        for (int j = k + 2; j < k * 2 + 1; j ++) {
            res.emplace_back(i, j);
        }
    }
    for (int j = k + 2; j < k * 2 + 1; j += 2) {
        res.emplace_back(j, j + 1);
    }
    
    for (int i = k * 2 + 1; i < k * 3; i ++) {
        res.emplace_back(2, i);
        for (int j = k * 3; j < k * 4 - 1; j ++) {
            res.emplace_back(i, j);
        }
    }
    for (int j = k * 3; j < k * 4 - 1; j += 2) {
        res.emplace_back(j, j + 1);
    }
    
    cout << ver << ' ' << sz(res) << endl;
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
}
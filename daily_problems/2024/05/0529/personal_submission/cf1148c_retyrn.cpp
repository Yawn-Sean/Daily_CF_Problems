int n;
void solve() {
    cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<pii> res;
    
    auto gao = [&](int x, int y) {
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        res.emplace_back(x, y);
    };
    
    for (int i = 2; i < n; i ++) {
        if ((pos[i] - 1) * 2 >= n) {
            // 和 1 交换
            gao(pos[i], 1);
            if ((i - 1) * 2 >= n) {
                gao(i, 1);
            }
            else {
                gao(1, n);
                gao(i, n);
            }
        }
        else {
            gao(pos[i], n);
            if ((n - i) * 2 >= n) {
                gao(n, i);
            }
            else {
                gao(1, n);
                gao(1, i);
            }
        }
    }
    
    if (a[1] != 1) gao(1, n);
    
    cout << sz(res) << endl;
    for (auto& p : res) {
        cout << p << endl;
    }
}
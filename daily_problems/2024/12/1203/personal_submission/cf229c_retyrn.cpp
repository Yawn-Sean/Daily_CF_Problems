int n, m;

void solve() {
    cin >> n >> m;
    // 计算减少了多少个三角形
    ll res = 0;
    
    vector<int> d(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        d[x] ++, d[y] ++;
    }
    
    for (int i = 0; i < n; i ++) {
        res += (ll)d[i] * (n - 1 - d[i]);
    }
    
    cout << (ll)n * (n - 1) * (n - 2) / 6 - res / 2 << endl;
    
}
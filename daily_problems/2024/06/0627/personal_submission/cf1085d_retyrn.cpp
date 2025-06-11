int n, s;

void solve() {
    cin >> n >> s;
    // 所有的权值分配到叶子结点上
    // 看最多的叶子结点个数
    vector<int> cnt(n, 0);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        cnt[x] += 1;
        cnt[y] += 1;
    }
    
    int t = 0;
    for (int i = 0; i < n; i ++) {
        t += (cnt[i] == 1);
    }
    cout << 1.0 * s / t * 2 << endl;
}
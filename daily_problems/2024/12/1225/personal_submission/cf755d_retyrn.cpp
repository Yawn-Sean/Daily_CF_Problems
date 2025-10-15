int n, k;

void solve() {
    cin >> n >> k;
    if (k > n / 2) k = n - k;
    
    Fenwick<int> fen(n + 1);
    int cur = 0;
    ll res = 1;
    
    vector<ll> ans;
    
    for (int i = 0; i < n; i ++) {
        // 检查 [cur+1, cur+k)
        if (cur + k <= n) res += fen.rangeSum(cur + 1, cur + k) + 1;
        else {
            // [cur+1, n) [0, cur + k - n)
            res += fen.rangeSum(cur + 1, n) + fen.rangeSum(0, cur + k - n) + 1;
        }
        
        fen.add(cur, 1);
        cur = (cur + k) % n;
        fen.add(cur, 1);
        ans.push_back(res);
    }
    
    cout << ans << endl;
}
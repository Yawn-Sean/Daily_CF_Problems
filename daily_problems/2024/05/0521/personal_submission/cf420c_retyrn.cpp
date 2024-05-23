int n, p;

void solve() {
    cin >> n >> p;
    map<pii, int> mp;
    vector<int> cnt(n, 0);
    
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (x > y) swap(x, y);
        mp[mpr(x, y)] += 1;
        cnt[x] += 1;
        cnt[y] += 1;
    }
    
    ll res = 0;
    for (auto& [pa, val] : mp) {
        auto x = pa.fi, y = pa.se;
        if (cnt[x] + cnt[y] >= p and cnt[x] + cnt[y] - val < p) {
            res -= 1;
        }
    }
    
    sort(all(cnt));
    for (int i = 0, j = n - 1; i < n; i ++) {
        // 枚举第一个
        while (j >= 0 and cnt[i] + cnt[j] >= p) j --;
        int val = min(n - j - 1, n - i - 1);
        res += val;
    }
    cout << res << endl;
}
void solve() {
    int n, x;
    cin >> n;
    vector<int> a(2 * n), ct(2);
    unordered_map<int, int> mp;
    rep (i, 0, 2 * n) {
        cin >> a[i];
        -- a[i];
        if (i < n) {
            ct[a[i]]++;
            mp[ct[0] - ct[1]] = i;
        }
    }
    int ans = mp.count(0) ? 2 * n - mp[0] - 1 : 2 * n;
    ct[0] = ct[1] = 0;
    br (i, 2 * n - 1, n) {
        ct[a[i]] ++;
        if (mp.count(ct[1] - ct[0])) chmin(ans, i - mp[ct[1] - ct[0]] - 1);
        if (ct[1] - ct[0] == 0) chmin(ans, i);
    }
    cout << ans << nl;
}

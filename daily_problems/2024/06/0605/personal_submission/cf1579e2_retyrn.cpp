int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    map<int, int> mp;
    for (auto x : a) {
        mp[x] = 0;
    }
    int idx = 1;
    for (auto& [_, v] : mp) {
        v = idx ++;
    }
    int m = idx;
    
    BIT<int> bit(idx);
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        int x = mp[a[i]];
        res += min(bit.sum(1, x - 1), bit.sum(x + 1, m));
        bit.add(x, 1);
    }
    cout << res << endl;
}
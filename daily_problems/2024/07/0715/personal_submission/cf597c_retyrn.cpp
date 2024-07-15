int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    
    vector<BIT<ll>> bit(k + 2, n);
    vector<vector<ll>> f(n + 1, vector<ll>(k + 2));
    ll res = 0;
    
    for (auto x : a) {
        f[x][1] = 1;
        bit[1].add(x, 1);
        for (int i = 2; i <= k + 1; i ++) {
            f[x][i] = bit[i-1].sum(x - 1);
            bit[i].add(x, f[x][i]);
        }
        res += f[x][k + 1];
    }
    
    cout << res << endl;
}
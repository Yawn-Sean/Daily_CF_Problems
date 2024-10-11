int n, m;

void solve() {
    cin >> n >> m;
    vector<ll> fact(maxn);
    fact[0] = 1;
    for (int i = 1; i <= n; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    vector<int> a(n), b(m);
    cin >> a >> b;
    Fenwick<int> fen(maxn);
    vector<int> freq(maxn);
    for (auto x : a) {
        fen.add(x, 1);
        freq[x] += 1;
    }
    
    Z cur = fact[n];
    for (int i = 1; i <= 200000; i ++) {
        cur /= fact[freq[i]];
    }
    
    Z res = 0;
    for (int i = 0; i < m; i ++) {
        if (i >= n) {
            res += 1;
            break;
        }
        cur = cur / (n - i);
        res += cur * fen.rangeSum(1, b[i]);
        if (freq[b[i]] == 0) break;
        cur *= freq[b[i]];
        freq[b[i]] -= 1;
        fen.add(b[i], -1);
    }
    cout << res << endl;
}
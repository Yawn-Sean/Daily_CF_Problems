int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    int res = 0;
    for (auto x : a) {
        res ^= x;
    }
    
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] ^ i;
    }
    // 计算从0到n mod i 的值
    for (int i = 1; i <= n; i ++) {
        int u = (n + 1) / i;
        if (u & 1) res ^= s[i - 1];
        if (u * i == n + 1) continue;
        int v = n % i;
        res ^= s[v];
    }
    cout << res << endl;
}
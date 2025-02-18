vector<int> PolyMul(const vector<int>& a, const vector<int>& b) {
    int deg = (int)a.size() + (int)b.size() - 2;
    vector<int> c(deg + 1);
    for (int i = 0;i < a.size();i++) {
        for (int j = 0;j < b.size();j++) {
            c[i + j] += a[i] * b[j] % MOD;
            if (c[i + j] >= MOD) c[i + j] -= MOD;
        }
    }
    return c;
}
vector<int> PolyInv(const vector<int>& a) {
    int n = a.size() - 1;
    vector<int> b(n + 1);
    int inv_a0 = inv(a[0]), neg = (MOD - inv_a0) % MOD;
    b[0] = inv_a0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            b[i] = (b[i] + neg * a[j] % MOD * b[i - j] % MOD) % MOD;
        }
    }
    return b;
}
vector<int> PolyLn(const vector<int>& a) {// 不需要保证a[0] = 1
    int n = a.size() - 1;
    vector<int> b(n + 1);
    for (int i = 0;i <= n;i++) {
        b[i] = i * a[i];
        int sum = 0;
        for (int j = 1;j < i;j++) {
            sum = (sum + j * b[j] % MOD * a[i - j] % MOD) % MOD;
        }
        b[i] = (b[i] + MOD - sum) % MOD;
        b[i] = b[i] * inv(a[0] * i % MOD) % MOD;
    }
    return b;
}
vector<int> PolyExp(const vector<int>& a) {// 保证a[0] = 0
    int n = a.size() - 1;
    vector<int> b(n + 1);
    b[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            b[i] = (b[i] + b[i - j] * a[j] % MOD * j % MOD) % MOD;
        }
        b[i] = b[i] * inv(i) % MOD;
    }
    return b;
}
vector<int> PolyPow(vector<int> a, int k) {
    a = PolyLn(a);
    for (int i = 0;i < a.size();i++) a[i] = a[i] * k % MOD;
    a = PolyExp(a);
    return a;
}
void Solve() {
    int n, k;cin >> n >> k;
    vector<int> a(n);for (int i = 0;i < n;i++) cin >> a[i];
    vector<int> b(n);b[0] = 1, b[1] = MOD - 1;b = PolyInv(b);
    auto res = PolyMul(a, PolyPow(b, k));
    for (int i = 0;i < n;i++) cout << res[i] << " ";
}

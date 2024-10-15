int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    auto check = [&](int k) {
        for (int i = 0; i < k; i ++) {
            int cnt = 0;
            for (int j = i; j < n; j += k) {
                cnt += (s[j] - '0');
            }
            if (cnt & 1) return false;
        }
        return true;
    };
    
    vector<int> f(n + 1);
    for (int i = 1; i <= n / i; i ++) {
        if (n % i) continue;
        f[i] = check(i);
        f[n / i] = check(n / i);
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int t = __gcd(i, n);
        res += f[t];
    }
    cout << res << endl;
}
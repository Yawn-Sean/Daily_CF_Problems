int n, q;
string str;

void solve() {
    cin >> n >> q;
    cin >> str;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i-1] + (str[i-1] == '1');
    }
    
    vector<ll> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i-1] * 2;
        if (f[i] >= mod) f[i] -= mod;
    }
    
    while (q --) {
        int l, r;
        cin >> l >> r;
        int one = s[r] - s[l-1], len = r - l + 1;
        int zero = len - one;
        // (2^one - 1) 现在是t 还有zero个t
        ll t = (f[one] + mod - 1) % mod * f[zero] % mod;
        cout << t << endl;
    }
}
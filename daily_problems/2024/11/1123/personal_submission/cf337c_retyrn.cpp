int n, m, k;

ll powmod (ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for(; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    // 每k-1个题就错一次, 避免翻倍
    int u = n / k;
    if (n - m >= u) {
        cout << m << endl;
        return;
    }
    // 优先翻倍
    int wrong = n - m;
    // 前面连续正确的
    int t = n - wrong * k;
    // k * 2 -> k * 6 -> k * 14 -> k * 30
    ll res = (powmod(2, t / k + 1) + mod - 2) % mod * k % mod;
    res += (ll)wrong * (k - 1) + t % k;
    res %= mod;
    cout << res << endl;
}
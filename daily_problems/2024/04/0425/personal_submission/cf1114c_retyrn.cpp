ll n, b;

void solve() {
    cin >> n >> b;
    // 对b进行质因数分解
    map<ll, int> mp;
    auto x = b;
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                mp[i] += 1;
            }
        }
    }
    if (x > 1) mp[x] = 1;
    
    // 对于某个质因子p
    // p中有1个 2p有1个 3p有一个 .. p*p有两个 p*p*p有三个
    // 每段p-1个数
    ll res = inf2;
    for (auto [p, need] : mp) {
        ll sum = 0;
        ll x = n;
        while (x > 0) {
            x /= p;
            sum += x;
        }
        res = min(res, sum / need);
    }
    cout << res << endl;
}
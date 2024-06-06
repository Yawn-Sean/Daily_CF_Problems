int n, mod;

void solve() {
    cin >> n >> mod;
    vector<int> f(n + 1, 0);
    f[1] = 1;
    
    vector<int> primes(n + 1, 0);
    iota(all(primes), 0);
    
    for (int i = 2; i <= n; i ++) {
        if (primes[i] == i) {
            for (int j = i + i; j <= n; j += i) {
                primes[j] = i;
            }
        }
    }
    vector<int> fact;
    
    function<void(int)> get_factors = [&](int x) {
        fact.clear();
        fact.push_back(1);
        while (x > 1) {
            int cnt = 0, p = primes[x];
            while (x % p == 0) {
                x /= p;
                cnt += 1;
            }
            int m = sz(fact);
            for (int i = 0; i < m; i ++) {
                int val = fact[i];
                for (int j = 0; j < cnt; j ++) {
                    val *= p;
                    fact.push_back(val);
                }
            }
        }
    };
    
    int pre = 1, cur = 0;
    for (int i = 2; i <= n; i ++) {
        get_factors(i);
        for (auto fa : fact) {
            if (fa > 1) {
                cur = (cur + mod - f[(i - 1) / fa]) % mod;
                cur = (cur + f[i / fa]) % mod;
            }
        }
        f[i] = (f[i] + cur) % mod;
        f[i] = (f[i] + pre) % mod;
        pre = (pre + f[i]) % mod;
    }
    
    cout << f[n] << endl;
}
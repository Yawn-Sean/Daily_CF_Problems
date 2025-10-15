int T;
LL n;

void solve1() {
    LL res1 = 0, res2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            res1 += res2 + 1;
        } else {
            res2 += res1 + 1;
        }
        res1 %= MOD1;
        res2 %= MOD1;
    }
    cout << (res1 + res2) % MOD1 << "\n";
}                                                                                                  

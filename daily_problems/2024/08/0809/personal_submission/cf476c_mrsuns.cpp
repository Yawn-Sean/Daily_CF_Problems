const int MOD = 1e9 + 7;
const int inv2 = MOD + 1 >> 1;
void Solve() {
    int a, b;cin >> a >> b;
    int res = (b - 1) * b % MOD * inv2 % MOD * a % MOD;
    res = (res + (b - 1) * b % MOD * inv2 % MOD * b % MOD * (1 + a) % MOD * a % MOD * inv2 % MOD) % MOD;
    cout << res << endl;
}

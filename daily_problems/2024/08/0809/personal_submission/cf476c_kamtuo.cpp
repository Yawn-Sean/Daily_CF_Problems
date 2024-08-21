const int MOD = 1e9 + 7;

int main() {
    int a, b;
    cin >> a >> b;
    int tot = (1ll * b * (b - 1ll) / 2ll) % MOD; 
    int ans = 0;
    for (int i = 1; i <= a; i ++) {
        ans += ((1ll * b * 1ll * (b - 1ll) / 2ll) % MOD * b % MOD * 1ll * i % MOD + tot) % MOD;
        ans %= MOD;
    } 
    cout << ans << endl;
    return 0;
}

void solve() {
    ll a, b, mod;
    scanf("%I64d %I64d %I64d", &a, &b, &mod);
    for (ll i = 1; i <= min(a, mod); i++) {
        ll val = (i * ll(1e9)) % mod;
        ll c = (mod - val) % mod;
        if (c > b) {
            printf("1 %09d\n", i);
            return;
        }
    }
    printf("2\n");
}

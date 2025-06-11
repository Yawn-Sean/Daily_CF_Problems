const int N = 1e5 + 7;
int num[N];
ll mp[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mp[num[i]]++;
    }
    ll ans = 0;
    if (k == 0) {
        for (int x = 0; x <= 10000; x++) {
            if (mp[x]) {
                ans += mp[x] * (mp[x] - 1LL);
            }
        }
        ans /= 2LL;
        cout << ans << "\n";
        return;
    }
    for (int x = 0; x <= 10000; x++) {
        if (!mp[x]) continue;
        for (int y = 0; y <= 10000; y++) {
            if (!mp[y]) continue;
            int z = x ^ y;
            if (__builtin_popcount(z) == k) {
                ans += mp[x] * mp[y];
            }
        }
    }
    ans /= 2LL;
    cout << ans << "\n";
}

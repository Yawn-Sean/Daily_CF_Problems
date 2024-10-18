int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n + 1);
    vector<vector<int>> pref(n + 1, vector<int>(32));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int b = 0; b <= 30; b++) {
            pref[i][b] = a[i] >> b & 1;
            pref[i][b] += pref[i - 1][b];
        }
    }


    ll num = 1;
    for (int i = 0; i < k; i++) num *= x;

    auto get = [&](int pos) {
        ll pre = 0, suf = 0;
        for (int b = 0; b <= 30; b++) {
            if (pref[pos - 1][b]) pre += 1 << b;
            if (pref[n][b] - pref[pos][b]) suf += 1 << b;
        }

        return suf | pre;
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        setmax(ans, get(i) | a[i] * num);
    }

    cout << ans << '\n';

    return 0;
}

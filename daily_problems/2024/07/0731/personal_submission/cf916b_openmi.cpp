void solve() {
    ll n, k;
    cin >> n >> k;
    int popcnt = __builtin_popcountll(n);
    k -= popcnt;
    if (k < 0) return p(0), void();

    map<int, ll> cnt;
    for (int i = hbll(n); i >= 0; --i) if (n >> i & 1) cnt[i]++;

    // 高bit降
    int j = hbll(n);
    while (k >= cnt[j]) {
        cnt[j-1] += cnt[j] * 2;
        k -= cnt[j];
        cnt.erase(j);
        --j;
    }

    // 末尾bit降
    j = min(j, __builtin_ffsll(n) - 1);
    while (k) {
        cnt[j-1] += 2;
        k -= 1;
        cnt[j] -= 1;
        if (cnt[j] == 0) cnt.erase(j);
        --j;
    }
    if (k) return p(0), void();

    p(1);
    for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        rep (i, 0, it->second) cout << it->first << ' ';
    }
}

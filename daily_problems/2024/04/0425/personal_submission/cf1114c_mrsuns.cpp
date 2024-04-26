void Solve() {
    int n, b;cin >> n >> b;
    vector<int> fac;
    map<int, int> mp;
    for (int i = 2;i * i <= b;i++) {
        if (b % i == 0) {
            fac.push_back(i);
        }
        while (b % i == 0) b /= i, mp[i] += 1;
    }
    if (b != 1) {
        fac.push_back(b);
        mp[b] += 1;
    }
    int mn = LONG_LONG_MAX;
    for (auto i : fac) {
        int res = 0;
        for (__int128 j = i;j <= n;j *= i) {
            res += n / j;
        }
        mn = min(mn, res / mp[i]);
    }
    cout << mn << endl;
}

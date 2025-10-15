int n, k;

void solve() {
    cin >> k;
    string str;
    cin >> str;
    n = sz(str);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + (str[i - 1] - '0');
    }
    // (x1, y1) -> (x2, y2)
    // (s[y2] - s[y1-1]) * (s[x2] - s[x1-1])
    map<ll, int> mp;
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            mp[s[j] - s[i]] += 1;
        }
    }

    ll res = 0;
    for (int i = 1; i <= k / i; i ++) {
        if (k % i) continue;
        if (mp.count(i) and mp.count(k / i)) {
            if (i == k / i) res += (ll)mp[i] * mp[i];
            else res += (ll)mp[i] * mp[k / i] * 2;
        }
    }
    if (k == 0) {
        int sum = (n + 1) * n / 2;
        res = (ll)sum * mp[0] * 2 - (ll)mp[0] * mp[0];
    }
    cout << res << endl;
}
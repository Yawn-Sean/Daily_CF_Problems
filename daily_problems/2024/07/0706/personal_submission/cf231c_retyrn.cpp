int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<ll> s(n + 1);
    sort(all(a));
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    int mx = 0, res = 0;
    
    for (int i = 0, j = 0; i < n; i ++) {
        while (s[i + 1] - s[j] + m < (ll)a[i] * (i - j + 1)) {
            j ++;
        }
        if ((i - j + 1) > mx) {
            mx = i - j + 1;
            res = a[i];
        }
    }
    cout << mx << ' ' << res << endl;
}
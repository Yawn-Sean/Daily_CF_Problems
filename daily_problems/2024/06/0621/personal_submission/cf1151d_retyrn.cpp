int n;

void solve() {
    cin >> n;
    vector<int> v(n);
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        res += (ll)b * n - a;
        v[i] = a - b;
    }
    sort(all(v));
    for (int i = 0; i < n; i ++) {
        res += (ll)(n - i) * v[i];
    }
    cout << res << endl;
}
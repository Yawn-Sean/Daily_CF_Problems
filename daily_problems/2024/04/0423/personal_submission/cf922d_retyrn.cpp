int n;

void solve() {
    cin >> n;
    vector<string> a(n);
    cin >> a;
    vector<int> s(n), h(n);
    for (int i = 0; i < n; i ++) {
        for (auto& c : a[i]) {
            if (c == 's') s[i] += 1;
            else h[i] += 1;
        }
    }
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return (ll)s[x] * h[y] > (ll)h[x] * s[y];
    });
    
    ll res = 0;
    int sum = 0;
    for (auto& idx : id) {
        for (auto c : a[idx]) {
            if (c == 's') sum ++;
            else res += sum;
        }
    }
    cout << res << endl;
}
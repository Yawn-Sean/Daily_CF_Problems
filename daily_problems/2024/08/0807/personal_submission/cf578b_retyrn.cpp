int n, k, x;

void solve() {
    cin >> n >> k >> x;
    ll t = 1;
    while (k --) {
        t *= x;
    }
    vector<ll> a(n);
    cin >> a;
    vector<ll> l(n + 1), r(n + 1);
    ll res = 0;
    for (int i = 1; i <= n; i ++) {
        l[i] = l[i-1] | a[i-1];
        r[i] = r[i-1] | a[n-i];
    }
    for (int i = 0; i < n; i ++) {
        ll cur = a[i] * t;
        chmax(res, cur | l[i] | r[n - 1 - i]);
    }
    cout << res << endl;
}
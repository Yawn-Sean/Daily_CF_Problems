int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n + 1);
    cin >> a;
    
    vector<ll> v(n + 1);
    for (int i = 0; i < n; i ++) {
        ll carry = (a[i] + v[i]) / 2;
        v[i] = (a[i] + v[i]) % 2;
        v[i + 1] += carry;
    }
    v[n] += a[n];
    
    int idx = 0;
    while (v[idx] == 0) idx ++;
    
    ll cur = 0;
    int res = 0;
    
    for (int i = n; i >= 0; i --) {
        cur = cur * 2 + v[i];
        if (abs(cur) > k * 2) break;
        if (i <= idx and abs(a[i] - cur) <= k and !(i == n and a[n] == cur)) res += 1;
    }
    cout << res << endl;
}
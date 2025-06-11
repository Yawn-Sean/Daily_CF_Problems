using i128 = __int128;
int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> s(n + 1);
    cin >> a;
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    
    auto get = [&](int l, int r) {
        return s[r + 1] - s[l];
    };
    
    ll mx = s[n] * k;
    
    // 记录大于1的位置
    vector<int> v;
    int start = 0;
    
    i128 cur = 1;
    ll res = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        cur *= a[i];
        if (a[i] > 1) v.emplace_back(i);
        
        while (j < i and cur > mx) {
            cur /= a[j];
            if (a[j] > 1) {
                start += 1;
            }
            j ++;
        }
        
        if (em(v)) {
            if (k == 1) res += 1;
            continue;
        }
        
        if (k == 1 and a[i] == 1) res += 1;
        ll t = 1;
        for (int l = sz(v) - 1; l >= start; l --) {
            t *= a[v[l]];
            if (t % k) continue;
            int low = (l == start ? j : v[l - 1] + 1);
            int up = v[l];
            if (low > up) continue;
            if (get(low, i) >= t / k and get(up, i) <= t / k) res += 1;
        }
    }
    cout << res << endl;
}
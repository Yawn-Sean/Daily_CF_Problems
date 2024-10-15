int n, k;
int cnt[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }
    
    ll res = 0;
    if (k == 0) {
        for (int i = 0; i <= 10000; i ++) {
            res += (ll)cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << res << endl;
        return;
    }
    
    for (int i = 0; i <= 10000; i ++) {
        for (int j = i + 1; j <= 10000; j ++) {
            if (__builtin_popcount(i ^ j) == k) res += (ll)cnt[i] * cnt[j];
        }
    }
    cout << res << endl;
}
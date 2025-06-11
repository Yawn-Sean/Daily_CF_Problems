int n;
int cnt[maxn], s[maxn];

void solve() {
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] += 1;
        chmax(mx, x);
    }
    for (int i = mx; i >= 0; i --) {
        s[i] = s[i + 1] + cnt[i];
    }
    ll res = 0;
    for (int i = 1; i <= mx; i ++) {
        if (!cnt[i]) continue;
        int j = mx / i * i;
        int pre = 0;
        ll cur = 0;
        while (j >= i) {
            cur += (ll)(s[j] - pre) * j;
            pre = s[j];
            j -= i;
        }
        chmax(res, cur);
    }
    cout << res << endl;
}
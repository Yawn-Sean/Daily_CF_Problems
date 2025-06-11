int T;
LL n, k, a[N], s[N];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    LL res = 0, val = INF;
    for (int i = 1; i <= n; i++) {
        LL l = 1, r = i, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            LL target = (i - mid + 1) * a[i];
            LL cost = target - (s[i] - s[mid - 1]);
            if (cost <= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        LL target = (i - l + 1) * a[i];
        LL cost = target - (s[i] - s[l - 1]);
        if (cost <= k) {
            if (res < i - l + 1) {
                res = max(res, i - l + 1);
                val = a[i];
            } else if (res == i - l + 1) {
                val = min(val, a[i]);
            }
        } else {
            if (res < i - r + 1) {
                res = max(res, i - r + 1);
                val = a[i];
            } else if (res == i - r + 1) {
                val = min(val, a[i]);
            }
        }
    }
    cout << res << " " << val << "\n";
}      
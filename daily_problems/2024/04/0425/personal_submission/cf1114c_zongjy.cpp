void solve() {
    i64 n, b;
    cin >> n >> b;
    map<i64, int> pri;
    for (i64 i = 2; i * i <= b; i++) {
        if (b % i == 0) {
            while (b % i == 0) {
                b /= i;
                ++pri[i];
            }
        }
    }
    if (b != 1) pri[b] = 1;

    i64 tmp, ans = 1E18, cnt = 0;
    for (auto [k, v] : pri) {
        tmp = n;
        cnt = 0;
        while (tmp) {
            cnt += tmp / k;
            tmp /= k;
        }
        ans = min(ans, cnt / v);
    }

    cout << ans << '\n';
}
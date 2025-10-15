LL n, a[N], sum[N];
string s;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> s;
    s = " " + s;
    sum[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    LL res = 0, pre = 0;
    for (int i = n; i > 0; i--) {
        if (s[i] == '0') {
            res = max(res, pre);
        } else {
            res = max(res, pre + sum[i - 1]);
            pre += a[i];
        }
    }
    res = max(res, pre);
    cout << res << "\n";
}

LL n, a[3][N], s1[N], s2[N], dp1[N], dp2[N];

void meibao() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[2][i];
    }
    
    for (int i = 0; i < n; i++) {
        s1[i + 1] = s1[i] + a[1][i];
        s2[i + 1] = s2[i] + a[2][i];
    }

    for (int i = n - 1; i >= 0; i--) {
        dp1[i] = dp1[i + 1] - (s1[n] - s1[i + 1]) - (s2[n] - s2[i + 1]) + 2 * i * a[1][i] + (2 * n - 1) * a[2][i];
        dp2[i] = dp2[i + 1] - (s1[n] - s1[i + 1]) - (s2[n] - s2[i + 1]) + 2 * i * a[2][i] + (2 * n - 1) * a[1][i];
    }
    LL res = dp1[0];
    LL cur = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            cur += 2 * i * a[2][i] + (2 * i + 1) * a[1][i];
            res = max(res, cur + dp1[i + 1]);
        }
        else {
            cur += 2 * i * a[1][i] + (2 * i + 1) * a[2][i];
            res = max(res, cur + dp2[i + 1]);
        }
    }
    cout << res << "\n";
}

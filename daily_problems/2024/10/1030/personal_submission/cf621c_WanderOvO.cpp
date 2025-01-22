LL n, p, l[N], r[N];

void meibao() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    double res = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + 1;
        if (j == n + 1) {
            j = 1;
        }
        LL cnt1 = r[i] / p - (l[i] - 1) / p;
        LL cnt2 = r[j] / p - (l[j] - 1) / p;
        // cout << cnt1 << " " << cnt2 << "\n";
        LL len1 = r[i] - l[i] + 1, len2 = r[j] - l[j] + 1;
        double prob = (cnt1 * len2 + cnt2 * len1 - cnt1 * cnt2) / (len1 * len2 * 1.0); 
        // cout << setprecision(10) << prob << '\n';
        res += prob * 2000;
    }
    cout << setprecision(18) << res << "\n";
}

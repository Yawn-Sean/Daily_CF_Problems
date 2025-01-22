/*
枚举完全解决了几个任务，减去那些时间，然后对于剩下的任务，按照时间消耗从小到大的顺序解决子任务
*/

LL n, k, m;
LL t[N];

void meibao() {
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
    }
    sort(t + 1, t + k + 1);
    LL tot = 0;
    for (int i = 1; i <= k; i++) {
        tot += t[i];
    }
    LL res = 0;
    for (int i = 0; i <= n && i * tot <= m; i++) {
        LL left = m - i * tot;
        if (left < 0) continue;
        LL ans = i * (k + 1);
        for (int j = 1; j <= k; j++) {
            for (int cnt = 1; cnt <= n - i; cnt++) {
                if (left >= t[j]) {
                    ans++;
                    left -= t[j];
                }
            }
        }
        res = max(res, ans);
        // cout << res << "\n";
    }
    cout << res << "\n";
}

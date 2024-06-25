// https://codeforces.com/contest/721/submission/259939181

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    i64 n, k, x;
    cin >> n >> k >> x;
    vector<i64> a(n);
    int neg = 0, pos = 0;
    i64 min_abs = 1e9;
    for (i64 &v: a) {
        cin >> v;
        neg += v < 0, pos += v > 0;
        if (v) min_abs = min(min_abs, abs(v));
    }
    if (n - neg - pos <= k) {
        k -= n - neg - pos;
        for (i64 &v: a) {
            if (v == 0) {
                if (neg % 2) v = x;
                else neg++, v = -x;
                min_abs = min(min_abs, abs(v));
            }
        }
        if (neg % 2 == 0 && min_abs < k * x) {
            for (i64 &v: a) {
                if (abs(v) == min_abs) {
                    int t = min_abs / x + 1;
                    v += v > 0 ? -t * x : t * x;
                    k -= t;
                    min_abs = min(min_abs, abs(v));
                    neg++;
                    break;
                }
            }
        }
        priority_queue<pii> Q;
        for (int i = 0; i < n; ++i) Q.emplace(-abs(a[i]), i);
        int sign = neg % 2 == 0 ? -1 : 1;
        while (k--) {
            auto [_, i] = Q.top();
            Q.pop();
            a[i] += (a[i] > 0 ? x : -x) * sign;
            Q.emplace(-abs(a[i]), i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

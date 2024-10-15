/*
假设当前 leading video 的数字是 val
如果 val 比较小，则如果能预处理出更大的那些数是 val 的多少倍并求和就好了
如果 val 比较大，则可以枚举 val 的倍数去计算这个事情，不会枚举太多次，且可以预处理数列中有多少 < k * val 的数
val 不会超过 2e5，取 sqrt(2e5) 为分界线根号分治
*/

LL n, a[N], less_cnt[N], times_cnt[M];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // times_cnt[i]: sum(a[j] / i) 的和，即 i 的倍数和
    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= n; j++) {
            times_cnt[i] += a[j] / i;
        }
    }
    for (int i = 1; i <= n; i++) {
        less_cnt[a[i] + 1]++;
    }
    for (int i = 1; i < N; i++) {
        less_cnt[i] += less_cnt[i - 1];
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        LL val = a[i];
        if (val < M) {
            res = max(res, val * times_cnt[val]);
        } else {
            LL tot = 0;
            for (int j = 1; val * j < N; j++) {
                LL new_val = val * j;
                LL cnt = n - less_cnt[new_val];
                tot += cnt;
            }
            res = max(res, tot * val);
        }
    }
    cout << res << "\n";
}        

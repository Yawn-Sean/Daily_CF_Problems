/*
(x, y, z, t) 表示的矩形的和是多少？
(sum[y] - sum[x - 1]) * (sum[t] - sum[z - 1])

*/

LL a, sum[M];
string s;

void meibao() {
    cin >> a >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + s[i] - '0';
    }
    map<LL, LL> cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cnt[sum[j] - sum[i - 1]]++;
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            LL row_sum = sum[j] - sum[i - 1];
            if (a == 0) {
                if (row_sum == 0) {
                    res += n * (n + 1) / 2;
                } else {
                    res += cnt[0];
                }
                continue;
            }
            if (row_sum == 0) continue;
            if (a % row_sum == 0) {
                if (cnt.count(a / row_sum)) {
                    res += cnt[a / row_sum];
                }
            }
        }
    }
    cout << res << "\n";
}

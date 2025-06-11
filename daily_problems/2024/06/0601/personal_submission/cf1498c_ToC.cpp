// https://codeforces.com/contest/1498/submission/263732135
int n, m, k;
LL cnt[MAXN];
void sol()
{
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << '\n';
        return ;
    }
    if (n == 1) {
        cout << 2 << '\n';
        return ;
    }
    LL res = 2;
    int dir = 1; // 右：1， 左：0
    for (int i = 1; i < n; i++) cnt[i] = 1;
    for (int i = 1; i < k; i++) {
        LL pre = 0;
        if (dir) {
            // 从右往左
            for (int i = n - 2; i >= 1; i--)
                (cnt[i] += cnt[i + 1]) %= mod1;
            (res += cnt[1]) %= mod1;
        } else {
            // 从左往右
            for (int i = 2; i < n; i++)
                (cnt[i] += cnt[i - 1]) %= mod1;
            (res += cnt[n - 1]) %= mod1;
        }
        dir ^= 1;
    }
    cout << res << '\n';
}

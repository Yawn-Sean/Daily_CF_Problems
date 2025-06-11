// https://codeforces.com/contest/1954/submission/263113003
int n, m;
int a[MAXN];
LL f[MAXN];    // f[j] 是 [1, i - 1]中总数为j的颜色子集的数量
void sol()
{
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tot += a[i];

    sort(a + 1, a + n + 1);
    int res = 0;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        for (int j = 0; j <= cur; j++)
            res = (res + f[j] * cur % mod2) % mod2;
        for (int j = cur + 1; j <= tot; j++)
            res = (res + (j + cur + 1) / 2 * f[j] % mod2) % mod2;
        for (int j = tot; j >= cur; j--)
            f[j] = (f[j] + f[j - cur]) % mod2;
    }
    cout << res << '\n';

}
